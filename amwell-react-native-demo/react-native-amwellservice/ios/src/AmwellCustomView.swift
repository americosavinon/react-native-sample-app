//
//  AmwellCustomView.swift
//  Amwellservice
//
//  Created by Yunfeng Lin on 1/10/20.
//  Copyright © 2020 Facebook. All rights reserved.
//

import Foundation

class AmwellCustomView: UIView {

    @objc var onUpdate: RCTDirectEventBlock?
    
    //initWithFrame to init view from code
    override init(frame: CGRect) {
      super.init(frame: frame)
      setupView()
    }
    
    //initWithCode to init view from xib or storyboard
    required init?(coder aDecoder: NSCoder) {
      super.init(coder: aDecoder)
      setupView()
    }
    
    //common func to init our view
    private func setupView() {
        // this is for debug
        backgroundColor = .lightGray
    }
}
