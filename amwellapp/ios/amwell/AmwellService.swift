//
//  AmwellService.swift
//  amwellapp
//
//  Created by Yunfeng Lin on 12/2/19.
//  Copyright © 2019 Facebook. All rights reserved.
//

import Foundation
import UIKit
import AWSDK

@objc(AmwellService)
class AmwellService: NSObject {
  @objc var testProperty: String = "hello"
  
  @objc func requiresMainQueueSetup () -> Bool {
    return false
  }

  @objc(test:rejecter:) func test (_ resolve: @escaping RCTPromiseResolveBlock, rejecter reject: @escaping RCTPromiseRejectBlock) -> Void {
    AWSDKService.initialize(withLaunchParams: [kAWSDKBundleID: "com.uhg.amwelldemo",
                                               kAWSDKUrl: "https://iot58.amwellintegration.com/",
                                               kAWSDKKey: "bf8a5665"]) { (success, error) in
                                                if success {
                                                  resolve("AWSDKService initialize is working!");
                                                } else {
                                                  reject("init_fail", "looks like init failed!", error);
                                                }
                                                
    }
  }
  
  @objc func constToExport () -> [String: Any] {
    return ["name": "AmwellService"]
  }
  
  @objc func initialize (_ resolve: @escaping RCTPromiseResolveBlock, reject: @escaping RCTPromiseRejectBlock) {
    AWSDKService.initialize(withLaunchParams: [kAWSDKBundleID: "com.uhg.amwelldemo",
                                               kAWSDKUrl: "https://iot58.amwellintegration.com/",
                                               kAWSDKKey: "bf8a5665"]) { (success, error) in
                                                if success {
                                                  resolve(nil);
                                                } else {
                                                  reject("init_fail", "looks like init failed!", error);
                                                }
                                                
    }
  }
}
