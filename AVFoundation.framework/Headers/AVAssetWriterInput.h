/*
	File:  AVAssetWriterInput.h

	Framework:  AVFoundation
 
	Copyright 2010 Apple Inc. All rights reserved.

*/

#if ! TARGET_OS_IPHONE || 40100 <= __IPHONE_OS_VERSION_MAX_ALLOWED

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CMSampleBuffer.h>
#import <CoreVideo/CVPixelBuffer.h>

@class AVAssetWriter;
@class AVAssetWriterInputInternal;

/*!
 @class AVAssetWriterInput
 @abstract
	AVAssetWriterInput defines an interface for appending media samples packaged as CMSampleBuffer objects to a single
	track of the output file of an AVAssetWriter.
 
 @discussion
	Clients that need to write multiple concurrent tracks of media data should use one AVAssetWriterInput instance per
	track. In order to write multiple concurrent tracks with ideal interleaving of media data, clients should observe the
	value returned by the readyForMoreMediaData property of each AVAssetWriterInput instance.
	
	AVAssetWriterInput also supports writing per-track metadata collections to the output file.
 */
@interface AVAssetWriterInput : NSObject
{
@private
	AVAssetWriterInputInternal	*_internal;
}

/*!
 @method assetWriterInputWithMediaType:outputSettings:
 @abstract
	Creates a new input of the specified media type to receive sample buffers for writing to the output file.

 @param mediaType
	The media type of samples that will be accepted by the input. Media types are defined in AVMediaFormat.h.
 @param outputSettings
	The settings used for encoding the media appended to the output.
 @result
	An instance of AVAssetWriterInput.

 @discussion
	Each new input accepts data for a new track of the AVAssetWriter's output file.  Inputs are added to an asset
	writer using -[AVAssetWriter addInput:].
 
	Audio output settings keys are defined in AVAudioSettings.h. AVEncoderAudioQualityKey and
	AVSampleRateConverterAudioQualityKey are not currently supported. Currently an audio settings dictionary must
	be fully-specified, meaning that it must contain AVFormatIDKey, AVSampleRateKey, AVNumberOfChannelsKey, and
	AVChannelLayoutKey.  For kAudioFormatLinearPCM, all relevant AVLinearPCM*Key keys must be included, and for
	other encoders all appropriate AVEncoder*Key keys must be included.
 
	Video output settings keys are defined in AVVideoSettings.h. Video output settings with keys from
	<CoreVideo/CVPixelBuffer.h> are not currently supported. The only value currently supported for
	AVVideoCodecKey is AVVideoCodecH264.

	Passing nil for output settings instructs the input to pass through appended samples, doing no processing
	before they are written to the output file.  This is useful if, for example, you are appending buffers that
	are already in a desirable compressed format.  However, passthrough is currently supported only when writing
	to QuickTime Movie files (i.e. the AVAssetWriter was initialized with AVFileTypeQuickTimeMovie).  For other
	file types, non-nil output settings must be specified.
 */
+ (AVAssetWriterInput *)assetWriterInputWithMediaType:(NSString *)mediaType outputSettings:(NSDictionary *)outputSettings;

/*!
 @method initWithMediaType:outputSettings:
 @abstract
	Creates a new input of the specified media type to receive sample buffers for writing to the output file.

 @param mediaType
	The media type of samples that will be accepted by the input. Media types are defined in AVMediaFormat.h.
 @param outputSettings
	The settings used for encoding the media appended to the output.
 @result
	An instance of AVAssetWriterInput.

 @discussion
	Each new input accepts data for a new track of the AVAssetWriter's output file.  Inputs are added to an asset
	writer using -[AVAssetWriter addInput:].
 
	Audio output settings keys are defined in AVAudioSettings.h. AVEncoderAudioQualityKey and
	AVSampleRateConverterAudioQualityKey are not currently supported. Currently an audio settings dictionary must
	be fully-specified, meaning that it must contain AVFormatIDKey, AVSampleRateKey, AVNumberOfChannelsKey, and
	AVChannelLayoutKey.  For kAudioFormatLinearPCM, all relevant AVLinearPCM*Key keys must be included, and for
	other encoders all appropriate AVEncoder*Key keys must be included.
 
	Video output settings keys are defined in AVVideoSettings.h. Video output settings with keys from
	<CoreVideo/CVPixelBuffer.h> are not currently supported. The only value currently supported for
	AVVideoCodecKey is AVVideoCodecH264.

	Passing nil for output settings instructs the input to pass through appended samples, doing no processing
	before they are written to the output file.  This is useful if, for example, you are appending buffers that
	are already in a desirable compressed format.  However, passthrough is currently supported only when writing
	to QuickTime Movie files (i.e. the AVAssetWriter was initialized with AVFileTypeQuickTimeMovie).  For other
	file types, non-nil output settings must be specified.
 */
