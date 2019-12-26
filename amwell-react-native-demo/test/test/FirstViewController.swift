//
//  FirstViewController.swift
//  test
//
//  Created by Yunfeng Lin on 12/20/19.
//  Copyright © 2019 Yunfeng Lin. All rights reserved.
//

import UIKit
import SwiftUI
import AWSDK

class FirstViewController: UIViewController,  AWSDKVisitDelegate, UIPopoverPresentationControllerDelegate  {

    var console:AWCoreVisitConsoleController?
    var visit: AWSDKVisit?
    var context: AWSDKVisitContext?
    
    func adaptivePresentationStyleForPresentationController(controller: UIPresentationController) -> UIModalPresentationStyle{
        return UIModalPresentationStyle.none;
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        launchVisit()

        let button = UIButton(frame: CGRect(x: view.frame.width / 2, y: view.frame.height / 2, width: 40, height: 40))
        button.backgroundColor = .red
        button.tintColor = .white
        button.setTitle("Test", for: .normal)
        button.addTarget(self, action: #selector(change), for: .touchUpInside)
        view.addSubview(button)
    }
    
    @objc func change () {
          // let otherView = SecondViewController2()
          
//          let contentView = NavigationView {
//              Text("This is a great app")
//                  .navigationBarTitle("Welcome")
//          }
//          
//          let vc = AWCoreVisitConsoleController(rootViewController: UIHostingController(rootView: contentView))
//  
          
        self.present(self.console!, animated: true, completion: nil)
      }

    
    func launchVisit() {
        
         AWSDKService.initialize(withLaunchParams: [kAWSDKBundleID: "com.uhg.amwelldemo",
                                                               kAWSDKUrl: "https://iot58.amwellintegration.com/",
                                                               kAWSDKKey: "bf8a5665"]) { (success, error) in
                                                                if success {
                                                                    print("AWSDKService initialize successfully!")
                                                                    
                                                                    AWSDKAuthenticationService.authenticateConsumer(withUsername: "yunfeng.lin@rallyhealth.com",
                                                                                                                    password: "cs123!@#",
                                                                                                                    consumerAuthKey: nil) { (result, error) in
                                                                                                                        
                                                                                                                        if (error != nil) {
                                                                                                                            print(error)
                                                                                                                        } else {
                                                                                                                            let consumer = result! as? AWSDKConsumer
                                                                                                                            
                                                                                                                            let option = AWSDKProviderSearchOptions.init()
                                                                                                                            option.name = "Test Four"
                                                                                                                            option.maxResults = 300
                                                                                                                        
                                                                                                                            AWSDKProviderService.performProviderSearch(with: option) {
                                                                                                                                (result, error) in
                                                                                                                                
                                                                                                                                if (error != nil) {
                                                                                                                                    print(error)
                                                                                                                                } else {
                                                                                                                                    print(result!)
                                                                                                                                    
                                                                                                                                    let providers = result as! [AWSDKProviderSearchResult]
                                                                                                                                    var provider = providers[0]
                                                                                                                                    
                                                                                                                                    // search for the Test Four
                                                                                                                                    for item in providers {
                                                                                                                                        let data = item.nameComponents.familyName! + " - " + item.nameComponents.givenName!
                                                                                                                                        print(data)
                                                                                                                                        if (item.nameComponents.familyName! == "Four") {
                                                                                                                                            provider = item
                                                                                                                                            break;
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                    
                                                                                                                                    provider.fetchDetails() {
                                                                                                                                        (data, error) in
                                                                                                                                        
                                                                                                                                        if (error != nil) {
                                                                                                                                            print(error)
                                                                                                                                        } else {
                                                                                                                                            print(data)
                                                                                                                                            
                                                                                                                                            AWSDKVisitContext.createVisitContext(for: consumer!, provider: data!) {
                                                                                                                                                (result, error) in
                                                                                                                                                
                                                                                                                                                if (error != nil) {
                                                                                                                                                    print(error)
                                                                                                                                                } else {
                                                                                                                                                    self.context = result as! AWSDKVisitContext
                                                                                                                                                    self.context!.legalText[0].setAccepted()
                                                                                                                                                    self.context!.selectedModality = AWSDKService.availableModalities![0]

                                                                                                                                                    AWSDKVisitService.createVisit(with: self.context!) {
                                                                                                                                                        (result, error) in
                                                                                                                                                        
                                                                                                                                                        if (error != nil) {
                                                                                                                                                            print(error)
                                                                                                                                                        } else {
                                                                                                                                                            var visit = result as! AWSDKVisit
                                                                                                                                                            self.visit = visit
                                                                                                                                                            self.visit!.delegate = self
                                                                                                                                                            // visitData.callbackDelegate = self
                                                                                                                                                            
                                                                                                                                                            AWSDKVisitService.start(self.visit!) {
                                                                                                                                                                (result, error) in
                                                                                                                                                                
                                                                                                                                                                if (error != nil) {
                                                                                                                                                                    print(error!)
                                                                                                                                                                } else {
                                                                                                                                                                    print(result)
                                                                                                                                                                }
                                                                                                                                                               
                                                                                                                                                            }
                                                                                                                                                        }
                                                                                                                                                    }
                                                                                                                                                     
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                    
                                                                                                                                }
                                                                                                                            }
                                                                                                                             
                                                                                                                        }
                                                                                                                        
                                                                    }
                                                                }
        }
    }
   
    func createVisitConsole() {
        AWSDKVisitService.createVisitConsole(for: self.visit!) {
            (result, error) in
            
            if (error != nil) {
                print(error!)
            } else {
                print(result)
                
                self.console = result
                self.present(self.console!, animated: true, completion: nil)
            }
        }
    }
    
   func providerDidEnterVisit() {
      print("providerDidEnterVisit")
        createVisitConsole()
   }
   
   func visitDidComplete(_ visitSuccessful: Bool, with: AWCoreVisitEndReason) {
       print("visitDidComplete")
   }
   
   func callbackStatusDidChange(_ status: AWSDKCallbackStatus) {
       print("callbackStatusDidChange")
   }
}

