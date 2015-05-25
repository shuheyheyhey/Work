//
//  ViewController.m
//  TestEncryptDecrypt
//
//  Created by 湯川 修平 on 5/9/15.
//  Copyright (c) 2015 湯川 修平. All rights reserved.
//

#import "ViewController.h"


@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Do any additional setup after loading the view.
    _decryptTextView.editable = NO;
    _encryptTextView.editable = NO;
}

- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

-(IBAction)start:(id)sender
{
    const char* message = [_inputTextView.string UTF8String];
    //適当な素数
    start(1471, 1483);
    
    //暗号
    char* encrypt = returnEncyptString(message);
    NSString* encryptString = [NSString stringWithCString:encrypt encoding:NSUTF8StringEncoding];
    [_encryptTextView setString:encryptString];
    
    //復号
    char* decrypt = returnDecyptString(encrypt);
    NSString* decryptString = [NSString stringWithCString:decrypt encoding:NSUTF8StringEncoding];
    [_decryptTextView setString:decryptString];

    
}

@end
