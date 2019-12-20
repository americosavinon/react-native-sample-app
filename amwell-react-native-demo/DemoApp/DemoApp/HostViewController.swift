//
//  HostViewController.swift
//  DemoApp
//
//  Created by Yunfeng Lin on 12/20/19.
//  Copyright © 2019 Yunfeng Lin. All rights reserved.
//

import Foundation
import UIKit
import SwiftUI


class MyViewController: UIViewController, AWSDKVisitDelegate {
    
    var console: AWCoreVisitConsoleController?

    convenience init(console: AWCoreVisitConsoleController){
        self.init()
        self.console = console
    }
    
    func providerDidEnterVisit() {
        
    }
    
    func visitDidComplete(_ visitSuccessful: Bool, with: AWCoreVisitEndReason) {
        
    }
    
    func callbackStatusDidChange(_ status: AWSDKCallbackStatus) {
        
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()

        let button = UIButton(frame: CGRect(x: view.frame.width / 2, y: view.frame.height / 2, width: 40, height: 40))
        button.backgroundColor = .red
        button.tintColor = .white
        button.setTitle("Test", for: .normal)
        button.addTarget(self, action: #selector(change), for: .touchUpInside)
        view.addSubview(button)
    }

    @objc func change () {
         let otherView = SecondViewController()
        
        /*
        let contentView = NavigationView {
            Text("This is a great app")
                .navigationBarTitle("Welcome")
        }
        
        let vc = AWCoreVisitConsoleController(rootViewController: UIHostingController(rootView: contentView))
        */
        
        // print(self.console!.view.responderChain())
        
        self.present(otherView, animated: true, completion: nil)
    }

}

extension UIResponder {
    func responderChain() -> String {
        guard let next = next else {
            return String(describing: self)
        }
        return String(describing: self) + " -> " + next.responderChain()
    }
}

class SecondViewController: UINavigationController {

    override func viewDidLoad() {
        super.viewDidLoad()

        view.backgroundColor = .yellow
    }

}
//
//class HostViewController: UIViewController {
//    var username: String = "Anonymous"
//    var console: AWCoreVisitConsoleController?
//    
//    init() {
//        self.username = "Peter"
//        super.init(nibName: nil, bundle: nil)
//        
//        let contentView = NavigationView {
//                  Text("This is a great app")
//                      .navigationBarTitle("Welcome")
//               }
//        
//        self.view = contentView as! UIView
//        self.loadView()
//    }
//    
//    public required init?(coder aDecoder: NSCoder) {
//        super.init(coder: aDecoder)
//        self.username = "Test"
//    }
//    
//    public func setConsole(_ navConsole:AWCoreVisitConsoleController) {
//        self.console = navConsole
//        
//        let contentView = NavigationView {
//           Text("This is a great app")
//               .navigationBarTitle("Welcome")
//        }
//
//        self.present(UIHostingController(rootView: contentView), animated: true)
//    }
//    
//    func providerDidEnterVisit() {
//        
//    }
//    
//    func visitDidComplete(_ visitSuccessful: Bool, with: AWCoreVisitEndReason) {
//        
//    }
//    
//    func callbackStatusDidChange(_ status: AWSDKCallbackStatus) {
//        
//    }
//}
