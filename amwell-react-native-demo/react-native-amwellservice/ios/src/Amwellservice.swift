//
//  Amwellservice.swift
//  Amwellservice
//
//  Created by Yunfeng Lin on 12/7/19.
//  Copyright © 2019 Facebook. All rights reserved.
//

import Foundation
import AWSDK
import React

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
    
    @objc func initialize (_ resolve: @escaping RCTPromiseResolveBlock, reject: @escaping RCTPromiseRejectBlock) {
        AWSDKService.initialize(withLaunchParams: [kAWSDKBundleID: "com.uhg.amwelldemo",
                                                   kAWSDKUrl: "https://iot58.amwellintegration.com/",
                                                   kAWSDKKey: "bf8a5665"]) { (success, error) in
                                                    if success {
                                                        resolve("AWSDKService initialize successfully!");
                                                    } else {
                                                        reject("init_fail", "looks like init failed!", error);
                                                    }
                                                    
        }
    }
}