- (id)initWithMediaType:(NSString *)mediaType outputSettings:(NSDictionary *)outputSettings;

/*!
 @property mediaType
 @abstract
	The media type of the samples that can be appended to the receiver.
 
 @discussion
	The value of this property is one of the media type strings defined in AVMediaFormat.h.
 */
@property (nonatomic, readonly) NSString *mediaType;

/*!
 @property outputSettings
 @abstract
	The settings used for encoding the media appended to the output.
 
 @discussion
	Audio output settings keys are defined in AVAudioSettings.h. Video output settings keys are defined in AVVideoSettings.h.
*/
@property (nonatomic, readonly) NSDictionary *outputSettings;

/*!
 @property transform
 @abstract
	The transform specified in the output file as the preferred transformation of the visual media data for display purposes.
 
 @discussion
	If no value is specified, the identity transform is used.

	This property cannot be set after writing on the receiver's AVAssetWriter has started.
*/
@property (nonatomic) CGAffineTransform transform;

/*!
 @property metadata
 @abstract
	A collection of metadata to be written to the track corresponding to the receiver. 

 @discussion
	The value of this property is an array of AVMetadataItem objects representing the collection of track-level metadata
    to be written in the output file.

	This property cannot be set after writing on the receiver's AVAssetWriter has started.
 */
@property (nonatomic, copy) NSArray *metadata;

/*!
 @property readyForMoreMediaData
 @abstract
	Indicates the readiness of the input to accept more media data.
 
 @discussion
    When there are multiple inputs, AVAssetWriter tries to write media data in an ideal interleaving pattern for efficiency
    in storage and playback. Each of its inputs signals its readiness to receive media data for writing according to that
    pattern via the value of readyForMoreMediaData. If readyForMoreMediaData is YES, an input can accept additional media
    data while maintaining appropriate interleaving. If media data is appended to an input after readyForMoreMediaData
    becomes NO, AVAssetWriter may need to write media data to its output without regard for ideal interleaving.
 
    Generally, clients should append media data to an input only while its readyForMoreMediaData property is YES.
 
    Clients writing media data from a non-real-time source, such as an instance of AVAssetReader, should hold off on
    generating or obtaining more media data to append to an input when the value of readyForMoreMediaData is NO. To help with
    control of the supply of non-real-time media data, such clients can use -requestMediaDataWhenReadyOnQueue:usingBlock
    in order to specify a block that the input should invoke whenever it's ready for input to be appended.

    Clients writing media data from a real-time source, such as an instance of AVCaptureOutput, should set the input's
    expectsMediaDataInRealTime property to YES to ensure that the value of readyForMoreMediaData is calculated
    appropriately. When expectsMediaDataInRealTime is YES, readyForMoreMediaData will become NO only when the input
    cannot process media samples as quickly as they are being provided by the client. If readyForMoreMediaData becomes NO
    for a real-time source, the client may need to drop samples or consider reducing the data rate of appended samples.
 
    The value of readyForMoreMediaData will often change from NO to YES asynchronously, as previously supplied media data
    is processed and written to the output.  It is possible for all of an AVAssetWriter's AVAssetWriterInputs temporarily to
    return NO for readyForMoreMediaData.
	
    This property is key value observable. Observers should not assume that they will be notified of changes on a
    specific thread.
 */
