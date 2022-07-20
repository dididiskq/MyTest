#pragma once
#include<iostream>
using namespace std;
#define _WALL_HEAD
class Wall{
public:
	//常用的数据使用枚举类型
	enum
	{
		ROW = 26,
		COL = 26
		
	};
	void initWall();
	void dradWall();
	void setWall(int x,int y,char c);
	char getWall(int x,int y);
private:
	char gameArray[ROW][COL];
};
