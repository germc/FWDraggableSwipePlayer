//
//  MSAuthApi.h
//  MembershipAuthAPITester
//
//  Created by Vincent Tsang on 26/4/13.
//  Copyright (c) 2013 tvb.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <FacebookSDK/FacebookSDK.h>

typedef enum {
    LoginSuccess,
    LoginErrorNetwork,
    LoginErrorCredential,
    LoginErrorUnknown
} LoginStatus;


@interface MSAuthApi : NSObject {
    NSString *user_token;
    NSString *login_id;
}

@property(nonatomic, readonly) NSString* loginID;
@property(nonatomic, readonly) NSString* token;
@property(nonatomic, readonly) int userStatus;
@property(nonatomic, readonly) NSString* errorMessage;

+ (MSAuthApi* )sharedApi;

- (BOOL)isLoggedIn;

// password login
- (void)asyncLoginWithUsername:(NSString *)username
          password:(NSString *)password
 completionHandler:(void (^)(BOOL SUCCESS, LoginStatus errMsg, NSDictionary* userInfo))handler;

- (BOOL)synchronousLoginWithUsername:(NSString *)username
     password:(NSString *)password;

// facebook login
- (void)asyncLoginWithFacebookId:(NSString*)fbid
               completionHandler:(void(^)(BOOL success, LoginStatus errMsg, NSDictionary* userInfo))handler;
- (BOOL)synchronousLoginWithFacebookId:(NSString*)fbid;

// logout
- (void)asyncLogoutWithCompletionHandler:(void(^)(BOOL success))completionHandler;
- (BOOL)synchronousLogout;

// get user info
- (void)asyncGetUserInfo:(void(^)(NSDictionary* userInfo))completionHandler;
- (NSDictionary *)synchronousGetUserInfo;

// registration
- (void)asyncRegisterMemebershipWithUsername:(NSString *)userID
                                    password:(NSString *) password
                                   subscribe:(BOOL) subscribe
                                    langauge:(NSString*)language
                           completion:(void(^)(BOOL success, LoginStatus errMsg, NSDictionary* userInfo))completionHandler;

- (void)asyncConvertQuickPlayToken:(NSString*)quickplayToken
                        completion:(void(^)(BOOL success))completionHandler;

- (NSString*)getLastLoginUsername;

@end