@property (nonatomic, readonly, getter=isReadyForMoreMediaData) BOOL readyForMoreMediaData;

/*!
 @property expectsMediaDataInRealTime
 @abstract
	Indicates whether the input should tailor its processing of media data for real-time sources.

 @discussion
    Clients appending media data to an input from a real-time source, such as an AVCaptureOutput, should set
    expectsMediaDataInRealTime to YES. This will ensure that readyForMoreMediaData is calculated appropriately for
    real-time usage.

	This property cannot be set after writing on the receiver's AVAssetWriter has started.
 */
@property (nonatomic) BOOL expectsMediaDataInRealTime;

/*!
 @method requestMediaDataWhenReadyOnQueue:usingBlock:
 @abstract
	Instructs the target to invoke a client-supplied block repeatedly, at its convenience, in order to gather media data
	for writing to the output. The block should append media data to the input either until the input's readyForMoreMediaData
	property becomes NO or until there is no more media data to supply (at which point it may choose to mark the input as finished
	via -markAsFinished). The block should then exit. After the block exits, if the input has not been marked as finished, once
	the input has processed the media data it has received and becomes ready for more media data again, it will invoke the block
	again in order to obtain more.

 @param queue
	The queue on which the block should be invoked.
 @param block
	The block the input should invoke to obtain media data.

 @discussion
    A typical use of this method, with a block that supplies media data to an input while respecting the input's readyForMoreMediaData
    property, might look like this:

    [myAVAssetWriterInput requestMediaDataWhenReadyOnQueue:myInputSerialQueue usingBlock:^{
        while ([myAVAssetWriterInput isReadyForMoreMediaData])
        {
            CMSampleBufferRef nextSampleBuffer = [self copyNextSampleBufferToWrite];
            if (nextSampleBuffer)
            {
                [myAVAssetWriterInput appendSampleBuffer:nextSampleBuffer];
                CFRelease(nextSampleBuffer);
            }
            else
            {
                [myAVAssetWriterInput markAsFinished];
                break;
            }
        }
    }];
 
	This method is not recommended for use with a push-style buffer source, such as AVCaptureAudioDataOutput or
	AVCaptureVideoDataOutput, because such a combination will likely require intermediate queueing of buffers.  Instead, this
	method is better suited to a pull-style buffer source such as AVAssetReaderOutput, as illustrated in the above example.
 
	When using a push-style buffer source, it is generally better to immediately append each buffer to the AVAssetWriterInput,
	directly via -[AVAssetWriter appendSampleBuffer:], as it is received.  Using this strategy, it is often possible to avoid 
	having to queue up buffers in between the buffer source and the AVAssetWriterInput.  Note that many of these push-style
	buffer sources also produce buffers in real-time, in which case the client should set expectsMediaDataInRealTime to YES.
 */
- (void)requestMediaDataWhenReadyOnQueue:(dispatch_queue_t)queue usingBlock:(void (^)(void))block;

/*!
 @method appendSampleBuffer:
 @abstract
	Appends samples to the receiver.

 @param sampleBuffer
	The CMSampleBuffer to be appended.
 @result
	A BOOL value indicating success of appending the sample buffer. If a result of NO is returned, clients may wish to
	invoke -[AVAssetWriter finishWriting] in order to save a partially completed asset.
 
 @discussion
	The timing information in the sample buffer, considered relative to the time passed to
	-[AVAssetWriter startSessionAtSourceTime:], will be used to determine the timing of those samples in the output file.
 
	The receiver will retain the CMSampleBuffer until it is done with it, and then release it.  Do not modify a
	CMSampleBuffer or its contents after you have passed it to this method.
	
	If the sample buffer contains a CVPixelBuffer then for optimal performance the format of the pixel buffer should match
	one of the native formats supported by the selected video encoder. The H.264 encoder natively supports 
	kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange and kCVPixelFormatType_420YpCbCr8BiPlanarFullRange, which should be 
	used with video and full range input respectively. Pixel buffers not in either of these formats will be converted 
	internally prior to encoding.
 
	Audio buffers passed into appendSampleBuffer: currently must be in linear PCM format.
 */
