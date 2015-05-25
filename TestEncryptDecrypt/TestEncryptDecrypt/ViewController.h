//
//  ViewController.h
//  TestEncryptDecrypt
//
//  Created by 湯川 修平 on 5/9/15.
//  Copyright (c) 2015 湯川 修平. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#include "EncryptDecrypt.h"

@interface ViewController : NSViewController

@property(nonatomic,retain)IBOutlet NSTextView* inputTextView;
@property(nonatomic,retain)IBOutlet NSTextView* encryptTextView;
@property(nonatomic,retain)IBOutlet NSTextView* decryptTextView;

@property(nonatomic,retain)IBOutlet NSTextField* encryptKeyText;
@property(nonatomic,retain)IBOutlet NSTextField* publicKeyText;


-(IBAction)start:(id)sender;

@end

