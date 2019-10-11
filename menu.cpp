#include <graphics.h>
#include <stdio.h> 
#include "UI.h"
#include "CG.h"

//关闭绘图程序函数
int save(mouse_msg msg = { 0 })
{
	setfont(40, 0, "华文行楷");
	setcolor(BLACK);
	int CG_ed_return;
	xyprintf(530, 300, "Do you want to save your project?");
	xyprintf(550, 370, "Yes");
	xyprintf(880, 370, "No");
	for (; is_run; delay_fps(60)) {
		while (mousemsg())
			msg = getmouse();
		if (button(535, 410, 600, 365, msg)){//这个按钮为是选项
			CG_edsave();
			CG_ed_return = 1;
			break;
		}
		else if (button(865, 410, 920, 365, msg)) {//这个按钮为否选项
			CG_edunsave();
			CG_ed_return = 2;
			break;
		}
	}
	setfont(20, 0, "宋体");
	return CG_ed_return;
}

//读取文件函数
int load(mouse_msg msg = { 0 })
{
	setfont(40, 0, "华文行楷");
	setcolor(BLACK);
	int load_return;
	xyprintf(530, 300, "Do you want to load your project?");
	xyprintf(550, 370, "Yes");
	xyprintf(880, 370, "No");

	for (; is_run; delay_fps(60)) {
		while (mousemsg())
			msg = getmouse();
		if (button(535, 410, 600, 365, msg)) {//这个按钮选择是
			CG_load();
			load_return = 1;
			goto to_return;
			break;
		}
		else if (button(865, 410, 920, 365, msg)) {//这个按钮选择否
			CG_unload();
			load_return = 2;
			goto to_return;
			break;
		}
	}
	setfont(20, 0, "宋体");
	to_return:
	return load_return;
}
