//
//  NSString+Time.h
//  TodaysFootball
//
//  Created by lequwuxian1 on 2018/1/26.
//  Copyright © 2018年 lequwuxian. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 时间转换
 */
@interface NSString (Time)
+(NSString *)stringFormatIntervalSince1970:(double)interval formatString:(NSString *)formatString;

//输出格式为：2010-10-27 10:22:59
+ (NSString *)stringFormatIntervalSince1970_YearMonthDayHourMinuteSecond_Line:(double)interval;

//输出格式为：2010-10-27 10:22
+ (NSString *)stringFormatIntervalSince1970_YearMonthDayHourMinute_Line:(double)interval;

// 输出格式为：10/27 10:22
+ (NSString *)stringFormatIntervalSince1970_MonthDayHourMinute_Slash:(double)interval;

// 输出格式为：10:27
+ (NSString *)stringFormatIntervalSince1970_HourMinute_colon:(double)interval;

//输出格式为：10/27
+ (NSString *)stringFormatIntervalSince1970_MonthDay_Slash:(double)interval;

/**
 时间通用规则一
 
 ·发布时间＜10分钟，显示：刚刚
 ·10分钟≤发布时间＜60分钟，以分钟为单位显示
 ·文本格式：[分钟数]分钟前
 ·1小时≤发布时间＜24小时，以小时为单位显示
 ·文本格式：[小时数]小时前
 ·1天≤发布时间＜7天，显示日期
 ·文本格式：[天数]天前
 ·7天≤发布时间＜365天，显示日期
 ·文本格式：[月份]-[日期]
 ·发布时间≥365天，显示月
 ·文本格式：[年份]-[月份]
 
 @param interval 1970时间戳
 */
+ (NSString *)stringIntervalSince1970RuleOne:(double)interval;

@end
