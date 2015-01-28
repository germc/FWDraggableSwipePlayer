//
//  MembershipRegisterViewController.h
//  mytvHD
//
//  Created by Ted Cheng on 21/5/13.
//  Copyright (c) 2013 Ted Cheng. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MembershipRegisterViewControllerDelegate;

@interface MembershipRegisterViewController : UIViewController<UITextFieldDelegate>

@property (unsafe_unretained) id<MembershipRegisterViewControllerDelegate> delegate; // do not use strong reference to avoid circular retain counts

@end


@protocol MembershipRegisterViewControllerDelegate <NSObject>

- (void)membershipRegisterViewControllerViewDidAppear:(MembershipRegisterViewController *)viewController;
- (void)membershipRegisterViewController:(MembershipRegisterViewController *)viewController
                      didRegisterSuccess:(BOOL)success;

@end
