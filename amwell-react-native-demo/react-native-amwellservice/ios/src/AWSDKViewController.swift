//
//  AWSDKViewController.swift
//  Amwellservice
//
//  Created by YUNFENG LIN on 12/24/19.
//  Copyright © 2019 Facebook. All rights reserved.
//

import Foundation
import SwiftUI
import AWSDK

class ToastLabel: UILabel {
    var textInsets = UIEdgeInsets.zero {
        didSet { invalidateIntrinsicContentSize() }
    }

    override func textRect(forBounds bounds: CGRect, limitedToNumberOfLines numberOfLines: Int) -> CGRect {
        let insetRect = bounds.inset(by: textInsets)
        let textRect = super.textRect(forBounds: insetRect, limitedToNumberOfLines: numberOfLines)
        let invertedInsets = UIEdgeInsets(top: -textInsets.top, left: -textInsets.left, bottom: -textInsets.bottom, right: -textInsets.right)

        return textRect.inset(by: invertedInsets)
    }

    override func drawText(in rect: CGRect) {
        super.drawText(in: rect.inset(by: textInsets))
    }
}

extension UIViewController {
    static let DELAY_SHORT = 1.5
    static let DELAY_LONG = 3.0

    func showToast(_ text: String, delay: TimeInterval = DELAY_LONG) {
        let label = ToastLabel()
        label.backgroundColor = UIColor(white: 0, alpha: 0.5)
        label.textColor = .white
        label.textAlignment = .center
        label.font = UIFont.systemFont(ofSize: 15)
        label.alpha = 0
        label.text = text
        label.clipsToBounds = true
        label.layer.cornerRadius = 20
        label.numberOfLines = 0
        label.textInsets = UIEdgeInsets(top: 10, left: 15, bottom: 10, right: 15)
        label.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(label)

        let saveArea = view.safeAreaLayoutGuide
        label.centerXAnchor.constraint(equalTo: saveArea.centerXAnchor, constant: 0).isActive = true
        label.leadingAnchor.constraint(greaterThanOrEqualTo: saveArea.leadingAnchor, constant: 15).isActive = true
        label.trailingAnchor.constraint(lessThanOrEqualTo: saveArea.trailingAnchor, constant: -15).isActive = true
        label.bottomAnchor.constraint(equalTo: saveArea.bottomAnchor, constant: -30).isActive = true

        UIView.animate(withDuration: 0.5, delay: 0, options: .curveEaseIn, animations: {
            label.alpha = 1
        }, completion: { _ in
            UIView.animate(withDuration: 0.5, delay: delay, options: .curveEaseOut, animations: {
                label.alpha = 0
            }, completion: {_ in
                label.removeFromSuperview()
            })
        })
    }
}

/**
 *  We need to use this controller to manage and control the video call testing.
 */
class AWSDKViewController: UIViewController, AWSDKVisitDelegate {
    var console:AWCoreVisitConsoleController?
    var visit: AWSDKVisit?
    var context: AWSDKVisitContext?
    
    // AWSDKVisitDelegate
    func providerDidEnterVisit() {
        print("providerDidEnterVisit")
        showToast("Now start to launch video!")
        onUpdate!(["virtualvisit-progress": "Now start to launch video!"])
        createVisitConsole()
    }
    
    func visitDidComplete(_ visitSuccessful: Bool, with: AWCoreVisitEndReason) {
        print("visitDidComplete")
        // self.view.makeToast("Visit did complete!")
        showToast("Visit did complete!")
        onUpdate!(["virtualvisit-progress": "Visit did complete!"])
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.

        let button = UIButton(frame: CGRect(x: 0, y: 0, width: 200, height: 100))
        button.backgroundColor = .white
        button.tintColor = .blue
        button.setTitle("AmwellSDK ViewManager Component @ rally health", for: .normal)
        view.addSubview(button)
    }

    @objc var onUpdate: RCTDirectEventBlock?
    
    func testVideoCall() {
        launchVisit()

        onUpdate!(["virtualvisit-progress": "start to launch visit console!"])
        showToast("Launch visit console ... !")
    }
    
