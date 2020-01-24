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
    
    var viewController : AmwellViewController?
    
    override init() {
        viewController = AmwellViewController()
    }
    
    override func view() -> UIView! {
        return viewController?.view
    }
    
    // this is required since RN 0.49+
    override static func requiresMainQueueSetup() -> Bool {
        return true
    }
    
    // MARK: Bridged methods
    @objc func testVideoCall(_ node: NSNumber) {
        DispatchQueue.main.async {
            self.viewController!.demoVideoCall()
        }
    }
}
