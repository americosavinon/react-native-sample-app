//
//  AmwellserviceTests.swift
//  AmwellserviceTests
//
//  Created by Yunfeng Lin on 12/16/19.
//  Copyright © 2019 Facebook. All rights reserved.
//

import XCTest

@testable import AWSDK
@testable import Amwellservice

class FakeDelegate : NSObject, AWSDKVisitDelegate, AWSDKCallbackDelegate {
    func providerDidEnterVisit() {
        
    }
    
    func visitDidComplete(_ visitSuccessful: Bool, with: AWCoreVisitEndReason) {
        
    }
    
    func callbackStatusDidChange(_ status: AWSDKCallbackStatus) {
        
    }
}

class AmwellserviceTests: XCTestCase {
    
    var target: Amwellservice!
    
    override func setUp() {
        // Put setup code here. This method is called before the invocation of each test method in the class.
        super.setUp()
        target = Amwellservice()
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        target = nil
        super.tearDown()
    }
    
    func testAuthentication() {
        
        let exp = expectation(description: "Test testAuthentication Async function!")
        
        self.target.initialize({ (value) in
            
            self.target.authenticateConsumer("yunfeng.lin@rallyhealth.com",
                                             password: "cs123!@#", resolver: { (consumer) in
                                                // XCTAssertTrue(value! as? String == "AWSDKAuthenticationService authenticateConsumer successfully!")
                                                print(consumer!)
                                                
                                                // Don't forget to fulfill the expectation in the async callback
                                                exp.fulfill()
                                                
            }, rejecter: { (error, type, Error) in
                XCTAssertTrue(error! == "auth_fail")
                exp.fulfill()
            })
            
        }) { (error, type, Error) in
            print(error!)
            exp.fulfill()
        }
        
        waitForExpectations(timeout: 5, handler: nil)
    }
    
    func testGetPracticeList() {
        
        let exp = expectation(description: "Test GetPracticeList Async function!")
        
        self.target.initialize({ (value) in
            
            self.target.authenticateConsumer("yunfeng.lin@rallyhealth.com",
                                             password: "cs123!@#", resolver: { (consumer) in
                                                // XCTAssertTrue(value! as? String == "AWSDKAuthenticationService authenticateConsumer successfully!")
                                                print(consumer!)
                                                
                                                let consumerWrapper = consumer as? AWSDKConsumer
                                                
                                                self.target.fetchPractices(consumerWrapper!, resolver: { (practices) in
                                                    // check for return value of practices
                                                    print(practices!)
                                                    // Don't forget to fulfill the expectation in the async callback
                                                    exp.fulfill()
                                                    
                                                }, rejecter: { (error, type, Error) in
                                                    // check for error
                                                    exp.fulfill()
                                                })
                                                
            }, rejecter: { (error, type, Error) in
                // XCTAssertTrue(error! == "auth_fail")
                exp.fulfill()
            })
            
        }) { (error, type, Error) in
            print(error!)
            exp.fulfill()
        }
        
        waitForExpectations(timeout: 5, handler: nil)
    }
    
    func testGetConsumerSpecialties() {
        
        let exp = expectation(description: "Test GetConsumerSpecialties Async function!")
        
        self.target.initialize({ (value) in
            
            self.target.authenticateConsumer("yunfeng.lin@rallyhealth.com",
                                             password: "cs123!@#", resolver: { (consumer) in
                                                // XCTAssertTrue(value! as? String == "AWSDKAuthenticationService authenticateConsumer successfully!")
                                                print(consumer!)
                                                
                                                let consumerWrapper = consumer as? AWSDKConsumer
                                                
                                                self.target.fetchPractices(consumerWrapper!, resolver: { (practices) in
                                                    // check for return value of practices
                                                    print(practices!)
                                                    
                                                    let practiceData = practices as! [AWSDKPractice]
                                                    
                                                    // need to use practice to get the specialty
                                                    self.target.getConsumerSpecialties(consumerWrapper!, practice: practiceData[0], resolver: { (value) in
                                                        
                                                        print(value!)
                                                        
                                                        // Don't forget to fulfill the expectation in the async callback
                                                        exp.fulfill()
                                                        
                                                    }, rejecter: { (error, type, Error) in
                                                        // XCTAssertTrue(error! == "init_fail")
                                                        exp.fulfill()
                                                    })
                                                    
                                                }, rejecter: { (error, type, Error) in
                                                    // check for error
                                                    exp.fulfill()
                                                })
                                                
            }, rejecter: { (error, type, Error) in
                // XCTAssertTrue(error! == "auth_fail")
                exp.fulfill()
            })
            
        }) { (error, type, Error) in
            print(error!)
            exp.fulfill()
        }
        
        waitForExpectations(timeout: 5, handler: nil)
    }
    
