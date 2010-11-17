/*
    File:  AVMetadataFormat.h

    Framework:  AVFoundation
 
    Copyright 2010 Apple Inc. All rights reserved.

*/

#import <AVFoundation/AVBase.h>
#import <Foundation/Foundation.h>

// CommonMetadata
extern NSString *const AVMetadataKeySpaceCommon                                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

// Metadata common keys
extern NSString *const AVMetadataCommonKeyTitle                                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyCreator                                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeySubject                                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyDescription                                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyPublisher                                  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyContributor                                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyCreationDate                               __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyLastModifiedDate                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyType                                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyFormat                                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyIdentifier                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeySource                                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyLanguage                                   __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyRelation                                   __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyLocation                                   __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyCopyrights                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyAlbumName                                  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyAuthor                                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyArtist                                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyArtwork                                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyMake                                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeyModel                                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataCommonKeySoftware                                   __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

// QuickTimeUserData
extern NSString *const AVMetadataFormatQuickTimeUserData                             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataKeySpaceQuickTimeUserData                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

// QuickTimeUserData keys
extern NSString *const AVMetadataQuickTimeUserDataKeyAlbum                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyArranger                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyArtist                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyAuthor                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyChapter                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyComment                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyComposer                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyCopyright                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyCreationDate                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyDescription                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyDirector                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyDisclaimer                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyEncodedBy                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyFullName                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyGenre                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyHostComputer                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyInformation                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyKeywords                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyMake                            __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyModel                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyOriginalArtist                  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyOriginalFormat                  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyOriginalSource                  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyPerformers                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyProducer                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyPublisher                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyProduct                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeySoftware                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeySpecialPlaybackRequirements     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyTrack                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyWarning                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyWriter                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyURLLink                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyLocationISO6709                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyTrackName                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyCredits                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeUserDataKeyPhonogramRights                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

extern NSString *const AVMetadataISOUserDataKeyCopyright                             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadata3GPUserDataKeyCopyright                             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadata3GPUserDataKeyAuthor                                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadata3GPUserDataKeyPerformer                             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadata3GPUserDataKeyGenre                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadata3GPUserDataKeyRecordingYear                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadata3GPUserDataKeyLocation                              __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadata3GPUserDataKeyTitle                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadata3GPUserDataKeyDescription                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

// QuickTimeMetadata
extern NSString *const AVMetadataFormatQuickTimeMetadata                             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataKeySpaceQuickTimeMetadata                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

// QuickTimeMetadata keys
extern NSString *const AVMetadataQuickTimeMetadataKeyAuthor                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyComment                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyCopyright                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyCreationDate                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyDirector                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyDisplayName                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyInformation                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyKeywords                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyProducer                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyPublisher                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyAlbum                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyArtist                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyArtwork                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyDescription                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeySoftware                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyYear                            __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyGenre                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyiXML                            __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyLocationISO6709                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyMake                            __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyModel                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyArranger                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyEncodedBy                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyOriginalArtist                  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyPerformer                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyComposer                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyCredits                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyPhonogramRights                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyCameraIdentifier                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataQuickTimeMetadataKeyCameraFrameReadoutTime          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

// iTunesMetadata
extern NSString *const AVMetadataFormatiTunesMetadata                                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataKeySpaceiTunes                                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

// iTunesMetadata keys
extern NSString *const AVMetadataiTunesMetadataKeyAlbum                              __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyArtist                             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyUserComment                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyCoverArt                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyCopyright                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyReleaseDate                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyEncodedBy                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyPredefinedGenre                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyUserGenre                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeySongName                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyTrackSubTitle                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyEncodingTool                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyComposer                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyAlbumArtist                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyAccountKind                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyAppleID                            __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyArtistID                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeySongID                             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyDiscCompilation                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyDiscNumber                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyGenreID                            __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyGrouping                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyPlaylistID                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyContentRating                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyBeatsPerMin                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyTrackNumber                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyArtDirector                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyArranger                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyAuthor                             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyLyrics                             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyAcknowledgement                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyConductor                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyDescription                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyDirector                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyEQ                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyLinerNotes                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyRecordCompany                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyOriginalArtist                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyPhonogramRights                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyProducer                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyPerformer                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyPublisher                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeySoundEngineer                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeySoloist                            __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyCredits                            __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyThanks                             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyOnlineExtras                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataiTunesMetadataKeyExecProducer                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

// ID3Metadata
extern NSString *const AVMetadataFormatID3Metadata                                   __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataKeySpaceID3                                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);

