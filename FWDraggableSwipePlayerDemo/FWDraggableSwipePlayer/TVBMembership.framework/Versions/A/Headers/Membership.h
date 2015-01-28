//
//  Membership.h
//  mytvHD
//
//  Created by Ted Cheng on 20/5/13.
//  Copyright (c) 2013 Ted Cheng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MembershipLoginViewController.h"
#import "MembershipRegisterViewController.h"

@interface Membership : NSObject

extern NSString *const MembershipLanguageEnglish;
extern NSString *const MembershipLanguageTraditionalChinese;
extern NSString *const MembershipLanguageSimplifiedChinese;

// for backward compatibility
// default to allow registration and disable facebook login
+ (void)showLoginViewControllerOnViewController:(UIViewController *)viewCon
                                   withLanguage:(NSString*)language
                                     completion:(void(^)()) completion
                                       delegate:(id<MembershipLoginViewControllerDelegate,MembershipRegisterViewControllerDelegate>) delegate;

// for backward compatibility
// default to allow registration
+ (void)showLoginViewControllerOnViewController:(UIViewController *)viewCon
                                   withLanguage:(NSString*)language
                                   withFacebook:(BOOL)withFb
                                     completion:(void(^)()) completion
                                       delegate:(id<MembershipLoginViewControllerDelegate,MembershipRegisterViewControllerDelegate>) delegate;

// language options:
//   MembershipLanguageEnglish,
//   MembershipLanguageTraditionalChinese,
//   MembershipLanguageSimplifiedChinese,
// default is MembershipLanguageTraditionalChinese
+ (void)showLoginViewControllerOnViewController:(UIViewController *)viewCon
                                   withLanguage:(NSString*)language
                                   withFacebook:(BOOL)withFb
                               withRegistration:(bool)withRegistration
                                     completion:(void(^)()) completion
                                       delegate:(id<MembershipLoginViewControllerDelegate,MembershipRegisterViewControllerDelegate>) delegate;


+ (void)dismissLoginViewControllerWithCompletion:(void(^)())completion;

@end