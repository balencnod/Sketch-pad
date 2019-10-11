#include <graphics.h>
#include <stdio.h> 
#include "UI.h"

//开始过场动画。
void CG_op()
{
	setfont(40, 0, "华文行楷");
	setcolor(BLACK);
	xyprintf(550, 400, "Welcome to use this sketch pad is ERROR");
	delay_ms(800);
	cleardevice();
	xyprintf(540, 400, "Welcome to use this sketch pad is ERROR .");
	delay_ms(800);
	cleardevice();
	xyprintf(530, 400, "Welcome to use this sketch pad is ERROR ..");
	delay_ms(800);
	cleardevice();
	xyprintf(520, 400, "Welcome to use this sketch pad is ERROR ...");
	delay_ms(800);
	cleardevice();
	xyprintf(590, 400, "Made by Co_BELAN");
	delay_ms(2000);
	cleardevice();
	setfont(20, 0, "宋体");
}

//读取时动画。
void CG_load()
{
	setfont(40, 0, "华文行楷");
	setcolor(BLACK);
	cleardevice();
	xyprintf(700, 300, "Loading.");
	delay_ms(500);
	cleardevice();
	xyprintf(690, 300, "Loading..");
	delay_ms(500);
	cleardevice();
	xyprintf(680, 300, "Loading...");
	delay_ms(500);
	cleardevice();
	xyprintf(650, 300, "Loaded Success !");
	delay_ms(1000); 
	cleardevice();
	setfont(20, 0, "宋体");
}

//未读取动画。
void CG_unload()
{
	setfont(40, 0, "华文行楷");
	setcolor(BLACK);
	cleardevice();
	xyprintf(700, 300, "Creating.");
	delay_ms(500);
	cleardevice();
	xyprintf(690, 300, "Creating..");
	delay_ms(500);
	cleardevice();
	xyprintf(680, 300, "Creating...");
	delay_ms(500);
	cleardevice();
	xyprintf(650, 300, "Created Success !");
	delay_ms(1000);
	cleardevice();
	setfont(20, 0, "宋体");
}

//结束保存动画
void CG_edsave()
{
	setfont(40, 0, "华文行楷");
	setcolor(BLACK);
	cleardevice();
	xyprintf(700, 300, "Saving.");
	delay_ms(500);
	cleardevice();
	xyprintf(690, 300, "Saving..");
	delay_ms(500);
	cleardevice();
	xyprintf(680, 300, "Saving...");
	delay_ms(500);
	cleardevice();
	xyprintf(650, 300, "Saved Success !");
	delay_ms(1000);
	cleardevice();
	setfont(20, 0, "宋体");
}

//结束未保存动画
void CG_edunsave()
{
	setfont(40, 0, "华文行楷");
	setcolor(BLACK);
	cleardevice();
	xyprintf(530, 300, "The project has not been saved !");
	delay_ms(2000);
	cleardevice();
	setfont(20, 0, "宋体");
}

//感谢使用动画
void end()
{
	setfont(40, 0, "华文行楷");
	setcolor(BLACK);
	xyprintf(500, 300, "Thank you for using this sketch pad is ERROR");
	delay_ms(2000);
	closegraph();
}