    func launchVisit() {
        AWSDKService.initialize(withLaunchParams: [kAWSDKBundleID: "com.uhg.amwelldemo",
                                                   kAWSDKUrl: "https://iot58.amwellintegration.com/",
                                                   kAWSDKKey: "bf8a5665"]) { (success, error) in
                                                    if success {
                                                        print("AWSDKService initialize successfully!")
                                                        
                                                        AWSDKAuthenticationService.authenticateConsumer(withUsername: "yunfeng.lin@rallyhealth.com",
                                                                                                        password: "cs123!@#",
                                                                                                        consumerAuthKey: nil) { (result, error) in
                                                                                                            
                                                                                                            if (error != nil) {
                                                                                                                print(error)
                                                                                                            } else {
                                                                                                                let consumer = result! as? AWSDKConsumer
                                                                                                                
                                                                                                                let option = AWSDKProviderSearchOptions.init()
                                                                                                                option.name = "Test Four"
                                                                                                                option.maxResults = 300
                                                                                                                
                                                                                                                AWSDKProviderService.performProviderSearch(with: option) {
                                                                                                                    (result, error) in
                                                                                                                    
                                                                                                                    if (error != nil) {
                                                                                                                        print(error)
                                                                                                                    } else {
                                                                                                                        print(result!)
                                                                                                                        
                                                                                                                        let providers = result as! [AWSDKProviderSearchResult]
                                                                                                                        var provider = providers[0]
                                                                                                                        
                                                                                                                        // search for the Test Four
                                                                                                                        for item in providers {
                                                                                                                            let data = item.nameComponents.familyName! + " - " + item.nameComponents.givenName!
                                                                                                                            print(data)
                                                                                                                            if (item.nameComponents.familyName! == "Four") {
                                                                                                                                provider = item
                                                                                                                                if (provider.availability == AWSDKMobileAvailability.Offline ) {
                                                                                
                                                                                                                                    self.showToast("Provider is offline :(  ... !")
                                                                                                                                    onUpdate!(["virtualvisit-progress": "Provider is offline :(  ... !"])
                                                                                                                                }
                                                                                                                                break;
                                                                                                                            }
                                                                                                                        }
                                                                                                                        
                                                                                                                        provider.fetchDetails() {
                                                                                                                            (data, error) in
                                                                                                                            
                                                                                                                            if (error != nil) {
                                                                                                                                print(error)
                                                                                                                            } else {
                                                                                                                                print(data)
                                                                                                                                
                                                                                                                                AWSDKVisitContext.createVisitContext(for: consumer!, provider: data!) {
                                                                                                                                    (result, error) in
                                                                                                                                    
                                                                                                                                    if (error != nil) {
                                                                                                                                        print(error)
                                                                                                                                    } else {
                                                                                                                                        self.showToast("createVisitContext success!")
                                                                                                                                        
                                                                                                                                        self.context = result as! AWSDKVisitContext
                                                                                                                                        self.context!.legalText[0].setAccepted()
                                                                                                                                        self.context!.selectedModality = AWSDKService.availableModalities![0]
                                                                                                                                        
                                                                                                                                        AWSDKVisitService.createVisit(with: self.context!) {
                                                                                                                                            (result, error) in
                                                                                                                                            
                                                                                                                                            if (error != nil) {
                                                                                                                                                print(error)
                                                                                                                                            } else {
                                                                                                                                                var visit = result as! AWSDKVisit
                                                                                                                                                self.visit = visit
                                                                                                                                                self.visit!.delegate = self
                                                                                                                                                // visitData.callbackDelegate = self
                                                                                                                                                
                                                                                                                                                AWSDKVisitService.start(self.visit!) {
                                                                                                                                                    (result, error) in
                                                                                                                                                    
                                                                                                                                                    if (error != nil) {
                                                                                                                                                        print(error!)
                                                                                                                                                    } else {
                                                                                                                                                        self.showToast("start visit now!");
                                                                                                                                                      
                                                                                                                                                        print(result)
                                                                                                                                                    }
                                                                                                                                                    
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                        
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                        
                                                                                                                    }
                                                                                                                }
                                                                                                                
                                                                                                            }
                                                                                                            
                                                        }
                                                    }
        }
    }
    
    func createVisitConsole() {
        AWSDKVisitService.createVisitConsole(for: self.visit!) {
            (result, error) in
            
            if (error != nil) {
                print(error!)
            } else {
                print(result)
                
                self.console = result
                // self.present(self.console!, animated: true, completion: nil)
                self.view.window!.rootViewController!.present(self.console!, animated: true, completion: nil)
            }
        }
    }
}
