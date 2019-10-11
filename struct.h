#pragma once


//下面是圆的结构体
struct circle_s {
	int x;
	int y;
	int rad;
	color_t color;
};
circle_s circle_record;
circle_s circle_data[64];


//下面是直线的结构体
struct line_s {
	int x1;
	int y1;
	int x2;
	int y2;
	color_t color;
};
struct line_s line_record;
struct line_s line_data[64];


//下面是矩形的结构体
struct rectangle_s {
	int left;
	int top;
	int right;
	int bottom;
	color_t color;
};
struct rectangle_s rectangle_record;
struct rectangle_s rectangle_data[64];


//下面是多边形的结构体
struct poly_s {
	int i;
	int coordinate[100];
	color_t color;
};
struct poly_s poly_record;
struct poly_s poly_data[64];
