
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//STM32F103RC 开发板
//LCD显示屏显示函数接口定义
//LCD型号：ST7735S
//亿研电子sz-yy.taobao.com
//日期:2019/5/1
//版本：V1.0
//********************************************************************************

#define HAL_LCD_LINE_1      0x01
#define HAL_LCD_LINE_2      0x02
#define HAL_LCD_LINE_3      0x03
#define HAL_LCD_LINE_4      0x04
#define HAL_LCD_LINE_5      0x05
#define HAL_LCD_LINE_6      0x06
#define HAL_LCD_LINE_7      0x07
#define HAL_LCD_LINE_8      0x08



void Gui_Circle(u16 X,u16 Y,u16 R,u16 fc);    //绘制圆形
void Gui_DrawLine(u16 x0, u16 y0,u16 x1, u16 y1,u16 Color);    //绘制直线
void Gui_box(u16 x, u16 y, u16 w, u16 h,u16 bc);   //绘制实心矩形
void Gui_box2(u16 x,u16 y,u16 w,u16 h, u8 mode);   //绘制特殊效果矩形
void DisplayButtonDown(u16 x1,u16 y1,u16 x2,u16 y2);    //显示按下状态按钮
void DisplayButtonUp(u16 x1,u16 y1,u16 x2,u16 y2);   //显示弹起状态按钮
void Gui_DrawFont_GBK16(u16 x, u16 y, u16 fc, u16 bc, u8 *s);   //显示16点阵中文字体，或者8*16的英文
void Gui_DrawFont_GBK24(u16 x, u16 y, u16 fc, u16 bc, u8 *s);    //显示24点阵中文字体，8x16像素的英文字体
void Gui_DrawFont_Num32(u16 x, u16 y, u16 fc, u16 bc, u16 num) ;   //显示32点阵数字
void LCD_P6x8Str(unsigned char x, unsigned char y, u16 fc, u16 bc,unsigned char ch[]);   //显示6x8英文字符
void Gui_DrawFont_GBK16_line(u8 line, u16 fc, u16 bc, u8 *s);   //显示一行16＊16的汉字，或者8*16的英文


