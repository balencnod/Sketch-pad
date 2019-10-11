#include <graphics.h>
#include <stdio.h> 
#include <string.h>
#include "struct.h"//这个头文件包含了保存图形所需要的结构体

FILE *fp;

//这个函数用于做圆
int circle_func()
{
	static int i_circle = 0;//这个变量用于计算从程序打开开始所画圆的个数
	int x, y, rad;
	char str_circle[100];
	inputbox_getline("提示", "请输入圆心的x轴坐标", str_circle, 100);
	x = atoi(str_circle);
	inputbox_getline("提示", "请输入圆心的y轴坐标", str_circle, 100);
	y = atoi(str_circle);
	inputbox_getline("提示", "请输入圆的半径", str_circle, 100);
	rad = atoi(str_circle);
	circle(x, y, rad);
	circle_data[i_circle].x = x;//这个函数用于记录所画的圆
	circle_data[i_circle].y = y;//这个函数用于记录所画的圆
	circle_data[i_circle].rad = rad;//这个函数用于记录所画的圆
	circle_data[i_circle].color = getcolor();//这个函数用于记录所画的圆
	i_circle++;
	return i_circle;
}

//这个函数用于做直线
int line_func()
{
	static int i_line = 0;//这个变量用于计算从程序打开开始所画直线的个数
	int x1, x2, y1, y2;
	char str_line[100];
	inputbox_getline("提示", "请输入线段任一端点的x轴坐标", str_line, 100);
	x1 = atoi(str_line);
	inputbox_getline("提示", "请输入线段这一端点的y轴坐标", str_line, 100);
	y1 = atoi(str_line);
	inputbox_getline("提示", "请输入线段另一端点的x轴坐标", str_line, 100);
	x2 = atoi(str_line);
	inputbox_getline("提示", "请输入线段这一端点的y轴坐标", str_line, 100);
	y2 = atoi(str_line);
	line(x1, y1, x2, y2);
	line_data[i_line].x1 = x1;//这个函数用于记录所画的直线
	line_data[i_line].y1 = y1;//这个函数用于记录所画的直线
	line_data[i_line].x2 = x2;//这个函数用于记录所画的直线
	line_data[i_line].y2 = y2;//这个函数用于记录所画的直线
	line_data[i_line].color = getcolor();//这个函数用于记录所画的直线
	i_line++;
	return i_line;
}

//这个函数用于画矩形
int rectangle_func()
{
	static int i_rectangle = 0;//这个变量用于计算从程序打开开始所画矩形的个数
	int  left, right, top, bottom;
	char str_rectangle[100];
	inputbox_getline("提示", "请输入矩形左部x轴坐标", str_rectangle, 100);
	left = atoi(str_rectangle);
	inputbox_getline("提示", "请输入矩形右部x轴坐标", str_rectangle, 100);
	right = atoi(str_rectangle);
	inputbox_getline("提示", "请输入矩形上部y轴坐标", str_rectangle, 100);
	top = atoi(str_rectangle);
	inputbox_getline("提示", "请输入矩形下部y轴坐标", str_rectangle, 100);
	bottom = atoi(str_rectangle);
	rectangle(left, top, right, bottom);
	rectangle_data[i_rectangle].left = left;//这个函数用于记录所画的矩形
	rectangle_data[i_rectangle].top = top;//这个函数用于记录所画的矩形
	rectangle_data[i_rectangle].right = right;//这个函数用于记录所画的矩形
	rectangle_data[i_rectangle].bottom = bottom;//这个函数用于记录所画的矩形
	rectangle_data[i_rectangle].color = getcolor();//这个函数用于记录所画的矩形
	i_rectangle++;
	return i_rectangle;
}

