//
//  CORBAManager.h
//  PhotoMaker
//
//  Created by Stas on 13.03.15.
//  Copyright (c) 2015 Distvi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CORBAManager : NSObject

+ (instancetype)sharedInstance;

- (void)sendTestMessage;

@end
