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
                                        password: "cs123!@#", resolver: { (value) in
                                            XCTAssertTrue(value! as? String == "AWSDKAuthenticationService authenticateConsumer successfully!")
                                            
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

    func testPerformanceExample() {
        // This is an example of a performance test case.
        measure {
            // Put the code you want to measure the time of here.
        }
    }

}
