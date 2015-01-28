//
//  VideoInfo.m
//  FWDraggableSwipePlayer
//
//  Created by Filly Wang on 27/1/15.
//  Copyright (c) 2015 Filly Wang. All rights reserved.
//

#import "VideoInfo.h"

@implementation VideoInfo

-(id)initWithDic:(NSDictionary*)dict
{
    self = [super init];
    if (self)
    {
        if (dict)
        {
            @try
            {
                self.subtitles = [[NSMutableArray alloc] init];
                self.audios = [[NSMutableArray alloc] init];
                
                if ([dict objectForKey:@"subtitles"] )
                {
                    [self addSubtitles:[dict objectForKey:@"subtitles"]];
                }
                
                if ([dict objectForKey:@"audio"] )
                {
                    [self addAudio:[dict objectForKey:@"audio"]];
                }
            }
            @catch (NSException *exception) {
                NSLog(@"exception in : %@", exception.reason);
            }
        }
    }
    return self;
}

-(void)addSubtitles:(NSMutableArray *)array
{
    for (NSDictionary *dict in array)
    {
        VideoSubtitle *obj = [[VideoSubtitle alloc]init];
        [obj ObjWithDict:dict];
        [array addObject:obj];
    }
}

-(void)addAudio:(NSMutableArray *)array
{
    for (NSDictionary *dict in array)
    {
        VideoAudio *obj = [[VideoAudio alloc]init];
        [obj ObjWithDict:dict];
        [array addObject:obj];
    }
}
@end

@implementation VideoAudio

- (void)ObjWithDict:(NSDictionary*)dict
{
    self.lang = [dict objectForKey:@"lang"] ? [dict objectForKey:@"lang"] : @"";
    self.readableLang = @"";
}

- (NSString *)readableLang
{
    NSString *langKey = [NSString stringWithFormat:@"VideoAudio - %@", self.lang];
    return NSLocalizedString(langKey, nil);
}

- (NSString*)supportLang
{
    if ([self.lang isEqualToString:@"Cantonese"])return @"";
    if ([self.lang isEqualToString:@"Mandarin"])return @"";
    if ([self.lang isEqualToString:@"English"])return @"";
    return @"";
}

- (int)audioIndex
{
    return [self.track intValue] - 1;
}

@end

@implementation VideoSubtitle

- (void)ObjWithDict:(NSDictionary*)dict
{
    self.lang = [dict objectForKey:@"lang"] ? [dict objectForKey:@"lang"] : @"";
    self.readableLang = @"";
    self.path = [dict objectForKey:@"path"] ? [dict objectForKey:@"path"] : @"";
}

- (NSString *)readableLang
{
    NSString *langKey = [NSString stringWithFormat:@"VideoSubtitle - %@", self.lang];
    return NSLocalizedString(langKey, nil);
}

- (NSString*)supportLang
{
    if ([self.lang isEqualToString:@"tc"])return @"";
    if ([self.lang isEqualToString:@"sc"])return @"";
    if ([self.lang isEqualToString:@"en"])return @"";
    return @"";
}

@end
