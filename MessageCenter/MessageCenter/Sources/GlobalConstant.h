//
//  FMWebKitConstant.h
//  H5Container
//
//  Created by 谈Xx on 15/12/2.
//  Copyright © 2015年 谈Xx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


#pragma mark - ================  Frame ================
//状态栏高度
#define kStatusBarHeight [UIApplication sharedApplication].statusBarFrame.size.height
//导航栏高度
#define kNavBarHeight 44.0f
#define kTitleHeight kNavBarHeight + kStatusBarHeight
//tabbar高度
#define kTabBarHeight ([[UIApplication sharedApplication] statusBarFrame].size.height>20.0f?83.0f:49.0f)

//屏幕比例
#define wflag ([UIScreen mainScreen].bounds.size.width / 375.0f)
#define hflag ([UIScreen mainScreen].bounds.size.height / 667.0f)
#define kStretch(x) (wflag * x)

//是否是iPhoneX
#define iPhoneX \
({BOOL isPhoneX = NO;\
if (@available(iOS 11.0, *)) {\
isPhoneX = [UIApplication sharedApplication].keyWindow.safeAreaInsets.bottom > 0.0;\
}\
(isPhoneX);})

//#define iPhoneX ([UIScreen mainScreen].bounds.size.height == 812.0f || [UIScreen mainScreen].bounds.size.height == 896.0f)

//X与其他屏幕的导航栏高度差
#define isIphoneXNavBarMargin (iPhoneX?24.0f:0.0f)
//X与其他屏幕的底部tabbar高度差
#define isIphoneXTabBarMargin (iPhoneX?34.0f:0.0f)

#define SCREENWIDTH_CQ ([UIScreen mainScreen].bounds.size.width)
#define SCREENHEIGHT_CQ ([UIScreen mainScreen].bounds.size.height)
#define screenScale ([UIScreen mainScreen].scale)
#define Base_Height ([[UIScreen mainScreen] bounds].size.height >= 812.0 ? 812.0 : 667.0)
#define Screen_Ratio_Width (SCREENWIDTH_CQ / 375.0)
#define Screen_Ratio_Height (SCREENHEIGHT_CQ / Base_Height)
#define SeparatorLineHeight (1.0 / [UIScreen mainScreen].scale)

#define ComponentCGRect CGRectMake(0, 0, SCREENWIDTH_CQ, self.contentView.height)

#pragma mark - ================  Font ================
//  字体
#define MYFONT(a)    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)?[UIFont fontWithName:@"PingFang-SC-Regular" size:a]:[UIFont systemFontOfSize:a]
//  粗体
#define MYBOLD(a)   ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)?[UIFont fontWithName:@"FontWeightStyleSemibold" size:a]:[UIFont boldSystemFontOfSize:a]

#pragma mark - ================  Color ================
#define COLOR_RGB(R,G,B)     [UIColor colorWithRed:(R)/255.0f green:(G)/255.0f blue:(B)/255.0f alpha:1]
#define COLOR_RGBA(R,G,B,A)  [UIColor colorWithRed:(R)/255.0f green:(G)/255.0f blue:(B)/255.0f alpha:(A)]
#define YNETCell_LineBGColor            COLOR_RGB(230, 230, 230)

#pragma mark - ================  Debug ================
// 打印调试信息
#ifdef DEBUG
#define YNETLog(format, ...) printf("class: <%p %s:(%d) > method: %s \n%s\n", self, [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __PRETTY_FUNCTION__, [[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String] )
#else
#define YNETLog(format, ...)
#endif

#pragma mark - ================  Device ================
#define kIOS8_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
#define kIOS9_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)
#define kIOS10_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >= 10.0)
#define kIOS11_OR_LATER @available(iOS 11.0, *)

#pragma mark - ================  Nil ================
//字符串是否为空
#define kStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
//数组是否为空
#define kArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
//字典是否为空
#define kDictIsEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys.count == 0)
//是否是空对象
#define kObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))
//如果为空对象，返回@""
#define kCheckNil(value)\
({id tmp;\
if ([(value) isKindOfClass:[NSNull class]] || \
[[NSString stringWithFormat:@"%@",value] isEqualToString:@"(null)"] || \
[[NSString stringWithFormat:@"%@",value] isEqualToString:@"(NULL)"] || \
[[NSString stringWithFormat:@"%@",value] isEqualToString:@"null"] || \
[[NSString stringWithFormat:@"%@",value] isEqualToString:@"<null>"] || \
[[NSString stringWithFormat:@"%@",value] isEqualToString:@"NULL"]) \
{tmp = @"";}\
else\
{tmp = (value?value:@"");}\
tmp;\
})\

@interface GlobalConstant : NSObject

@end