//这个函数用于合成用户所需颜色
int setcolor_func()
{
	int foreground_color, R_color, G_color, B_color;
	char str_color[100];
	inputbox_getline("请输入前景色", "请挑选前景色：\n1.红     2.橙     3.黄\n4.绿     5.蓝     6.青\n7.紫     8.白\n9.使用RGB自定义颜色", str_color, 100);

re_foreground_color:
	foreground_color = atoi(str_color);
	if (!(foreground_color >= 0 && foreground_color <= 9)) {//检查用户所输入的值
		inputbox_getline("请输入正确的选项", "请挑选前景色：\n1.红     2.橙     3.黄\n4.绿     5.蓝     6.青\n7.紫     8.白\n9.使用RGB自定义颜色", str_color, 100);
		goto re_foreground_color;//返回以重新赋值
	}

	switch (foreground_color) {
	case 1:
		setcolor(RED);
		break;
	case 2:
		setcolor(EGERGB(255, 153, 18));
		break;
	case 3:
		setcolor(EGERGB(255, 255, 0));
		break;
	case 4:
		setcolor(GREEN);
		break;
	case 5:
		setcolor(BLUE);
		break;
	case 6:
		setcolor(CYAN);
		break;
	case 7:
		setcolor(MAGENTA);
		break;
	case 8:
		setcolor(EGERGB(255, 255, 255));
		break;
	case 9://这个分支用于用RGB合成颜色
		char str_RGB[100];

		inputbox_getline("使用RGB合成颜色", "请输入R值", str_RGB, 100);
	re_R_color:
		R_color = atoi(str_RGB);
		if (!(R_color >= 0 && R_color <= 255)) {//用于检查用户输入的值
			inputbox_getline("请输入正确的R值", "请输入R值", str_RGB, 100);
			goto re_R_color;//返回以重新赋值
		}

		inputbox_getline("使用RGB合成颜色", "请输入G值", str_RGB, 100);
	re_G_color:
		G_color = atoi(str_RGB);
		if (!(G_color >= 0 && G_color <= 255)) {//用于检查用户输入的值
			inputbox_getline("请输入正确的G值", "请输入G值", str_RGB, 100);
			goto re_G_color;//返回以重新赋值
		}

		inputbox_getline("使用RGB合成颜色", "请输入B值", str_RGB, 100);
	re_B_color:
		B_color = atoi(str_RGB);
		if (!(B_color >= 0 && B_color <= 255)) {//用于检查用户输入的值
			inputbox_getline("请输入正确的B值", "请输入B值", str_RGB, 100);
			goto re_B_color;//返回以重新赋值
		}
		setcolor(EGERGB(R_color, G_color, B_color));
	}
	return foreground_color;
}

//这个函数用于画多边形
int poly_func()
{
	static int i_poly = 0;//这个变量用于计算从程序打开开始所画多边形的个数
	int coordinate[100];//多边形的坐标将储存在一个数组中，以x1,y1,x2,y2...的形式排列
	int i = 0;
	char str_poly[100];
	inputbox_getline("请输入多边形顶点的坐标", "请输入坐标，并以英文逗号进行分割", str_poly, 100);
	char *token = strtok(str_poly, ",");//以英文逗号作为分隔符
	while (token != '\0') {//在字符串末尾停止
		coordinate[i] = atoi(token);
		poly_data[i_poly].coordinate[i] = coordinate[i];//这个部分用于储存多边形的坐标
		i++;
		token = strtok(NULL, ",");//继续取下一个坐标
	}
	fillpoly(i / 2, coordinate);
	poly_data[i_poly].i = i;//储存多边形的边数
	poly_data[i_poly].color = getcolor();//储存多边形的颜色
	i_poly++;
	return i_poly++;
}

//这个函数用于重画圆
void rewrite_circle(int i)
{
	setcolor(circle_data[i].color);
	circle(circle_data[i].x, circle_data[i].y, circle_data[i].rad);
}

//这个函数用于重画直线
void rewrite_line(int i)
{
	setcolor(line_data[i].color);
	line(line_data[i].x1, line_data[i].y1, line_data[i].x2, line_data[i].y2);
}

//这个函数用于重画矩形
void rewrite_rectangle(int i)
{
	setcolor(rectangle_data[i].color);
	rectangle(rectangle_data[i].left, rectangle_data[i].top, rectangle_data[i].right, rectangle_data[i].bottom);
}

//这个函数用于重画多边形
void rewrite_poly(int i) {
	setcolor(poly_data[i].color);
	fillpoly(poly_data[i].i / 2, poly_data[i].coordinate);
}

