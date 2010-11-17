//
//  MPMediaItem.h
//  MediaPlayer
//
//  Copyright 2008 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <MediaPlayer/MediaPlayerDefines.h>
#import <MediaPlayer/MPMediaEntity.h>

@class UIImage;

enum {
    // audio
    MPMediaTypeMusic        = 1 << 0,
    MPMediaTypePodcast      = 1 << 1,
    MPMediaTypeAudioBook    = 1 << 2,
    MPMediaTypeAnyAudio     = 0x00ff,
    
    MPMediaTypeAny          = ~0
};
typedef NSInteger MPMediaType;

// An MPMediaItem represents a single piece of media in an MPMediaLibrary.
// Media items have a unique identifier which persists across application launches.

MP_EXTERN_CLASS_AVAILABLE(3_0) @interface MPMediaItem : MPMediaEntity
@end

//-----------------------------------------------------

MP_EXTERN_CLASS_AVAILABLE(3_0) @interface MPMediaItemArtwork : NSObject

// Returns the artwork image for an item at a given size (in points).
- (UIImage *)imageWithSize:(CGSize)size;

@property(nonatomic, readonly) CGRect bounds; // The bounds of the full size image (in points).
@property(nonatomic, readonly) CGRect imageCropRect; // The actual content area of the artwork, in the bounds of the full size image (in points).

@end

// ----------------------------------------------------

// Item properties can be used with -valueForProperty: to fetch metadata about an MPMediaItem.
// Properties marked filterable can also be used to build MPMediaPropertyPredicates (see MPMediaQuery.h).

// Media properties
MP_EXTERN NSString *const MPMediaItemPropertyPersistentID;     // @"persistentID",        NSNumber of uint64_t (unsigned long long),    filterable
MP_EXTERN NSString *const MPMediaItemPropertyMediaType;        // @"mediaType",           NSNumber of MPMediaType (NSInteger),          filterable
MP_EXTERN NSString *const MPMediaItemPropertyTitle;            // @"title",               NSString,                                     filterable
MP_EXTERN NSString *const MPMediaItemPropertyAlbumTitle;       // @"albumTitle",          NSString,                                     filterable
MP_EXTERN NSString *const MPMediaItemPropertyAlbumPersistentID NS_AVAILABLE_IPHONE(4_2);
                                                               // @"albumPID",            NSNumber of uint64_t (unsigned long long),    filterable
MP_EXTERN NSString *const MPMediaItemPropertyArtist;           // @"artist",              NSString,                                     filterable
MP_EXTERN NSString *const MPMediaItemPropertyArtistPersistentID NS_AVAILABLE_IPHONE(4_2);
                                                               // @"artistPID",           NSNumber of uint64_t (unsigned long long),    filterable
MP_EXTERN NSString *const MPMediaItemPropertyAlbumArtist;      // @"albumArtist",         NSString,                                     filterable
MP_EXTERN NSString *const MPMediaItemPropertyAlbumArtistPersistentID NS_AVAILABLE_IPHONE(4_2);
                                                               // @"albumArtistPID",      NSNumber of uint64_t (unsigned long long),    filterable
MP_EXTERN NSString *const MPMediaItemPropertyGenre;            // @"genre",               NSString,                                     filterable
MP_EXTERN NSString *const MPMediaItemPropertyGenrePersistentID NS_AVAILABLE_IPHONE(4_2);
                                                               // @"genrePID",            NSNumber of uint64_t (unsigned long long),    filterable
MP_EXTERN NSString *const MPMediaItemPropertyComposer;         // @"composer",            NSString,                                     filterable
MP_EXTERN NSString *const MPMediaItemPropertyComposerPersistentID NS_AVAILABLE_IPHONE(4_2);
                                                               // @"composerPID",         NSNumber of uint64_t (unsigned long long),    filterable
MP_EXTERN NSString *const MPMediaItemPropertyPlaybackDuration; // @"playbackDuration",    NSNumber of NSTimeInterval (double)
MP_EXTERN NSString *const MPMediaItemPropertyAlbumTrackNumber; // @"albumTrackNumber",    NSNumber of NSUInteger
MP_EXTERN NSString *const MPMediaItemPropertyAlbumTrackCount;  // @"albumTrackCount",     NSNumber of NSUInteger
MP_EXTERN NSString *const MPMediaItemPropertyDiscNumber;       // @"discNumber",          NSNumber of NSUInteger
MP_EXTERN NSString *const MPMediaItemPropertyDiscCount;        // @"discCount",           NSNumber of NSUInteger
MP_EXTERN NSString *const MPMediaItemPropertyArtwork;          // @"artwork",             MPMediaItemArtwork
MP_EXTERN NSString *const MPMediaItemPropertyLyrics;           // @"lyrics",              NSString
MP_EXTERN NSString *const MPMediaItemPropertyIsCompilation;    // @"isCompilation",       NSNumber of BOOL,                             filterable
MP_EXTERN NSString *const MPMediaItemPropertyReleaseDate NS_AVAILABLE_IPHONE(4_0);
                                                               // @"releaseDate",         NSDate
MP_EXTERN NSString *const MPMediaItemPropertyBeatsPerMinute NS_AVAILABLE_IPHONE(4_0);
                                                               // @"beatsPerMinute",      NSNumber of NSUInteger
MP_EXTERN NSString *const MPMediaItemPropertyComments NS_AVAILABLE_IPHONE(4_0);
                                                               // @"comments",            NSString
MP_EXTERN NSString *const MPMediaItemPropertyAssetURL NS_AVAILABLE_IPHONE(4_0);
                                                               // @"assetURL",            NSURL

// Podcast properties
MP_EXTERN NSString *const MPMediaItemPropertyPodcastTitle;     // @"podcastTitle",        NSString,                                     filterable
MP_EXTERN NSString *const MPMediaItemPropertyPodcastPersistentID NS_AVAILABLE_IPHONE(4_2);
                                                               // @"podcastPID",          NSNumber of uint64_t (unsigned long long),    filterable

// User properties
MP_EXTERN NSString *const MPMediaItemPropertyPlayCount;        // @"playCount",           NSNumber of NSUInteger
MP_EXTERN NSString *const MPMediaItemPropertySkipCount;        // @"skipCount",           NSNumber of NSUInteger
MP_EXTERN NSString *const MPMediaItemPropertyRating;           // @"rating",              NSNumber of NSUInteger, 0...5
MP_EXTERN NSString *const MPMediaItemPropertyLastPlayedDate;   // @"lastPlayedDate",      NSDate
MP_EXTERN NSString *const MPMediaItemPropertyUserGrouping NS_AVAILABLE_IPHONE(4_0);
                                                               // @"userGrouping",        NSString
