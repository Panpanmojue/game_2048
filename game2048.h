#pragma once

#define Size 4

class game2048
{
private:
    int chessMap[4][4];
    int count1;//用来记录连消值 
    bool flag;//判断是否能消除 
public:
    game2048();//构造函数 
    void add();//在棋盘上增加2的函数 
    //四个移动操作 
    void up();
    void down();
    void left();
    void right();
    void showMap();//打印棋盘 
    bool over();//判断游戏是否结束 
};

void delay_time(double t);
