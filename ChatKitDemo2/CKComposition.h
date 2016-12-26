//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

//#import "NSObject.h"

@class IMPluginPayload, NSArray, NSAttributedString, NSString;

@interface CKComposition : NSObject
{
    _Bool _isFromExternalSource;
    NSAttributedString *_text;
    NSAttributedString *_subject;
    IMPluginPayload *_shelfPluginPayload;
    NSString *_expressiveSendStyleID;
}

+ (id)compositionWithShelfPluginPayload:(id)arg1;
+ (id)composition;
+ (id)compositionWithPluginDisplayContainer:(id)arg1 subject:(id)arg2;
+ (id)compositionWithMediaObjects:(id)arg1 subject:(id)arg2;
+ (id)compositionWithMediaObject:(id)arg1 subject:(id)arg2;
+ (id)newExpirableCompositionWithText:(id)arg1 subject:(id)arg2 shelfPluginPayload:(id)arg3;
+ (id)expirableCompositionWithMediaObject:(id)arg1;
+ (id)audioCompositionWithMediaObject:(id)arg1;
+ (id)quickImageCompositionWithMediaObject:(id)arg1;
+ (id)photoPickerCompositionWithMediaObjects:(id)arg1;
+ (id)photoPickerCompositionWithMediaObject:(id)arg1;
+ (id)stickerCompositionWithMediaObjects:(id)arg1;
+ (id)compositionForMessageParts:(id)arg1 preserveSubject:(_Bool)arg2;
+ (id)savedCompositionForGUID:(id)arg1;
+ (void)deleteCompositionWithGUID:(id)arg1;
@property(nonatomic) _Bool isFromExternalSource; // @synthesize isFromExternalSource=_isFromExternalSource;
@property(copy, nonatomic) NSString *expressiveSendStyleID; // @synthesize expressiveSendStyleID=_expressiveSendStyleID;
@property(copy, nonatomic) IMPluginPayload *shelfPluginPayload; // @synthesize shelfPluginPayload=_shelfPluginPayload;
@property(copy, nonatomic) NSAttributedString *subject; // @synthesize subject=_subject;
@property(copy, nonatomic) NSAttributedString *text; // @synthesize text=_text;
//- (void).cxx_destruct;
- (Class)balloonViewClass;
@property(readonly, nonatomic, getter=isSaveable) _Bool saveable;
@property(readonly, nonatomic, getter=isSendAnimated) _Bool sendAnimated;
- (id)compositionByAppendingComposition:(id)arg1;
- (id)compositionByAppendingText:(id)arg1;
- (id)_compositionByAppendingText:(id)arg1 isExpirable:(_Bool)arg2 shelfPluginPayload:(id)arg3;
@property(readonly, copy, nonatomic) NSString *previewText;
@property(readonly, nonatomic) _Bool hasNonwhiteSpaceContent;
@property(readonly, nonatomic) _Bool hasContent;
- (id)initWithText:(id)arg1 subject:(id)arg2;
- (id)initWithText:(id)arg1 subject:(id)arg2 shelfPluginPayload:(id)arg3;
- (unsigned long long)hash;
- (_Bool)isEqual:(id)arg1;
- (id)description;
@property(readonly, nonatomic) NSArray *pasteboardItems;
- (id)compositionByAppendingPluginDisplayContainer:(id)arg1;
@property(readonly, nonatomic, getter=isTextOnly) _Bool textOnly;
@property(readonly, nonatomic) NSArray *mediaObjects;
- (id)compositionByReplacingMediaObject:(id)arg1 withMediaObject:(id)arg2;
- (id)compositionByAppendingMediaObjects:(id)arg1;
- (id)compositionByAppendingMediaObject:(id)arg1;
@property(readonly, nonatomic, getter=isExpirableComposition) _Bool expirableComposition;
- (id)externalSourceComposition;
- (id)messageWithGUID:(id)arg1;
- (id)messageWithGUID:(id)arg1 superFormatText:(id)arg2 superFormatSubject:(id)arg3 fileTransferGUIDs:(id)arg4 mediaObjects:(id)arg5 balloonBundleID:(id)arg6 payloadData:(id)arg7;
- (id)messagesFromCompositionFirstGUIDForMessage:(id)arg1;
- (id)_compositionParts;
- (id)_messageFromPayload:(id)arg1 firstGUID:(id)arg2;
- (id)superFormatText:(id *)arg1;
- (id)superFormatText:(id)arg1 transfterGUIDs:(id *)arg2 mediaObjects:(id *)arg3;
- (id)superFormatSubject;
- (void)saveCompositionWithGUID:(id)arg1;
- (id)compositionWithExpressiveSendStyleID:(id)arg1;

@end

