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
    
    @objc func setCount(_ value: Int, resolve: @escaping RCTPromiseResolveBlock, reject: @escaping RCTPromiseRejectBlock) {
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
    @objc func initialize (_ resolve: @escaping RCTPromiseResolveBlock, reject: @escaping RCTPromiseRejectBlock) {
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
    
}
