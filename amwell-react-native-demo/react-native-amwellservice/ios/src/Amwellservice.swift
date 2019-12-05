//
//  Counter.swift
//  react-native-counter
//
//  Created by Yunfeng Lin on 12/5/19.
//

import Foundation
import AWSDK

@objc(Amwellservice)
class Counter: NSObject {
    @objc var testProperty: String = "hello"

    @objc func requiresMainQueueSetup () -> Bool {
        return false
    }

    @objc(test:rejecter:) func test (_ resolve: @escaping RCTPromiseResolveBlock, rejecter reject: @escaping RCTPromiseRejectBlock) -> Void {
        resolve(true)
    }

    @objc func constToExport () -> [String: Any] {
        return ["name": "Counter"]
    }

    @objc func authenticateConsumerWithUsername (_ resolve: @escaping RCTPromiseResolveBlock, reject: @escaping RCTPromiseRejectBlock) {
        AWSDKAuthenticationService.authenticateConsumer(withUsername: "rallytestuser1@gmail.com", password: "test1234", consumerAuthKey: nil) { (success, error) in
            if success != nil {
              resolve("authenticateConsumerWithUsername initialize successfully!");
            } else {
              reject("init_fail", "looks like init failed!", error);
            }
        }
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
