#pragma once
#include"wall.h"
#include"food.h"
class Snake {
public:
	struct Point
	{
		int x;
		int y;
		Point* next;
	};
	Point* head;
	Food& food;
	Wall& wall;
	Snake(Wall & temWall,Food & temFood);
	void initSnake();
	void destorySnake();
	void addPoint(int x,int y);
	void deletePoint();
	bool move(char key);
	bool isRool;
	int getScore();
	int getSnakeLength();
	int getTime();
	 
};
