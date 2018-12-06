//
//  NSString+Time.m
//  TodaysFootball
//
//  Created by lequwuxian1 on 2018/1/26.
//  Copyright © 2018年 lequwuxian. All rights reserved.
//

#define SECONDS_PER_DAY (24*60*60)
#define SECONDS_PER_MONTH (30*24*60*60)
#define SECONDS_PER_YEAR (365*24*60*60)


#import "NSString+Time.h"
#import "NSDate+MC.h"

@implementation NSString (Time)

+(NSString *)stringFormatIntervalSince1970:(double)interval formatString:(NSString *)formatString
{
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:formatString];
    NSString *currentDateStr = [dateFormatter stringFromDate:[NSDate dateWithTimeIntervalSince1970:interval]];
    return  currentDateStr;
}

+ (NSString *)stringFormatIntervalSince1970_YearMonthDayHourMinuteSecond_Line:(double)interval
{
    return [NSString stringFormatIntervalSince1970:interval formatString:@"yyyy-MM-dd HH:mm:ss"];
}

+ (NSString *)stringFormatIntervalSince1970_YearMonthDayHourMinute_Line:(double)interval
{
    return [NSString stringFormatIntervalSince1970:interval formatString:@"yyyy-MM-dd HH:mm"];
}

+ (NSString *)stringFormatIntervalSince1970_MonthDayHourMinute_Slash:(double)interval
{
    return [NSString stringFormatIntervalSince1970:interval formatString:@"MM/dd HH:mm"];
}

+ (NSString *)stringFormatIntervalSince1970_HourMinute_colon:(double)interval
{
    return [NSString stringFormatIntervalSince1970:interval formatString:@"HH:mm"];
}

+ (NSString *)stringFormatIntervalSince1970_MonthDay_Slash:(double)interval
{
    return [NSString stringFormatIntervalSince1970:interval formatString:@"MM/dd"];
}


+ (NSString *)stringIntervalSince1970RuleOne:(double)interval
{
    return [self intervalFromLastDateWithInterval:interval];
}

+ (NSString *)intervalFromLastDateWithInterval:(double)secs
{
    //两个时间的时间差
    NSDate *serDate = [[NSDate alloc] initWithTimeIntervalSince1970:secs];
    NSDate *curDate = NSDate.date;
    double delta = fabs([serDate timeIntervalSinceDate:curDate]);
    
    if (delta < 10 * MINUTE)
    {
        return @"刚刚";
    }
    else if (delta < 60 * MINUTE)
    {
        int minutes = floor((double)delta/MINUTE);
        return [NSString stringWithFormat:(@"%d分钟前"), minutes];
    }
    else if (delta < 24 * HOUR)
    {
        int hours = floor((double)delta/HOUR);
        return [NSString stringWithFormat:(@"%d小时前"), hours];
    }
    else if (delta < 7 * DAY)
    {
        int days = floor((double)delta/DAY);
        return [NSString stringWithFormat:(@"%d天前"), days];
    }
    else if (delta < YEAR)
    {
        return [NSString stringFormatIntervalSince1970:secs formatString:@"MM-dd"];
    }
    
    return [NSString stringFormatIntervalSince1970:secs formatString:@"yyyy-MM"];
}

@end
