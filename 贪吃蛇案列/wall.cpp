#include"wall.h"
void Wall::initWall() {
	for (int i = 0;i < ROW;i++) {
		for (int j = 0;j < COL;j++) {
			if (i==0||i==ROW-1||j==0||j==COL-1) {
				gameArray[i][j] = '*';
			}
			else {
				gameArray[i][j] = ' ';
			}
		}
	}
}

void Wall::dradWall()
{
	for (int i = 0;i < ROW;i++) {
		for(int j = 0;j < COL;j++) {
			cout << gameArray[i][j] << " ";
		}
		//显示出操作提示
			if (i == 5) {
				cout << "a:left";
			}
			if (i == 6) {
				cout << "d:right";
			}
			if (i == 7) {
				cout << "w:up";
			}
			if (i == 8) {
				cout << "s:down";
			}
		cout << endl;
	}
}
//这两个函数其实是为了初始化蛇和食物的样子而设置的
void Wall::setWall(int x, int y, char c)
{
	gameArray[x][y] = c;
}

char Wall::getWall(int x, int y)
{
	return gameArray[x][y];
}
