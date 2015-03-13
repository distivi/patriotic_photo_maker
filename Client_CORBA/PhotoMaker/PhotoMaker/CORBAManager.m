//
//  CORBAManager.m
//  PhotoMaker
//
//  Created by Stas on 13.03.15.
//  Copyright (c) 2015 Distvi. All rights reserved.
//

#import "CORBAManager.h"
#import "ADORB.h"
#include "HelloWorld.idl"

@interface CORBAManager()
{
    CORBAObject* server;
}

@end

@implementation CORBAManager

+ (instancetype)sharedInstance
{
    static CORBAManager *singleton = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        singleton = [[CORBAManager alloc] init];
    });
    
    return singleton;
}

- (instancetype)init
{
    if (self = [super init]) {
        //
    }
    return self;
}

- (void)sendTestMessage
{
    
    CORBAObject* server; // assume it exists
    
//    id type = [[ORB defaultORB] definitionNamed:@"Example/Echo"];
//    NSDictionary* name = [NSDictionary dictionaryWithObjectsAndKeys:
//                          @"some-name", @"id", @"some-ext", @"kind", nil];
//    IDLAnyObject* arg = [IDLAnyObject objectWithIDLType:type];
//    [arg setValue:name];
    
//    IDLObject *strObject = [[IDLObject alloc] initWithIDLType:<#(id<IDLDefinition>)#>]
    
    [server echoString:@"asdf"];

}

@end
