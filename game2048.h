#pragma once

#define Size 4

class game2048
{
private:
    int chessMap[4][4];
    int count1;//������¼����ֵ 
    bool flag;//�ж��Ƿ������� 
public:
    game2048();//���캯�� 
    void add();//������������2�ĺ��� 
    //�ĸ��ƶ����� 
    void up();
    void down();
    void left();
    void right();
    void showMap();//��ӡ���� 
    bool over();//�ж���Ϸ�Ƿ���� 
};

void delay_time(double t);