- (BOOL)appendSampleBuffer:(CMSampleBufferRef)sampleBuffer;

/*!
 @method markAsFinished
 @abstract
	Indicates to the AVAssetWriter that no more buffers will be appended to this input.

 @discussion
	Clients that are monitoring each input's readyForMoreMediaData value must call markAsFinished on an input when they are
	done appending buffers to it.  This is necessary to prevent other inputs from stalling, as they may otherwise wait
	forever for that input's media data, attempting to complete the ideal interleaving pattern.
 */
- (void)markAsFinished;

@end


@class AVAssetWriterInputPixelBufferAdaptorInternal;

/*!
 @class AVAssetWriterInputPixelBufferAdaptor
 @abstract
	Defines an interface for appending video samples packaged as CVPixelBuffer objects to a single
	AVAssetWriterInput object.
 
 @discussion
	Instances of AVAssetWriterInputPixelBufferAdaptor provide a CVPixelBufferPool that can be used to
	allocate pixel buffers for writing to the output file.  Using the provided pixel buffer pool for buffer
	allocation is typically more efficient than appending pixel buffers allocated using a separate pool.
 */
@interface AVAssetWriterInputPixelBufferAdaptor : NSObject
{
@private
	AVAssetWriterInputPixelBufferAdaptorInternal	*_internal;
}

/*!
 @method assetWriterInputPixelBufferAdaptorWithAssetWriterInput:sourcePixelBufferAttributes:
 @abstract
	Creates a new pixel buffer adaptor to receive pixel buffers for writing to the output file.

 @param input
	An instance of AVAssetWriterInput to which the receiver should append pixel buffers.  Currently, only
	asset writer inputs that accept media data of type AVMediaTypeVideo can be used to initialize a pixel buffer
	adaptor.
 @param sourcePixelBufferAttributes
	Specifies the attributes of pixel buffers that will be vended by the input's CVPixelBufferPool.
 @result
	An instance of AVAssetWriterInputPixelBufferAdaptor.

 @discussion
	In order to take advantage of the improved efficiency of appending buffers created from the adaptor's pixel buffer
	pool, clients should specify pixel buffer attributes that most closely accommodate the source format of the video
	frames being appended.

	Pixel buffer attributes keys for the pixel buffer pool are defined in <CoreVideo/CVPixelBuffer.h>. To specify the
	pixel format type, the pixelBufferAttributes dictionary should contain a value for kCVPixelBufferPixelFormatTypeKey.
	For example, use [NSNumber numberWithInt:kCVPixelFormatType_32BGRA] for 8-bit-per-channel BGRA, or use
	[NSNumber numberWithInt:kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange] for 2-plane YCbCr.

	Clients that do not need a pixel buffer pool for allocating buffers should set sourcePixelBufferAttributes to nil.
	
	It is an error to initialize an instance of AVAssetWriterInputPixelBufferAdaptor with a sample buffer
	input that is already attached to another instance of AVAssetWriterInputPixelBufferAdaptor.
 */
+ (AVAssetWriterInputPixelBufferAdaptor *)assetWriterInputPixelBufferAdaptorWithAssetWriterInput:(AVAssetWriterInput *)input sourcePixelBufferAttributes:(NSDictionary *)sourcePixelBufferAttributes;

