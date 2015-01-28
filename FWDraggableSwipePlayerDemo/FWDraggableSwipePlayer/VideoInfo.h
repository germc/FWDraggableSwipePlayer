//
//  VideoInfo.h
//  FWDraggableSwipePlayer
//
//  Created by Filly Wang on 27/1/15.
//  Copyright (c) 2015 Filly Wang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VideoInfo : NSObject

@property (nonatomic, strong) NSMutableArray *subtitles;
@property (nonatomic, strong) NSMutableArray *audios;

-(id)initWithDic:(NSDictionary*)dict;

@end

@interface VideoSubtitle : NSObject

@property (nonatomic, strong) NSString *lang;
@property (nonatomic, strong) NSString *readableLang;
@property (nonatomic, strong) NSString *path;

- (void)ObjWithDict:(NSDictionary*)dict;
- (NSString*)supportLang;

@end

@interface VideoAudio : NSObject

@property (nonatomic, strong) NSString *episode_id;
@property (nonatomic, strong) NSNumber *track;
@property (nonatomic, assign) int audioIndex;
@property (nonatomic, strong) NSString *lang;
@property (nonatomic, strong) NSString *readableLang;
@property (nonatomic, strong) NSString *mode;

- (void)ObjWithDict:(NSDictionary*)dict;
- (NSString*)supportLang;

@end
