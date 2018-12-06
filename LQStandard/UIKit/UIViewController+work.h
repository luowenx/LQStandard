//
//  UIViewController+work.h
//  TodaysFootball
//
//  Created by lequwuxian1 on 2018/2/5.
//  Copyright © 2018年 lequwuxian. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (work)

/**
 当前顶层控制器
 */
@property (nonatomic, class, readonly) UIViewController *topViewController_;


/**
 回到某个控制器主页

 @param class 控制器栈root
 */
+(void)popToRootViewCtrl:(Class)class;


/**
 清除栈内某个类别的控制器

 @param class 将被清除的类别
 */
- (void)cleanNavSubClass:(Class)class;

/**
 使自身永远处于第二位
 */
- (void)foreverProson;
- (void)foreverProson:(Class)brotherClass;

@end
