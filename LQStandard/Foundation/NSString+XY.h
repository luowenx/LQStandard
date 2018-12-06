//
//  NSString+XY.h
//  JoinShow
//
//  Created by Heaven on 13-10-16.
//  Copyright (c) 2013年 Heaven. All rights reserved.
//  Copy from bee Framework

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define stringNotNil(str) (str ? [NSString stringWithFormat:@"%@",str] : @"")

#pragma mark -

typedef NSString *			(^NSStringAppendBlock)( id format, ... );
typedef NSString *			(^NSStringReplaceBlock)( NSString * string, NSString * string2 );

typedef NSMutableString *	(^NSMutableStringAppendBlock)( id format, ... );
typedef NSMutableString *	(^NSMutableStringReplaceBlock)( NSString * string, NSString * string2 );

#pragma mark -

@interface NSString (XY)

@property (nonatomic, readonly, copy  ) NSStringAppendBlock  APPEND;
@property (nonatomic, readonly, copy  ) NSStringAppendBlock  LINE;
@property (nonatomic, readonly, copy  ) NSStringReplaceBlock REPLACE;

//@property (nonatomic, readonly, copy  ) NSString             *MD5;
//@property (nonatomic, readonly, strong) NSData               *MD5Data;

@property (nonatomic, readonly, strong) NSData               *data;
@property (nonatomic, readonly, strong) NSDate               *date;

@property (nonatomic, readonly, copy  ) NSString             *SHA1;

//计算md5
- (NSString *)stringMD5; //使用MD5 方法

- (BOOL)empty;
- (BOOL)notEmpty;

- (BOOL)eq:(NSString *)other;
- (BOOL)equal:(NSString *)other;

- (BOOL)is:(NSString *)other;
- (BOOL)isNot:(NSString *)other;

// 是否在array里, caseInsens 区分大小写
- (BOOL)isValueOf:(NSArray *)array;
- (BOOL)isValueOf:(NSArray *)array caseInsens:(BOOL)caseInsens;

#pragma mark - bee里的检测
- (BOOL)isNormal;
- (BOOL)isTelephone;
- (BOOL)isUserName;
- (BOOL)isChineseUserName;
- (BOOL)isPassword;
- (BOOL)isEmail;
- (BOOL)isUrl;
- (BOOL)isIPAddress;

#pragma mark - 额外的检测
// 包含一个字符和数字
- (BOOL)isHasCharacterAndNumber;
// 昵称
- (BOOL)isNickname;
- (BOOL)isTelephone2;

- (NSString *)substringUnicodeLength:(NSUInteger)length;
- (NSString *)substringFromIndex:(NSUInteger)from untilCharset:(NSCharacterSet *)charset;
- (NSString *)substringFromIndex:(NSUInteger)from untilCharset:(NSCharacterSet *)charset endOffset:(NSUInteger *)endOffset;

#if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)
- (CGSize)sizeWithFont:(UIFont *)font byWidth:(CGFloat)width;
- (CGSize)sizeWithFont:(UIFont *)font byHeight:(CGFloat)height;
#endif	// #if (TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR)

+ (NSString *)fromResource:(NSString *)resName;

// 中英文混排，获取字符串长度
- (NSInteger)getLength;
- (NSInteger)getLength2;

// Unicode格式的字符串编码转成中文的方法(如\u7E8C)转换成中文,unicode编码以\u开头
- (NSString *)replaceUnicode;

/**
 * 擦除保存的值, 建议敏感信息在不用的是调用此方法擦除.
 * 如果是这样 _text = @"information"的 被分配到data区的无法擦除
 */
- (void)erasure;

// 大写字母 (International Business Machines 变成 IBM)
- (NSString*)stringByInitials;

// 返回显示字串所需要的尺寸
- (CGSize)calculateSize:(CGSize)size font:(UIFont *)font;
- (CGSize)calculateSize:(CGSize)size font:(UIFont *)font lineBreak:(NSLineBreakMode)breakMode;

- (NSTimeInterval)displayTime;

/*
 * 设置字符串中一部分文本的 富文本
 *
 * @param defaultColor 普通文本颜色
 * @param defaultFont 普通文本字体
 * @param attrString 被改变 字符串
 * @param attrColor 被改变 字符串颜色
 * @param attrFont 被改变 字符串字体
 *
 */
- (NSMutableAttributedString *)getAttributedWithColor:(UIColor *)defaultColor
                                          defaultFont:(UIFont *)defaultFont
                                           attrString:(NSString *)attrString
                                            attrColor:(UIColor *)attrColor
                                             attrFont:(UIFont *)attrFont;

@end


#pragma mark -

@interface NSMutableString(BeeExtension)

@property (nonatomic, readonly, copy) NSMutableStringAppendBlock	APPEND;
@property (nonatomic, readonly, copy) NSMutableStringAppendBlock	LINE;
@property (nonatomic, readonly, copy) NSMutableStringReplaceBlock	REPLACE;

@end

