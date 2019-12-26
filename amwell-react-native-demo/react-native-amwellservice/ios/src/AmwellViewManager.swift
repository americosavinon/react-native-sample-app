//
//  AmwellViewController.swift
//  Amwellservice
//
//  Created by YUNFENG LIN on 12/24/19.
//  Copyright © 2019 Facebook. All rights reserved.
//

import Foundation
import AWSDK
import SwiftUI

@objc(AmwellViewManager)
class AmwellViewManager: RCTViewManager {
    
    var viewController : AWSDKViewController?
    
    override init() {
        viewController = AWSDKViewController()
    }
    
    override func view() -> UIView! {
        return viewController?.view
    }
    
    // this is required since RN 0.49+
    override static func requiresMainQueueSetup() -> Bool {
        return true
    }
    
    // MARK: Bridged methods
    @objc func triggerRequest() -> Void {
        print("trigger Request")
    }
    
    @objc func test() -> Void {
        print("test called!")
    }
    
    @objc func updateValueViaManager(_ node: NSNumber) {
        print("updateValueViaManager")
        
        DispatchQueue.main.async {
            self.viewController!.testVideoCall()
        }
    }
}
