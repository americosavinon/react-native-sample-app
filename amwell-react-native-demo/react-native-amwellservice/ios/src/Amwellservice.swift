//
//  Amwellservice.swift
//  Amwellservice
//
//  Created by Yunfeng Lin on 12/7/19.
//  Copyright © 2019 Facebook. All rights reserved.
//

import Foundation
import AWSDK

@objc(Amwellservice)
class Amwellservice: NSObject {
    // MARK: RCTBridgeModule
    @objc static func requiresMainQueueSetup() -> Bool {
        return false
    }
    @objc var bridge: RCTBridge?
    @objc var methodQueue: DispatchQueue?
    @objc func batchDidComplete() {
        // do something if needed at the end of the batch
    }
    @objc func partialBatchDidFlush() {
        // do something if needed at the end of the partial flush of the batch
    }
    // MARK: Bridged methods
    @objc func triggerRequest() -> Void {
        print("trigger Request")
    }
    
    @objc func constantsToExport() -> [String: Any]! {
        return ["name": "Amwellservice"]
    }
    
    // ========== Demo Functions ==========
    private var count = 0
    @objc func increment() {
        count += 1
        print("count is \(count)")
    }
    
    @objc(count:resolver:rejecter:)
    func setCount(_ value: Int,
                  resolver resolve: RCTPromiseResolveBlock,
                  rejecter reject: RCTPromiseRejectBlock) -> Void {
        if (value < 0) {
            let error = NSError(domain: "", code: 0, userInfo: [NSLocalizedDescriptionKey : "Invalid count value."])
            reject("init_fail", "Count input value can't be less than 0!", error)
        } else {
            self.count = value
            resolve(self.count)
        }
    }
    
    @objc func getCount(_ callback: RCTResponseSenderBlock) {
        callback([count,               // variable
            123.9,               // int or float
            "third argument",    // string
            [1, 2.2, "3"],       // array
            ["a": 1, "b": 2]     // object
        ])
    }
    // ========== Demo End ==========
    
    // AWSDK Serivce Initialize Example
    @objc(resolve:rejecter:)
    func initialize (_ resolve: @escaping RCTPromiseResolveBlock,
                     reject: @escaping RCTPromiseRejectBlock) -> Void {
        AWSDKService.initialize(withLaunchParams: [kAWSDKBundleID: "com.uhg.amwelldemo",
                                                   kAWSDKUrl: "https://iot58.amwellintegration.com/",
                                                   kAWSDKKey: "bf8a5665"]) { (success, error) in
                                                    if success {
                                                        resolve("AWSDKService initialize successfully!")
                                                    } else {
                                                        reject("init_fail", "looks like init failed!", error)
                                                    }
                                                    
        }
    }
    
    // AWSDKAuthenticationService with username and password
    @objc(userName:password:resolver:rejecter:)
    func authenticateConsumer(_ userName: String,
                              password: String,
                              resolver resolve: @escaping RCTPromiseResolveBlock,
                              rejecter reject: @escaping RCTPromiseRejectBlock) -> Void {
        
        // the initialize function need to be called first
        AWSDKAuthenticationService.authenticateConsumer(withUsername: userName,
                                                        password: password,
                                                        consumerAuthKey: nil) { (result, error) in
                                                            
                                                            if (error != nil) {
                                                                reject("auth_fail", "looks like init failed!", error)
                                                            } else {
                                                                let consumer = result! as? AWSDKConsumer
                                                                resolve(consumer!)
                                                            }
                                                            
        }
    }
    
    @objc(consumer:resolver:rejecter:)
    func fetchPractices(_ consumer: AWSDKConsumer,
                        resolver resolve: @escaping RCTPromiseResolveBlock,
                        rejecter reject: @escaping RCTPromiseRejectBlock) -> Void {
        
        AWSDKPracticeService.fetchPractices(for: consumer) {
            (result, error) in
            
            if (error != nil) {
                reject("fetchPractices_fail", "looks like init failed!", error)
            } else {
                resolve(result!)
            }
        }
    }
    
    @objc(consumer:practice:resolver:rejecter:)
    func getConsumerSpecialties(_ consumer: AWSDKConsumer,
                                practice: AWSDKPractice,
                                resolver resolve: @escaping RCTPromiseResolveBlock,
                                rejecter reject: @escaping RCTPromiseRejectBlock) -> Void {
        
        practice.fetchSpecialties(for: consumer) {
            (result, error) in
            
            if (error != nil) {
                reject("getConsumerSpecialties_fail", "looks like get specialties failed!", error)
            } else {
                resolve(result!)
            }
        }
    }
    
    @objc(consumer:specialty:resolver:rejecter:)
    func createVisitContextForConsumer(_ consumer: AWSDKConsumer,
                                specialty: AWSDKOnDemandSpecialty,
                                resolver resolve: @escaping RCTPromiseResolveBlock,
                                rejecter reject: @escaping RCTPromiseRejectBlock) -> Void {
        
        let option = AWSDKProviderSearchOptions.init()
        option.name = "Test Four"
        option.consumer = consumer
        
        AWSDKProviderService.performProviderSearch(with: option)
        {
            (result, error) in
            
            if (error != nil) {
                print(error)
            } else {
                print(result!)
                
                let providers = result as! [AWSDKProviderSearchResult]
                let searchResult = providers.count
                
                providers[0].fetchDetails() {
                    (data, error) in

                    if (error != nil) {
                        print(error)
                    } else {
                        print(data)
                        
                        if #available(iOS 9.0, *) {
                            let t1 = data!.nameComponents.givenName
                        } else {
                            // Fallback on earlier versions
                        }
                        
                        AWSDKVisitContext.createVisitContext(for: consumer, provider: data!) {
                                    (result, error) in
                                    
                                    if (error != nil) {
                                        reject("createVisitContextForConsumer_fail", "looks like createVisitContextForConsumer failed!", error)
                                    } else {
                                        
                        //                do {
                        //                    result!.legalText[0].setAccepted()
                        //                    // result!.legalText[1].setAccepted()
                        //                    let a = result!.legalText
                        //
                        //                    let valid = try AWSDKVisitService.isVisitContextValid(result!, cartMode: false)
                        //                } catch {
                        //                    print("Unexpected non-vending-machine-related error: \(error)")
                        //                }
                                        
                                        // simulate the legal accepted
                                        result!.legalText[0].setAccepted()
                                        let data2 = result!.provider
                                        if #available(iOS 9.0, *) {
                                            let t2 = data2!.nameComponents.givenName
                                        } else {
                                            // Fallback on earlier versions
                                        }
                                        
                                        resolve(result!)
                                    }
                                }
                    }
                }

                // exp.fulfill()
            }
        }
        
    }
    
    @objc(visitContext:resolver:rejecter:)
    func createVisitWithContext(_ visitContext: AWSDKVisitContext,
                                resolver resolve: @escaping RCTPromiseResolveBlock,
                                rejecter reject: @escaping RCTPromiseRejectBlock) -> Void {
        
        AWSDKVisitService.createVisit(with: visitContext) {
            (result, error) in
            
            if (error != nil) {
                reject("createVisitWithContext_fail", "looks like createVisitWithContext failed!", error)
            } else {
                resolve(result!)
            }
        }
    }
}

