//
//  CounterViewManager.swift
//  Amwellservice
//
//  Created by Yunfeng Lin on 12/19/19.
//  Copyright © 2019 Facebook. All rights reserved.
//

import Foundation

@objc(CounterViewManager)
class CounterViewManager: RCTViewManager {
  override func view() -> UIView! {
    return CounterView()
  }
  
  // this is required since RN 0.49+
  override static func requiresMainQueueSetup() -> Bool {
    return true
  }
  
  @objc func updateFromManager(_ node: NSNumber, count: NSNumber) {
    DispatchQueue.main.async {
      let component = self.bridge.uiManager.view(
        forReactTag: node
      ) as! CounterView
      component.update(value: count)
    }
  }
}
