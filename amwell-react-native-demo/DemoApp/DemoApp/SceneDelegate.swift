//
//  SceneDelegate.swift
//  DemoApp
//
//  Created by Yunfeng Lin on 12/19/19.
//  Copyright © 2019 Yunfeng Lin. All rights reserved.
//

import UIKit
import SwiftUI
import AWSDK
import Amwellservice

class FakeDelegate : NSObject, AWSDKVisitDelegate, AWSDKCallbackDelegate {
    func providerDidEnterVisit() {
        
    }
    
    func visitDidComplete(_ visitSuccessful: Bool, with: AWCoreVisitEndReason) {
        
    }
    
    func callbackStatusDidChange(_ status: AWSDKCallbackStatus) {
        
    }
}

class SceneDelegate: UIResponder, UIWindowSceneDelegate {
    
    var window: UIWindow?
    
    var console: AWCoreVisitConsoleController?
    
    func scene(_ scene: UIScene, willConnectTo session: UISceneSession, options connectionOptions: UIScene.ConnectionOptions) {
        // Use this method to optionally configure and attach the UIWindow `window` to the provided UIWindowScene `scene`.
        // If using a storyboard, the `window` property will automatically be initialized and attached to the scene.
        // This delegate does not imply the connecting scene or session are new (see `application:configurationForConnectingSceneSession` instead).
        
        // Create the SwiftUI view that provides the window contents.
        let contentView = NavigationView {
            Text("This is a great app")
                .navigationBarTitle("Welcome")
        }
        
        // Use a UIHostingController as window root view controller.
        if let windowScene = scene as? UIWindowScene {
            // let window = UIWindow(windowScene: windowScene)
            
            
            // window.rootViewController = UIHostingController(rootView: contentView)
            
            //            let console = AWCoreVisitConsoleController(rootViewController: UIHostingController(rootView: contentView))
            //            console.setTintColor(UIColor.blue)
            
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
                                                                                                                                                    visitData.delegate = delegateInstance
                                                                                                                                                    visitData.callbackDelegate = delegateInstance
                                                                                                                                                    
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
                                                                                                                                                                    // print(result)
                                                                                                                                                                
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
    }
    
    func sceneDidDisconnect(_ scene: UIScene) {
        // Called as the scene is being released by the system.
        // This occurs shortly after the scene enters the background, or when its session is discarded.
        // Release any resources associated with this scene that can be re-created the next time the scene connects.
        // The scene may re-connect later, as its session was not neccessarily discarded (see `application:didDiscardSceneSessions` instead).
    }
    
    func sceneDidBecomeActive(_ scene: UIScene) {
        // Called when the scene has moved from an inactive state to an active state.
        // Use this method to restart any tasks that were paused (or not yet started) when the scene was inactive.
    }
    
    func sceneWillResignActive(_ scene: UIScene) {
        // Called when the scene will move from an active state to an inactive state.
        // This may occur due to temporary interruptions (ex. an incoming phone call).
    }
    
    func sceneWillEnterForeground(_ scene: UIScene) {
        // Called as the scene transitions from the background to the foreground.
        // Use this method to undo the changes made on entering the background.
    }
    
    func sceneDidEnterBackground(_ scene: UIScene) {
        // Called as the scene transitions from the foreground to the background.
        // Use this method to save data, release shared resources, and store enough scene-specific state information
        // to restore the scene back to its current state.
    }
    
    
}

