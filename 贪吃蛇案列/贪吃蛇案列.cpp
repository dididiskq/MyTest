// 贪吃蛇案列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"wall.h"
#include <iostream>
#include"snake.h"
#include"food.h"
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include<ctime> 
#include<conio.h>
#include<Windows.h>
//这一段是定位光标位置的函数，是为了解决屏幕闪的问题，提高游戏的体验
void gotoxy(HANDLE hOut,int x,int y) {
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
int main()
{
    //设置随机种子，保证小蝌蚪出现的位置时随机的
    srand((unsigned int)time(NULL));
    //先画出墙体
    Wall wall;
    wall.initWall();
    wall.dradWall();

    //初始化蛇和食物
    bool isDead=false;
    char prekey = NULL;//记录蛇动的上一步是那个按键
    Food food(wall);
    food.setFood();

    Snake snake(wall,food);
    snake.initSnake();
     
    gotoxy(hOut,0,26);
    cout << "得分:" << snake.getScore();
    
    /*gotoxy(hOut,12,4);*/
    //进入主循环，保持程序的运行
    while (true) {
        char key = _getch();//键盘输入函数
        if (prekey==NULL&&key=='a') {//初始激活不能用left
            continue;
        }
        do
        {
            if (key=='a'|| key =='d' || key == 'w' || key == 's') {
                //下面这段代码是因为出现按钮之间的矛盾
                if ((key == 'a' && prekey == 'd' )||
                    (key == 'd' && prekey == 'a' )||
                    (key == 'w' && prekey == 's' )||
                    (key == 's' && prekey == 'w' )
                    ) {
                    key = prekey;
                }
                else {
                    prekey = key;
                }
                if (snake.move(key)) {
                   /* system("cls");
                    wall.dradWall();*/
                    gotoxy(hOut, 0, 26);
                    cout << "得分:" << snake.getScore();
                    Sleep(snake.getTime());
                }
                else {
                    isDead = true;
                    break;
                }
            }
        } while (!_kbhit());//键盘不输入的时候，返回0
         
    }
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
