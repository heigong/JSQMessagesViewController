//
//  Created by Jesse Squires
//  http://www.hexedbits.com
//
//
//  Documentation
//  http://cocoadocs.org/docsets/JSMessagesViewController
//
//
//  The MIT License
//  Copyright (c) 2014 Jesse Squires
//  http://opensource.org/licenses/MIT
//

#import <UIKit/UIKit.h>

#import "JSQMessagesCollectionView.h"
#import "JSQMessagesCollectionViewFlowLayout.h"
#import "JSQMessagesCollectionViewCellIncoming.h"
#import "JSQMessagesCollectionViewCellOutgoing.h"

#import "JSQMessagesToolbarContentView.h"
#import "JSQMessagesInputToolbar.h"
#import "JSQMessagesComposerTextView.h"

#import "JSQMessageData.h"
#import "JSQMessage.h"

#import "JSQMessagesAvatarFactory.h"
#import "JSQMessagesBubbleImageFactory.h"
#import "JSQMessagesToolbarButtonFactory.h"

#import "JSQSystemSoundPlayer+JSQMessages.h"
#import "NSString+JSQMessages.h"
#import "UIColor+JSQMessages.h"
#import "UIImage+JSQMessages.h"
#import "UIView+JSQMessages.h"

@class JSQMessagesViewController;


@protocol JSQMessagesViewControllerDelegate <NSObject>

@required
- (void)messagesViewController:(JSQMessagesViewController *)viewController
                didSendMessage:(JSQMessage *)message;

- (void)messagesViewController:(JSQMessagesViewController *)viewController
       didPressAccessoryButton:(UIButton *)sender;

@end



@interface JSQMessagesViewController : UIViewController <JSQMessagesCollectionViewDataSource,
                                                         UICollectionViewDelegateFlowLayout>

@property (weak, nonatomic) id<JSQMessagesViewControllerDelegate> delegate;

@property (weak, nonatomic, readonly) JSQMessagesCollectionView *collectionView;

@property (weak, nonatomic, readonly) JSQMessagesInputToolbar *inputToolbar;

/**
 *  The name of the user sending messages. The default value is `@"JSQDefaultSender"`.
 */
@property (copy, nonatomic) NSString *sender;

@property (assign, nonatomic) BOOL autoScrollsToMostRecentMessage;

@property (copy, nonatomic) NSString *outgoingCellIdentifier;

@property (copy, nonatomic) NSString *incomingCellIdentifier;

#pragma mark - Class methods

+ (UINib *)nib;

+ (instancetype)messagesViewController;

#pragma mark - Messages view controller

- (void)finishSending;

- (void)scrollToBottomAnimated:(BOOL)animated;

@end
