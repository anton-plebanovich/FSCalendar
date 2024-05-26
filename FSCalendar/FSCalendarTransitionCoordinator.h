//
//  FSCalendarTransitionCoordinator.h
//  FSCalendar
//
//  Created by dingwenchao on 3/13/16.
//  Copyright © 2016 Wenchao Ding. All rights reserved.
//

#import "FSCalendar.h"
#import "FSCalendarCollectionView.h"
#import "FSCalendarCollectionViewLayout.h"

typedef NS_ENUM(NSUInteger, FSCalendarTransitionState) {
    FSCalendarTransitionStateIdle,
    FSCalendarTransitionStateChanging,
    FSCalendarTransitionStateFinishing,
};

@class FSCalendarTransitionAttributes;

@interface FSCalendarTransitionCoordinator : NSObject <UIGestureRecognizerDelegate>

@property (assign, nonatomic) FSCalendarTransitionState state;

@property (assign, nonatomic) CGSize cachedMonthSize;

@property (readonly, nonatomic) FSCalendarScope representingScope;

@property (nullable, strong, nonatomic) FSCalendarTransitionAttributes *transitionAttributes;

- (instancetype _Nonnull)initWithCalendar:(FSCalendar *_Nonnull)calendar;

- (void)performScopeTransitionFromScope:(FSCalendarScope)fromScope toScope:(FSCalendarScope)toScope animated:(BOOL)animated;
- (void)performBoundingRectTransitionFromMonth:(NSDate *_Nullable)fromMonth toMonth:(NSDate *_Nonnull)toMonth duration:(CGFloat)duration;
- (CGRect)boundingRectForScope:(FSCalendarScope)scope page:(NSDate *_Nonnull)page;

- (void)handleScopeGesture:(id _Nonnull)sender;
- (void)scopeTransitionDidBegin:(UIPanGestureRecognizer *_Nonnull)panGesture;
- (void)scopeTransitionDidUpdate:(UIPanGestureRecognizer *_Nonnull)panGesture;
- (void)scopeTransitionDidEnd:(UIPanGestureRecognizer *_Nonnull)panGesture;

@end

@interface FSCalendarTransitionAttributes : NSObject

@property (assign, nonatomic) CGRect sourceBounds;
@property (assign, nonatomic) CGRect targetBounds;
@property (strong, nonatomic, nullable) NSDate *sourcePage;
@property (strong, nonatomic, nullable) NSDate *targetPage;
@property (assign, nonatomic) NSInteger focusedRow;
@property (strong, nonatomic, nullable) NSDate *focusedDate;
@property (assign, nonatomic) FSCalendarScope targetScope;

- (void)revert;

@end
