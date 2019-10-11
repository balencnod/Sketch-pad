#include <graphics.h>
#include <stdio.h> 
#include <math.h> 

int mx1, mx2, my1, my2, mx3, my3, mdata1;
bool mouse_is_down1 = false, mouse_is_down2 = false;

//这个函数用于鼠绘一个圆
void mouse_circle(mouse_msg msg = { 0 })
{
	
	for (; is_run(); delay_fps(60)) {
		while (mousemsg())
			msg = getmouse();
		if (msg.is_down() == 1 && msg.is_left()) {//当鼠标左键按下时确定第一个点的坐标
			mx1 = msg.x;
			my1 = msg.y;
			circle(mx1, my1, 1);
			mouse_is_down1 = true;
		}
		if (msg.is_down() == 1 && msg.is_right()) {//当鼠标右键按下时确定第二个点的坐标
			mx2 = msg.x;
			my2 = msg.y;
			circle(mx2, my2, 1);
			mouse_is_down2 = true;
		}
		if (mouse_is_down1 && mouse_is_down2) {//当左右键都按下后绘制直线
			mx3 = (mx1 + mx2) / 2;
			my3 = (my1 + my2) / 2;
			mdata1 = sqrt((mx1 - mx3)*(mx1 - mx3) + (my1 - my3)*(my1 - my3));
			circle(mx3, my3, mdata1);
			mouse_is_down1 = false;
			mouse_is_down2 = false;
			return;
		}
	}
}

//这个函数用于鼠绘一个直线
void mouse_line(mouse_msg msg = { 0 })
{
	for (; is_run(); delay_fps(60)) {
		while (mousemsg())
			msg = getmouse();
		if (msg.is_down() == 1 && msg.is_left()) {//当鼠标左键按下时确定圆的外切矩形左上角坐标
			mx1 = msg.x;
			my1 = msg.y;
			circle(mx1, my1, 1);
			mouse_is_down1 = true;
		}
		if (msg.is_down() == 1 && msg.is_right()) {//当鼠标右键按下时确定圆的外切矩形右下角坐标
			mx2 = msg.x;
			my2 = msg.y;
			circle(mx2, my2, 1);
			mouse_is_down2 = true;
		}
		if (mouse_is_down1 && mouse_is_down2) {//当两个左右键都按下后绘制圆
			line(mx1, my1, mx2, my2);
			mouse_is_down1 = false;
			mouse_is_down2 = false;
			return;
		}
	}
}