    func testCreateVisitContextForConsumer() {
        
        let exp = expectation(description: "Test CreateVisitContextForConsumer Async function!")
        
        self.target.initialize({ (value) in
            
            self.target.authenticateConsumer("yunfeng.lin@rallyhealth.com",
                                             password: "cs123!@#", resolver: { (consumer) in
                                                // XCTAssertTrue(value! as? String == "AWSDKAuthenticationService authenticateConsumer successfully!")
                                                print(consumer!)
                                                
                                                let consumerWrapper = consumer as? AWSDKConsumer
                                                
                                                self.target.fetchPractices(consumerWrapper!, resolver: { (practices) in
                                                    // check for return value of practices
                                                    print(practices!)
                                                    
                                                    let practiceData = practices as! [AWSDKPractice]
                                                    
                                                    // need to use practice to get the specialty
                                                    self.target.getConsumerSpecialties(consumerWrapper!, practice: practiceData[0], resolver: { (specialties) in
                                                        
                                                        print(specialties!)
                                                        
                                                        let specialtyDataList = specialties as! [AWSDKOnDemandSpecialty]
                                                        
                                                        self.target.createVisitContextForConsumer(consumerWrapper!, specialty: specialtyDataList[0], resolver: { (visitContext) in
                                                            
                                                            let context = visitContext as! AWSDKVisitContext
                                                            print(context)
                                                            
                                                            // Don't forget to fulfill the expectation in the async callback
                                                            exp.fulfill()
                                                            
                                                        }, rejecter: { (error, type, Error) in
                                                            exp.fulfill()
                                                        })
                                                        
                                                        // Don't forget to fulfill the expectation in the async callback
                                                        // exp.fulfill()
                                                        
                                                    }, rejecter: { (error, type, Error) in
                                                        // XCTAssertTrue(error! == "init_fail")
                                                        exp.fulfill()
                                                    })
                                                    
                                                }, rejecter: { (error, type, Error) in
                                                    // check for error
                                                    exp.fulfill()
                                                })
                                                
            }, rejecter: { (error, type, Error) in
                // XCTAssertTrue(error! == "auth_fail")
                exp.fulfill()
            })
            
        }) { (error, type, Error) in
            print(error!)
            exp.fulfill()
        }
        
        waitForExpectations(timeout: 5, handler: nil)
    }
    
    
    func testCreateVisitWithContext() {
        
        let exp = expectation(description: "Test CreateVisitWithContext Async function!")
        
        self.target.initialize({ (value) in
            
            self.target.authenticateConsumer("yunfeng.lin@rallyhealth.com",
                                             password: "cs123!@#", resolver: { (consumer) in
                                                // XCTAssertTrue(value! as? String == "AWSDKAuthenticationService authenticateConsumer successfully!")
                                                print(consumer!)
                                                
                                                let consumerWrapper = consumer as? AWSDKConsumer
                                                
                                                self.target.fetchPractices(consumerWrapper!, resolver: { (practices) in
                                                    // check for return value of practices
                                                    print(practices!)
                                                    
                                                    let practiceDataList = practices as! [AWSDKPractice]
                                                    
                                                    // need to use practice to get the specialty
                                                    self.target.getConsumerSpecialties(consumerWrapper!, practice: practiceDataList[0], resolver: { (specialties) in
                                                        
                                                        print(specialties!)
                                                        
                                                        let specialtyDataList = specialties as! [AWSDKOnDemandSpecialty]
                                                        
                                                        self.target.createVisitContextForConsumer(consumerWrapper!, specialty: specialtyDataList[0], resolver: { (visitContext) in
                                                            
                                                            let context = visitContext as! AWSDKVisitContext
                                                            print(practiceDataList[0].availableModalities)
                                                            
                                                            let modalities = practiceDataList[0].availableModalities
                                                            print(modalities)
                                                            
                                                            context.selectedModality = modalities[0]
                                                            
                                                            // Valid Context
                                                            do {
                                                                let valid = try AWSDKVisitService.isVisitContextValid(context, cartMode: false)
                                                                print(valid)
                                                            } catch {
                                                                print("Unexpected non-vending-machine-related error: \(error)")
                                                            }
                                                            
                                                            // Debug the Providers
                                                            //let debugProvider = context.

                                                            self.target.createVisitWithContext(context, resolver: { (visit) in

                                                                print(visit!)
                                                                
                                                                let visitData = visit as? AWSDKVisit
                                                                let delegateInstance = FakeDelegate()
                                                                visitData?.delegate = delegateInstance
                                                                visitData?.callbackDelegate = delegateInstance
                                                                
                                                                // Verify if the
//                                                                AWSDKVisitService.ready(toStart: visitData!) {
//                                                                    (result, error) in
//
//                                                                    if (error != nil) {
//                                                                       print(error!)
//                                                                        exp.fulfill()
//                                                                    } else {
//                                                                       print(result)
//                                                                        exp.fulfill()
//                                                                    }
//                                                                }
                                                                
                                                                let givenName = visitData!.provider.nameComponents.givenName
                                                                let familyName = visitData!.provider.nameComponents.familyName
                                                                
                                                                AWSDKVisitService.start(visitData!) {
                                                                    (result, error) in
                                                                    
                                                                    if (error != nil) {
                                                                        print(error!)
                                                                        exp.fulfill()
                                                                    } else {
                                                                        print(result)
                                                                        
                                                                        // this test is successful!
                                                                        exp.fulfill()
                                                                    }
                                                                }
                                                                

                                                                // Don't forget to fulfill the expectation in the async callback
                                                                //exp.fulfill()

                                                            }, rejecter: { (error, type, Error) in
                                                                exp.fulfill()
                                                            })
                                                            
                                                            // exp.fulfill()
                                                            
                                                        }, rejecter: { (error, type, Error) in
                                                            exp.fulfill()
                                                        })
                                                        
                                                        // Don't forget to fulfill the expectation in the async callback
                                                        // exp.fulfill()
                                                        
                                                    }, rejecter: { (error, type, Error) in
                                                        // XCTAssertTrue(error! == "init_fail")
                                                        exp.fulfill()
                                                    })
                                                    
                                                }, rejecter: { (error, type, Error) in
                                                    // check for error
                                                    exp.fulfill()
                                                })
                                                
            }, rejecter: { (error, type, Error) in
                // XCTAssertTrue(error! == "auth_fail")
                exp.fulfill()
            })
            
        }) { (error, type, Error) in
            print(error!)
            exp.fulfill()
        }
        
        waitForExpectations(timeout: 5, handler: nil)
    }
    
