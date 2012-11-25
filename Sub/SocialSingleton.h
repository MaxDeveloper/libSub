//
//  SocialSingleton.h
//  iSub
//
//  Created by Ben Baron on 10/15/10.
//  Copyright 2010 Ben Baron. All rights reserved.
//

#ifndef iSub_SocialSingleton_h
#define iSub_SocialSingleton_h

#define socialS ((SocialSingleton *)[SocialSingleton sharedInstance])

#import "SA_OAuthTwitterController.h"

@class SA_OAuthTwitterEngine, Song;

@interface SocialSingleton : NSObject <SA_OAuthTwitterControllerDelegate>

@property (strong) SA_OAuthTwitterEngine *twitterEngine;

@property (readonly) NSTimeInterval scrobbleDelay;
@property (readonly) NSTimeInterval subsonicDelay;
@property (readonly) NSTimeInterval tweetDelay;

+ (id)sharedInstance;

- (void)createTwitterEngine;
- (void)destroyTwitterEngine;

- (void)scrobbleSongAsPlaying;
- (void)scrobbleSongAsSubmission;
- (void)scrobbleSong:(ISMSSong *)aSong isSubmission:(BOOL)isSubmission;
- (void)tweetSong;
- (void)notifySubsonic;

@property (nonatomic) BOOL playerHasNotifiedSubsonic;
@property (nonatomic) BOOL playerHasTweeted;
@property (nonatomic) BOOL playerHasScrobbled;
- (void)playerHandleSocial;
- (void)playerClearSocial;

@end

#endif