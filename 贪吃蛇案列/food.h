#pragma once
#include"wall.h"
class Food {
public:
	//����ʳ��
	Food(Wall & temWall);
	void setFood();
	Wall& wall;
	int foodX;
	int foodY;
};
