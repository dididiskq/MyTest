#pragma once
#include"wall.h"
class Food {
public:
	//…Ë÷√ ≥ŒÔ
	Food(Wall & temWall);
	void setFood();
	Wall& wall;
	int foodX;
	int foodY;
};
