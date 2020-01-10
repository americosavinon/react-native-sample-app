//
//  AWSDKViewController.swift
//  Amwellservice
//
//  Created by YUNFENG LIN on 12/24/19.
//  Copyright © 2019 Facebook. All rights reserved.
//

import Foundation
import SwiftUI
import AWSDK

/**
 *  We need to use this controller to manage and control the video call testing.
 */
class AmwellViewController: UIViewController, AWSDKVisitDelegate {
    var console:AWCoreVisitConsoleController?
    var visit: AWSDKVisit?
    var context: AWSDKVisitContext?
    var myView: AmwellCustomView?
    
    override func loadView() {
       self.myView = AmwellCustomView()
       super.view = self.myView
    }
    
    // AWSDKVisitDelegate
    func providerDidEnterVisit() {
        self.Debug("Now start to launch video!")
        createVisitConsole()
    }
    
    func visitDidComplete(_ visitSuccessful: Bool, with: AWCoreVisitEndReason) {
        self.Debug("Virtual Visit is completed!")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    // This is the main function
    func demoVideoCall() {
        launchVisit()
        self.Debug("Launch visit console!")
    }
    
    func Debug(_ message: String) {
        print(message)
        self.myView!.onUpdate!(["vv-debug": message])
    }
    
    func Error(_ message: String) {
        print(message)
        self.myView!.onUpdate!(["vv-error": message])
    }
    
    func launchVisit() {
        AWSDKService.initialize(withLaunchParams: [kAWSDKBundleID: "com.uhg.amwelldemo",
                                                   kAWSDKUrl: "https://iot58.amwellintegration.com/",
                                                   kAWSDKKey: "bf8a5665"]) { (success, error) in
                                                    if success {
                                                        self.Debug("AWSDKService initialize successfully!")
                                                        
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
                                                                                                                                if (provider.availability == AWSDKMobileAvailability.Offline ) {
                                                                                                                                    self.Error("Provider is offline :(  ... !")
                                                                                                                                }
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
                                                                                                                                        self.Debug("Create VisitContext success!")
                                                                                                                                        
                                                                                                                                        self.context = result as! AWSDKVisitContext
                                                                                                                                        self.context!.legalText[0].setAccepted()
                                                                                                                                        self.context!.selectedModality = AWSDKService.availableModalities![0]
                                                                                                                                        
                                                                                                                                        AWSDKVisitService.createVisit(with: self.context!) {
                                                                                                                                            (result, error) in
                                                                                                                                            
                                                                                                                                            if (error != nil) {
                                                                                                                                                self.Debug(error.debugDescription)
                                                                                                                                            } else {
                                                                                                                                                var visit = result as! AWSDKVisit
                                                                                                                                                self.visit = visit
                                                                                                                                                self.visit!.delegate = self
                                                                                                                                                
                                                                                                                                                AWSDKVisitService.start(self.visit!) {
                                                                                                                                                    (result, error) in
                                                                                                                                                    
                                                                                                                                                    if (error != nil) {
                                                                                                                                                        print(error!)
                                                                                                                                                    } else {
                                                                                                                                                        self.Debug("Wait for provider to connect!")
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
                // self.present(self.console!, animated: true, completion: nil)
                self.view.window!.rootViewController!.present(self.console!, animated: true, completion: nil)
            }
        }
    }
}
