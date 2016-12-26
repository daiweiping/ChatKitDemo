//
//  ViewController.m
//  ChatKitDemo2
//
//  Created by MIMO on 2016/12/26.
//  Copyright © 2016年 戴尼玛. All rights reserved.
//

#import "ViewController.h"
#import <objc/message.h>
#import <dlfcn.h>
#import "CKDBMessage.h"
#import "CKConversation.h"
#import "CKConversationList.h"
#import "CKComposition.h"
#import "CTMessageCenter.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self sendingMessageWithRecordID];
    //[self sendingMessageIniOS8];
    //[self sendingMessagesThroughCTMessageCenter];
}

-(void)sendingMessageWithRecordID{
    static int (*IMDMessageRecordGetMessagesSequenceNumber)();
    void *libHandleIMD = dlopen("/System/Library/PrivateFrameworks/IMDPersistence.framework/IMDPersistence", RTLD_LAZY);
    IMDMessageRecordGetMessagesSequenceNumber = (int (*)())dlsym(libHandleIMD, "IMDMessageRecordGetMessagesSequenceNumber");
    int lastID = IMDMessageRecordGetMessagesSequenceNumber();
    
    dlopen("/System/Library/PrivateFrameworks/ChatKit.framework/ChatKit", RTLD_LAZY);
    Class CKDBMessageClass = NSClassFromString(@"CKDBMessage");
    CKDBMessage *msg = [[CKDBMessageClass alloc] initWithRecordID:lastID];
    NSLog(@"address: %@", msg.address);
    NSLog(@"plainBody: %@", msg.plainBody);
    
    Class CKConversationClass = NSClassFromString(@"CKConversation");
    //CKConversation *conversation = [CKConversationClass newPendingConversation];
    CKConversation *conversation = [CKConversationClass conversationForAddresses:@[msg.address] allowRetargeting:NO candidateConversation:nil];
    NSLog(@"conversation is >> %@",conversation);       //会话创建成功
    
    Class CKCompositionClass = NSClassFromString(@"CKComposition");
    NSAttributedString* text = [[NSAttributedString alloc] initWithString:@"testing"];
    NSAttributedString* subject = [[NSAttributedString alloc] initWithString:@"hello"];
    CKComposition* composition = [[CKCompositionClass alloc] initWithText:text subject:subject];
    NSLog(@"composition is >> %@",composition);
    NSLog(@"canSendComposition is >> %d",[conversation canSendComposition:composition error:nil]);      //检测该消息可发送
    id message = [conversation messageWithComposition:composition];
    [conversation sendMessage:message newComposition:YES];
    
    UILabel *textLabel = [[UILabel alloc] initWithFrame:self.view.frame];
    textLabel.textAlignment = NSTextAlignmentCenter;
    textLabel.numberOfLines = 0;
    NSString *str = [NSString stringWithFormat:@"您有一条新消息，%@：%@",msg.address,msg.plainBody];
    textLabel.text = str;
    [self.view addSubview:textLabel];
}

-(void)sendingMessageIniOS8{
    dlopen("/System/Library/PrivateFrameworks/ChatKit.framework/ChatKit", RTLD_LAZY);
    
    Class CKConversationListClass = NSClassFromString(@"CKConversationList");
    CKConversationList* conversationList = [CKConversationListClass sharedConversationList];
    NSLog(@"conversationList is >> %@",conversationList);
    
    CKConversation *conversation = [conversationList conversationForExistingChatWithGroupID:@"+8613537727339"];
    NSLog(@"conversation is >> %@",conversation);
    
    Class CKCompositionClass = NSClassFromString(@"CKComposition");
    NSAttributedString* text = [[NSAttributedString alloc] initWithString:@"hello"];
    CKComposition* composition = [[CKCompositionClass alloc] initWithText:text subject:nil];
    NSLog(@"composition is >> %@",composition);
    
    id message = [conversation messageWithComposition:composition];
    [conversation sendMessage:message newComposition:YES];
}

-(void)sendingMessagesThroughCTMessageCenter{
    dlopen("/System/Library/Frameworks/CoreTelephony.framework/CoreTelephony", RTLD_LAZY);
    Class CTMessageCenterClass = NSClassFromString(@"CTMessageCenter");
    CTMessageCenter *messageCenter = [CTMessageCenterClass sharedMessageCenter];
    NSLog(@"messageCenter is >> %@",messageCenter);
    BOOL success = [messageCenter sendSMSWithText:@"Hello!" serviceCenter:nil toAddress:@"+8613537727339"];
    NSLog(@"success is >> %d",success);
}

@end
