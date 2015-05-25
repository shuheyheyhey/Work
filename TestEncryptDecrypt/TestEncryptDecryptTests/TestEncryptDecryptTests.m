//
//  TestEncryptDecryptTests.m
//  TestEncryptDecryptTests
//
//  Created by 湯川 修平 on 5/9/15.
//  Copyright (c) 2015 湯川 修平. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

@interface TestEncryptDecryptTests : XCTestCase

@end

@implementation TestEncryptDecryptTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    // This is an example of a functional test case.
    XCTAssert(YES, @"Pass");
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
