//
//  FirstViewController.swift
//  test
//
//  Created by Yunfeng Lin on 12/20/19.
//  Copyright © 2019 Yunfeng Lin. All rights reserved.
//

import UIKit
import AWSDK

class FakeDelegate : NSObject, AWSDKVisitDelegate, AWSDKCallbackDelegate {
    func providerDidEnterVisit() {
        
    }
    
    func visitDidComplete(_ visitSuccessful: Bool, with: AWCoreVisitEndReason) {
        
    }
    
    func callbackStatusDidChange(_ status: AWSDKCallbackStatus) {
        
    }
}

class FirstViewController: UIViewController,  AWSDKVisitDelegate, AWSDKCallbackDelegate  {

    var console:AWCoreVisitConsoleController?
    
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
          
          /*
          let contentView = NavigationView {
              Text("This is a great app")
                  .navigationBarTitle("Welcome")
          }
          
          let vc = AWCoreVisitConsoleController(rootViewController: UIHostingController(rootView: contentView))
          */
          
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
                                                                                                                            // option.consumer = consumer
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
                                                                                                                                            print(data!.nameComponents.familyName)
                                                                                                                                            print(data!.nameComponents.givenName)
                                                                                                                                            
                                                                                                                                            AWSDKVisitContext.createVisitContext(for: consumer!, provider: data!) {
                                                                                                                                                (result, error) in
                                                                                                                                                
                                                                                                                                                if (error != nil) {
                                                                                                                                                    print(error)
                                                                                                                                                    // reject("createVisitContextForConsumer_fail", "looks like createVisitContextForConsumer failed!", error)
                                                                                                                                                } else {
                                                                                                                                                    
                                                                                                                                                    // simulate the legal accepted
                                                                                                                                                    result!.legalText[0].setAccepted()
                                                                                                                                                    
                                                                                                                                                    let visitContext = result as! AWSDKVisitContext
                                                                                                                                                    visitContext.selectedModality = AWSDKService.availableModalities![0]

                                                                                                                                                    AWSDKVisitService.createVisit(with: visitContext) {
                                                                                                                                                        (result, error) in
                                                                                                                                                        
                                                                                                                                                        if (error != nil) {
                                                                                                                                                            print(error)
                                                                                                                                                        } else {
                                                                                                                                                            let visitData = result as! AWSDKVisit
                                                                                                                                                            
                                                                                                                                                            let delegateInstance = FakeDelegate()
                                                                                                                                                            visitData.delegate = self
                                                                                                                                                            visitData.callbackDelegate = self
                                                                                                                                                            
                                                                                                                                                            AWSDKVisitService.createVisitConsole(for: visitData) {
                                                                                                                                                                (result, error) in
                                                                                                                                                                
                                                                                                                                                                if (error != nil) {
                                                                                                                                                                    print(error)
                                                                                                                                                                } else {
                                                                                                                                                                    self.console = result as? AWCoreVisitConsoleController
                                                                                                                                                                           
                                                                                                                                                                    // start visit call from here
                                                                                                                                                                    // print(visitData.provider.nameComponents.familyName)
                                                                                                                                                                    
                                                                                                                                                                    AWSDKVisitService.start(visitData) {
                                                                                                                                                                        (result, error) in
                                                                                                                                                                        
                                                                                                                                                                        if (error != nil) {
                                                                                                                                                                            print(error!)
                                                                                                                                                                        } else {
                                                                                                                                                                            print(result)
                                                                                                                                                                        
        //
        //                                                                                                                                                                    self.window = UIWindow(windowScene: windowScene)
        //
        //                                                                                                                                                                    if let window = self.window {
        //
        //                                                                                                                                                                        window.rootViewController = MyViewController(console: self.console!)
        //
        //                                                                                                                                                                        window.makeKeyAndVisible()
                                                                                                                                                                            // }
                                                                                                                                                                            
                                                                                                                                                                            //let appDelegate = UIApplication.sharedApplication().delegate as! AppDelegate
                                                                                                                                                                            //appDelegate.
                                                                                                                                                                            
                                                                                                                                                                         //   window.rootViewController = viewController
                                                                                                                                                                         
                                                                                                                                                                              // self.window = window
                                                                                                                                                                                
                                                                                                                                                                            // viewController.present(console!, animated: true)
                                                                                                                                                                              // window.rootViewController!.present(console!, animated: true)
                                                                                                                                                                                
                                                                                                                                                                              // window.makeKeyAndVisible()
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
        }
    }
    
   func providerDidEnterVisit() {
           
   }
   
   func visitDidComplete(_ visitSuccessful: Bool, with: AWCoreVisitEndReason) {
       
   }
   
   func callbackStatusDidChange(_ status: AWSDKCallbackStatus) {
       
   }
}