//保存圆
void save_circle(int circlenum) 
{
	fp = fopen("circledat", "w+" );//图形的保存将分类型以文本方式保存
	fprintf(fp, "%d\n", circlenum);
	for (int i = 0; i < circlenum; i++) {
		fprintf(fp, "%d %d %d %d ", circle_data[i].x, circle_data[i].y, circle_data[i].rad, circle_data[i].color);
		fprintf(fp, "\n");
	}
	fclose(fp);
	fp = NULL;
}

//保存直线
void save_line(int linenum)
{
	fp = fopen("linedat", "w+");
	fprintf(fp, "%d\n", linenum);
	for (int i = 0; i < linenum; i++) {
		fprintf(fp, "%d %d %d %d %d", line_data[i].x1, line_data[i].y1, line_data[i].x2, line_data[i].y2, line_data[i].color);
		fprintf(fp, "\n");
	}
	fclose(fp);
	fp = NULL;
}

//保存矩形
void save_rectangle(int rectanglenum)
{
	fp = fopen("rectangledat", "w+");
	fprintf(fp, "%d\n", rectanglenum);
	for (int i = 0; i < rectanglenum; i++) {
		fprintf(fp, "%d %d %d %d %d", rectangle_data[i].left, rectangle_data[i].top, rectangle_data[i].right, rectangle_data[i].bottom, rectangle_data[i].color);
		fprintf(fp, "\n");
	}
	fclose(fp);
	fp = NULL;
}

//保存多边形
void save_poly(int polynum)
{
	fp = fopen("polydat", "w+");
	fprintf(fp, "%d\n", polynum);
	for (int i = 0; i < polynum; i++) {//i用于计数保存了几个多边形
		fprintf(fp, "%d ", poly_data[i].i);
		fprintf(fp, "%d ", poly_data[i].color);//首先保存多边形边数和颜色
		for (int k = 0; k < poly_data[i].i; k++) {//k用于计数保存了多边形几个坐标
			fprintf(fp, "%d ", poly_data[i].coordinate[k]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	fp = NULL;
}

//读取圆
void load_circle()
{
	int circlenum;
	fp = fopen("circledat", "r");
	fscanf(fp, "%d\n", &circlenum);
	for (int i = 0; i < circlenum; i++) {
		fscanf(fp, "%d %d %d %d \n", &circle_data[i].x, &circle_data[i].y, &circle_data[i].rad, &circle_data[i].color);
		rewrite_circle(i);
	}
	fclose(fp);
	fp = NULL;
}

//读取直线
void load_line()
{
	int linenum;
	fp = fopen("linedat", "r");
	fscanf(fp, "%d\n", &linenum);
	for (int i = 0; i < linenum; i++) {
		fscanf(fp, "%d %d %d %d %d", &line_data[i].x1, &line_data[i].y1, &line_data[i].x2, &line_data[i].y2, &line_data[i].color);
		rewrite_line(i);
	}
	fclose(fp);
	fp = NULL;
}

//读取矩形
void load_rectangle()
{
	int rectanglenum;
	fp = fopen("rectangledat", "r");
	fscanf(fp, "%d\n", &rectanglenum);
	for (int i = 0; i < rectanglenum; i++) {
		fscanf(fp, "%d %d %d %d %d", &rectangle_data[i].left, &rectangle_data[i].top, &rectangle_data[i].right, &rectangle_data[i].bottom, &rectangle_data[i].color);
		rewrite_rectangle(i);
	}
	fclose(fp);
	fp = NULL;
}

//读取多边形
void load_poly()
{
	int polynum;
	fp = fopen("polydat", "r");
	fscanf(fp, "%d\n", &polynum);
	for (int i = 0; i < polynum; i++) {//i用于计数读取了几个多边形
		fscanf(fp, "%d ", &poly_data[i].i);
		fscanf(fp, "%d ", &poly_data[i].color);
		for (int k = 0; k < poly_data[i].i; k++) {//k用于计数读取多边形的几个坐标
			fscanf(fp, "%d ", &poly_data[i].coordinate[k]);
		}
		rewrite_poly(i);
	}
	fclose(fp);
	fp = NULL;
}
