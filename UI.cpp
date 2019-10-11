#include <graphics.h>
#include <stdio.h> 

//创建标准按钮，用于配合if使用。
int button(int left, int bottom, int right, int top, mouse_msg msg = { 0 })//这个函数需要输入按钮有效区对应的矩形
{
	for (; is_run; delay_fps(60)) {
		while (mousemsg())
			msg = getmouse();
		if (msg.x > left && msg.y <= bottom && msg.x <= right && msg.y >= top) {//当鼠标移到按钮有效区时
			setcolor(BLACK);
			line(left, bottom, right, bottom);//在按钮下方绘制一条直线以增强反馈
			if (msg.is_down() == 1) {
				return 1;//返回按下按钮
			}
		}
		else {
			setcolor(EGERGB(250, 250, 210));
			line(left, bottom, right, bottom);//这样做用于不清屏地去掉直线
			setcolor(BLACK);
			return 0;
		}
	}
}

//初始化绘图面板。
void initialization()
{
	setinitmode(INIT_NOBORDER);
	initgraph(-1, -1);
	setbkcolor(EGERGB(250, 250, 210));
}
