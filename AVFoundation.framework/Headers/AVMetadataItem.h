/*
    File:  AVMetadataItem.h

	Framework:  AVFoundation
 
	Copyright 2010 Apple Inc. All rights reserved.

*/

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>
#import <CoreMedia/CMTime.h>
#import <AVFoundation/AVMetadataFormat.h>
#import <AVFoundation/AVAsynchronousKeyValueLoading.h>

#if TARGET_OS_IPHONE
#import <CoreGraphics/CoreGraphics.h>
#else // ! TARGET_OS_IPHONE
#import <ApplicationServices/../Frameworks/CoreGraphics.framework/Headers/CoreGraphics.h>
#endif // ! TARGET_OS_IPHONE

/*!
    @class			AVMetadataItem

    @abstract		AVMetadataItem represents an item of metadata associated with an audiovisual asset or with
    				one of its tracks.
    
	@discussion		AVMetadataItems have keys that accord with the specification of the container format from
					which they're drawn. Full details of the metadata formats, metadata keys, and metadata keyspaces
					supported by AVFoundation are available among the defines in AVMetadataFormat.h.
	
					Note that arrays of AVMetadataItems vended by AVAsset and other classes are "lazy", similar
					to array-based keys that support key-value observing, meaning that you can obtain
					objects from those arrays without incurring overhead for items you don't ultimately inspect.
					
					You can filter arrays of AVMetadataItems by locale or by key and keySpace via the category
					AVMetadataItemArrayFiltering defined below.
*/

@class AVMetadataItemInternal;

@interface AVMetadataItem : NSObject <
#if !TARGET_OS_IPHONE || 40100 <= __IPHONE_OS_VERSION_MAX_ALLOWED
										AVAsynchronousKeyValueLoading,
#endif // 40100 <= __IPHONE_OS_VERSION_MAX_ALLOWED
										NSCopying, NSMutableCopying>
{
	AVMetadataItemInternal	*_priv;
}

/* indicates the key of the metadata item */
@property (readonly, copy) id<NSObject, NSCopying> key;

/* indicates the common key of the metadata item */
@property (readonly, copy) NSString *commonKey;

/* indicates the keyspace of the metadata item's key; this will typically
   be the default keyspace for the metadata container in which the metadata item is stored */
@property (readonly, copy) NSString *keySpace;

/* indicates the locale of the metadata item; may be nil if no locale information is available for the metadata item */
@property (readonly, copy) NSLocale *locale;

/* indicates the timestamp of the metadata item. */
@property (readonly) CMTime time;

#if 40100 <= __IPHONE_OS_VERSION_MAX_ALLOWED

/* indicates the duration of the metadata item */
@property (readonly) CMTime duration;

#endif // 40100 <= __IPHONE_OS_VERSION_MAX_ALLOWED

/* provides the value of the metadata item */
@property (readonly, copy) id<NSObject, NSCopying> value;

/* provides a dictionary of the additional attributes */
@property (readonly, copy) NSDictionary *extraAttributes;

@end


@interface AVMetadataItem (AVMetadataItemTypeCoercion)

/* provides the value of the metadata item as a string; will be nil if the value cannot be represented as a string */
@property (readonly) NSString *stringValue;

/* provides the value of the metadata item as an NSNumber. If the metadata item's value can't be coerced to a number, @"numberValue" will be nil. */
@property (readonly) NSNumber *numberValue;

/* provides the value of the metadata item as an NSDate. If the metadata item's value can't be coerced to a date, @"dateValue" will be nil. */
@property (readonly) NSDate *dateValue;

/* provides the raw bytes of the value of the metadata item */
@property (readonly) NSData *dataValue;

@end


@interface AVMetadataItem (AVMetadataItemArrayFiltering)

/*!
	@method			metadataItemsFromArray:withLocale:
	@abstract		Filters an array of AVMetadataItems according to locale.
	@param			array
					An array of AVMetadataItems to be filtered by locale.
	@param			locale
					The NSLocale that must be matched for a metadata item to be copied to the output array.
	@result			An instance of NSArray containing the metadata items of the target NSArray that match the specified locale.
*/
+ (NSArray *)metadataItemsFromArray:(NSArray *)array withLocale:(NSLocale *)locale;

/*!
	@method			metadataItemsFromArray:withKey:keySpace:
	@abstract		Filters an array of AVMetadataItems according to key and/or keySpace.
	@param			array
					An array of AVMetadataItems to be filtered by key and/or keyspace.
	@param			key
					The key that must be matched for a metadata item to be copied to the output array.
					Note that to match item keys with any of the common keys, e.g. AVMetadataCommonKeyTitle, it's necessary
					to pass AVMetadataKeySpaceCommon as the keyspace parameter.
					If no filtering according to key is desired, pass nil. 
	@param			keySpace
					The keySpace that must be matched for a metadata item to be copied to the output array.
					If no filtering according to keySpace is desired, pass nil. (See special note above about the use of common keys.)
	@result			An instance of NSArray containing the metadata items of the target NSArray that match the specified
					key and/or keySpace.
*/
+ (NSArray *)metadataItemsFromArray:(NSArray *)array withKey:(id)key keySpace:(NSString *)keySpace;

@end


/*!
    @class			AVMutableMetadataItem

    @abstract		AVMutableMetadataItem provides support for building collections of metadata to be written
    				to asset files via AVAssetExportSession, AVAssetWriter or AVAssetWriterInput.
    
	@discussion		Can be initialized from an existing AVMetadataItem or with a one or more of the basic properties
					of a metadata item: a key, a keySpace, a locale, and a value.
*/

@class AVMutableMetadataItemInternal;

@interface AVMutableMetadataItem : AVMetadataItem
{
	AVMutableMetadataItemInternal	*_mutablePriv;
}

@property (readwrite, copy) id<NSObject, NSCopying> key;

/* indicates the keyspace of the metadata item's key; this will typically
   be the default keyspace for the metadata container in which the metadata item is stored */
@property (readwrite, copy) NSString *keySpace;

/* indicates the locale of the metadata item; may be nil if no locale information is available for the metadata item */
@property (readwrite, copy) NSLocale *locale;

/* indicates the timestamp of the metadata item. */
@property (readwrite) CMTime time;

#if 40100 <= __IPHONE_OS_VERSION_MAX_ALLOWED

/* indicates the duration of the metadata item. */
@property (readwrite) CMTime duration;

#endif // 40100 <= __IPHONE_OS_VERSION_MAX_ALLOWED

/* provides the value of the metadata item */
@property (readwrite, copy) id<NSObject, NSCopying> value;

/* provides a dictionary of the additional attributes */
@property (readwrite, copy) NSDictionary *extraAttributes;

/*!
	@method			metadataItem
	@abstract		Returns an instance of AVMutableMetadataItem.
*/
+ (AVMutableMetadataItem *)metadataItem;

@end

