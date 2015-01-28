//
//  MembershipLoginViewController.h
//  mytvHD
//
//  Created by Ted Cheng on 20/5/13.
//  Copyright (c) 2013 Ted Cheng. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MembershipRegisterViewController.h"

@protocol MembershipLoginViewControllerDelegate;

@interface MembershipLoginViewController : UIViewController<UITextFieldDelegate> {
    @private
    id<MembershipLoginViewControllerDelegate, MembershipRegisterViewControllerDelegate> __unsafe_unretained _delegate;
}

@property (nonatomic, assign) BOOL withFacebook;
@property (nonatomic, assign) BOOL withRegistration;
@property (unsafe_unretained) id<MembershipLoginViewControllerDelegate, MembershipRegisterViewControllerDelegate> delegate; // do not use strong reference to avoid circular retain counts

@end

@protocol MembershipLoginViewControllerDelegate <NSObject>

- (void)membershipLoginViewController:(MembershipLoginViewController*)viewController
                            onDismiss:(BOOL)isLoggedIn; // called when membership login view controller dimisses itself

- (void)membershipLoginViewControllerViewDidAppear:(MembershipLoginViewController *)viewController;

@end

