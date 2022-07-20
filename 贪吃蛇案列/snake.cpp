#include"snake.h"
#include<Windows.h>
void gotoxy1(HANDLE hOut1, int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut1, pos);
}
HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);
//注意这里啊，使用了初始化列表知识点
//目的：
Snake::Snake(Wall & temWall, Food& temFood):wall(temWall),food(temFood)
{
	head = nullptr;
}

void Snake::initSnake()
{
	destorySnake();
	//初始化蛇的长度是三个
	addPoint(5,3);
	addPoint(5,4);
	addPoint(5, 5);
}
//销毁所有节点
void Snake::destorySnake()
{
	//节点指针只是so easy
	Point* temPoint=head;
	while (head) {
		temPoint = head->next;
		delete head;
		head = temPoint;
	}
}

void Snake::addPoint(int x, int y)
{
	//先创建新节点
	Point* newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = nullptr;
	if (head) {
		wall.setWall(head->x,head->y,'=');
		gotoxy1(hOut1, 2*head->y, head->x);
		cout << "=";
	}
	newPoint->next = head;
	head = newPoint;
	wall.setWall(head->x,head->y,'@');
	gotoxy1(hOut1, 2*head->y, head->x);
	cout << "@";
}
//删除节点
void Snake::deletePoint()
{
	if (head==nullptr||head->next==nullptr) {
		return;
	}
	Point* pre=head;
	Point* cur=head->next;
	while (cur->next) {
		pre = pre->next;
		cur = cur->next;
	}
	 
	wall.setWall(cur->x,cur->y,' ');
	gotoxy1(hOut1, 2 * cur->y, cur->x);
	cout << " ";
	delete cur;
	cur = nullptr;
	pre->next = nullptr;
}

bool Snake::move(char key)
{
	int x = head->x;
	int y = head->y;
	switch (key)
	{
	case 'w':
		x--;
		break;
	case 's':
		x++;
		break;
	case 'a':
		y--;
		break;
	case 'd':
		y++;
		break;
	default:
		break;
	}
	Point* pre = head;
	Point* cur = head->next;
	while (cur->next) {
		pre = pre->next;
		cur = cur->next;
	}
	if (cur->x == x && cur->y == y) {
		isRool = true;
	}
	else {
		if (wall.getWall(x,y)=='*'||wall.getWall(x,y)=='=') {
			addPoint(x,y);
			deletePoint();
			system("cls");
			wall.dradWall();
			cout << "GAME OVER!!" << endl;
			cout << "最终得分" << getScore();
			return false;
		}
	}
	if (wall.getWall(x,y)=='#') {
		addPoint(x,y);
		food.setFood();
	}
	else {
		addPoint(x,y);
		deletePoint();
		if (isRool) {
			wall.setWall(x,y,'@');
			gotoxy1(hOut1, 2*y,  x);
			cout << "@";
		}
	}
	return true;
}

int Snake::getScore()
{
	int score = 0;
	score = getSnakeLength() - 3;
	return score;
}

int Snake::getSnakeLength()
{
	Point* tem = head;
	int size = 0;
	while (tem) {
		size++;
		tem = tem->next;
	}
	return size;
}

int Snake::getTime()
{
	int time = 0;
	if (getSnakeLength()<5) {
		time = 300;
	}
	else if (getSnakeLength()>=6&&getSnakeLength()<=15) {
		time = 200;
	}
	else {
		time = 100;
	}
	return time;
}

 