/*!
 @method initWithAssetWriterInput:sourcePixelBufferAttributes:
 @abstract
	Creates a new pixel buffer adaptor to receive pixel buffers for writing to the output file.

 @param input
	An instance of AVAssetWriterInput to which the receiver should append pixel buffers.  Currently, only
	asset writer inputs that accept media data of type AVMediaTypeVideo can be used to initialize a pixel buffer
	adaptor.
 @param sourcePixelBufferAttributes
	Specifies the attributes of pixel buffers that will be vended by the input's CVPixelBufferPool.
 @result
	An instance of AVAssetWriterInputPixelBufferAdaptor.

 @discussion
	In order to take advantage of the improved efficiency of appending buffers created from the adaptor's pixel buffer
	pool, clients should specify pixel buffer attributes that most closely accommodate the source format of the video
	frames being appended.

	Pixel buffer attributes keys for the pixel buffer pool are defined in <CoreVideo/CVPixelBuffer.h>. To specify the
	pixel format type, the pixelBufferAttributes dictionary should contain a value for kCVPixelBufferPixelFormatTypeKey.
	For example, use [NSNumber numberWithInt:kCVPixelFormatType_32BGRA] for 8-bit-per-channel BGRA, or use
	[NSNumber numberWithInt:kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange] for 2-plane YCbCr.

	Clients that do not need a pixel buffer pool for allocating buffers should set sourcePixelBufferAttributes to nil.
	
	It is an error to initialize an instance of AVAssetWriterInputPixelBufferAdaptor with an asset writer input that
	is already attached to another instance of AVAssetWriterInputPixelBufferAdaptor.  It is also an error to initialize
	an instance of AVAssetWriterInputPixelBufferAdaptor with an asset writer input whose asset writer has progressed
	beyond AVAssetWriterStatusUnknown.
 */
- (id)initWithAssetWriterInput:(AVAssetWriterInput *)input sourcePixelBufferAttributes:(NSDictionary *)sourcePixelBufferAttributes;

/*!
 @property assetWriterInput
 @abstract
	The asset writer input to which the receiver should append pixel buffers.
 */
@property (nonatomic, readonly) AVAssetWriterInput *assetWriterInput;

/*!
 @property sourcePixelBufferAttributes
 @abstract
	The pixel buffer attributes of pixel buffers that will be vended by the receiver's CVPixelBufferPool.

 @discussion
	The value of this property is a dictionary containing pixel buffer attributes keys defined in
	<CoreVideo/CVPixelBuffer.h>.
 */
@property (nonatomic, readonly) NSDictionary *sourcePixelBufferAttributes;

/*!
 @property pixelBufferPool
 @abstract
	A pixel buffer pool that will vend and efficiently recycle CVPixelBuffer objects that can be appended to the receiver.

 @discussion
	For maximum efficiency, clients should create CVPixelBuffer objects for appendPixelBuffer:withPresentationTime: by
	using this pool with the CVPixelBufferPoolCreatePixelBuffer() function.
	
	The value of this property will be NULL before -[AVAssetWriter startWriting] is called on the associated
	AVAssetWriter object.
	
	This property is key value observable.
 */
@property (nonatomic, readonly) CVPixelBufferPoolRef pixelBufferPool;

/*!
 @method appendPixelBuffer:withPresentationTime:
 @abstract
	Appends a pixel buffer to the receiver.

 @param pixelBuffer
	The CVPixelBuffer to be appended.
 @param presentationTime
	The presentation time for the pixel buffer to be appended.  This time will be considered relative to the time passed
	to -[AVAssetWriter startSessionAtSourceTime:] to determine the timing of the frame in the output file.
 @result
	A BOOL value indicating success of appending the pixel buffer. If a result of NO is returned, clients may wish to
	invoke -[AVAssetWriter finishWriting] in order to save a partially completed asset.

 @discussion
	The receiver will retain the CVPixelBuffer until it is done with it, and then release it.  Do not modify a
	CVPixelBuffer or its contents after you have passed it to this method.
	
	For optimal performance the format of the pixel buffer should match one of the native formats supported by the
	selected video encoder. The H.264 encoder natively supports kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange and
	kCVPixelFormatType_420YpCbCr8BiPlanarFullRange, which should be used with video and full range input respectively.
	Pixel buffers not in either of these formats will be converted internally prior to encoding.
 */
- (BOOL)appendPixelBuffer:(CVPixelBufferRef)pixelBuffer withPresentationTime:(CMTime)presentationTime;

@end

#endif // ! TARGET_OS_IPHONE || 40100 <= __IPHONE_OS_VERSION_MAX_ALLOWED