// ID3Metadata keys
extern NSString *const AVMetadataID3MetadataKeyAudioEncryption                       /* AENC Audio encryption */                                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyAttachedPicture                       /* APIC Attached picture */                                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyAudioSeekPointIndex                   /* ASPI Audio seek point index */                               __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyComments                              /* COMM Comments */                                             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyCommerical                            /* COMR Commercial frame */                                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyEncryption                            /* ENCR Encryption method registration */                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyEqualization                          /* EQUA Equalization */                                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyEqualization2                         /* EQU2 Equalisation (2) */                                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyEventTimingCodes                      /* ETCO Event timing codes */                                   __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyGeneralEncapsulatedObject             /* GEOB General encapsulated object */                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyGroupIdentifier                       /* GRID Group identification registration */                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyInvolvedPeopleList_v23                /* IPLS Involved people list */                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyLink                                  /* LINK Linked information */                                   __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyMusicCDIdentifier                     /* MCDI Music CD identifier */                                  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyMPEGLocationLookupTable               /* MLLT MPEG location lookup table */                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyOwnership                             /* OWNE Ownership frame */                                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyPrivate                               /* PRIV Private frame */                                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyPlayCounter                           /* PCNT Play counter */                                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyPopularimeter                         /* POPM Popularimeter */                                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyPositionSynchronization               /* POSS Position synchronisation frame */                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyRecommendedBufferSize                 /* RBUF Recommended buffer size */                              __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyRelativeVolumeAdjustment              /* RVAD Relative volume adjustment */                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyRelativeVolumeAdjustment2             /* RVA2 Relative volume adjustment (2) */                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyReverb                                /* RVRB Reverb */                                               __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeySeek                                  /* SEEK Seek frame */                                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeySignature                             /* SIGN Signature frame */                                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeySynchronizedLyric                     /* SYLT Synchronized lyric/text */                              __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeySynchronizedTempoCodes                /* SYTC Synchronized tempo codes */                             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyAlbumTitle                            /* TALB Album/Movie/Show title */                               __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyBeatsPerMinute                        /* TBPM BPM (beats per minute) */                               __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyComposer                              /* TCOM Composer */                                             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyContentType                           /* TCON Content type */                                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyCopyright                             /* TCOP Copyright message */                                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyDate                                  /* TDAT Date */                                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyEncodingTime                          /* TDEN Encoding time */                                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyPlaylistDelay                         /* TDLY Playlist delay */                                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyOriginalReleaseTime                   /* TDOR Original release time */                                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyRecordingTime                         /* TDRC Recording time */                                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyReleaseTime                           /* TDRL Release time */                                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyTaggingTime                           /* TDTG Tagging time */                                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyEncodedBy                             /* TENC Encoded by */                                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyLyricist                              /* TEXT Lyricist/Text writer */                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyFileType                              /* TFLT File type */                                            __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyTime                                  /* TIME Time */                                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyInvolvedPeopleList_v24                /* TIPL Involved people list */                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyContentGroupDescription               /* TIT1 Content group description */                            __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyTitleDescription                      /* TIT2 Title/songname/content description */                   __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeySubTitle                              /* TIT3 Subtitle/Description refinement */                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyInitialKey                            /* TKEY Initial key */                                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyLanguage                              /* TLAN Language(s) */                                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyLength                                /* TLEN Length */                                               __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyMusicianCreditsList                   /* TMCL Musician credits list */                                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyMediaType                             /* TMED Media type */                                           __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyMood                                  /* TMOO Mood */                                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyOriginalAlbumTitle                    /* TOAL Original album/movie/show title */                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyOriginalFilename                      /* TOFN Original filename */                                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyOriginalLyricist                      /* TOLY Original lyricist(s)/text writer(s) */                  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyOriginalArtist                        /* TOPE Original artist(s)/performer(s) */                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyOriginalReleaseYear                   /* TORY Original release year */                                __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyFileOwner                             /* TOWN File owner/licensee */                                  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyLeadPerformer                         /* TPE1 Lead performer(s)/Soloist(s) */                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyBand                                  /* TPE2 Band/orchestra/accompaniment */                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyConductor                             /* TPE3 Conductor/performer refinement */                       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyModifiedBy                            /* TPE4 Interpreted, remixed, or otherwise modified by */       __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyPartOfASet                            /* TPOS Part of a set */                                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyProducedNotice                        /* TPRO Produced notice */                                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyPublisher                             /* TPUB Publisher */                                            __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyTrackNumber                           /* TRCK Track number/Position in set */                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyRecordingDates                        /* TRDA Recording dates */                                      __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyInternetRadioStationName              /* TRSN Internet radio station name */                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyInternetRadioStationOwner             /* TRSO Internet radio station owner */                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeySize                                  /* TSIZ Size */                                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyAlbumSortOrder                        /* TSOA Album sort order */                                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyPerformerSortOrder                    /* TSOP Performer sort order */                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyTitleSortOrder                        /* TSOT Title sort order */                                     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyInternationalStandardRecordingCode    /* TSRC ISRC (international standard recording code) */         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyEncodedWith                           /* TSSE Software/Hardware and settings used for encoding */     __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeySetSubtitle                           /* TSST Set subtitle */                                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyYear                                  /* TYER Year */                                                 __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyUserText                              /* TXXX User defined text information frame */                  __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyUniqueFileIdentifier                  /* UFID Unique file identifier */                               __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyTermsOfUse                            /* USER Terms of use */                                         __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyUnsynchronizedLyric                   /* USLT Unsynchronized lyric/text transcription */              __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyCommercialInformation                 /* WCOM Commercial information */                               __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyCopyrightInformation                  /* WCOP Copyright/Legal information */                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyOfficialAudioFileWebpage              /* WOAF Official audio file webpage */                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyOfficialArtistWebpage                 /* WOAR Official artist/performer webpage */                    __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyOfficialAudioSourceWebpage            /* WOAS Official audio source webpage */                        __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyOfficialInternetRadioStationHomepage  /* WORS Official Internet radio station homepage */             __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyPayment                               /* WPAY Payment */                                              __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyOfficialPublisherWebpage              /* WPUB Publishers official webpage */                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
extern NSString *const AVMetadataID3MetadataKeyUserURL                               /* WXXX User defined URL link frame */                          __OSX_AVAILABLE_STARTING(__MAC_10_7,__IPHONE_4_0);