    func testsetCount() {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct results.
        let exp = expectation(description: "Test setCount Async function!")
        
        target.setCount(_: 3, resolver: { (value) in
            XCTAssertTrue(value! as? Int == 3)
            
            // Don't forget to fulfill the expectation in the async callback
            exp.fulfill()
            
        }, rejecter: { (error, type, Error) in
            XCTAssertTrue(error! == "init_fail")
            exp.fulfill()
        })
        
        waitForExpectations(timeout: 0.3, handler: nil)
    }
    
    func testFindProvider() {
        
        let exp = expectation(description: "testFindProvider Async function!")
        
        
        
        self.target.initialize({
            (value) in
            
            self.target.authenticateConsumer("yunfeng.lin@rallyhealth.com",
                                             password: "cs123!@#", resolver: { (consumer) in
                                                // XCTAssertTrue(value! as? String == "AWSDKAuthenticationService authenticateConsumer successfully!")
                                                print(consumer!)
                                                
                                                let option = AWSDKProviderSearchOptions.init()
                                                option.name = "Test Four"
                                                option.consumer = consumer as? AWSDKConsumer
                                                
                                                AWSDKProviderService.performProviderSearch(with: option)
                                                {
                                                    (result, error) in
                                                    
                                                    if (error != nil) {
                                                        print(error)
                                                        exp.fulfill()
                                                    } else {
                                                        print(result!)
                                                        
                                                        let providers = result as! [AWSDKProviderSearchResult]
                                                        let searchResult = providers.count
                                                        
                                                        providers[0].fetchDetails() {
                                                            (data, error) in
                                                            
                                                            if (error != nil) {
                                                                print(error)
                                                                exp.fulfill()
                                                            } else {
                                                                print(data)
                                                                exp.fulfill()
                                                            }
                                                        }
                                                        
                                                        // exp.fulfill()
                                                    }
                                                }
                                                
            }, rejecter: { (error, type, Error) in
                XCTAssertTrue(error! == "auth_fail")
                exp.fulfill()
            })
            
        }) { (error, type, Error) in
            print(error!)
            exp.fulfill()
        }
        
         waitForExpectations(timeout: 5, handler: nil)
    }
    
    func testPerformanceExample() {
        // This is an example of a performance test case.
        measure {
            // Put the code you want to measure the time of here.
        }
    }
    
}
