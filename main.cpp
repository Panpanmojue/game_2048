#include"game2048.h"
#include<iostream>
#include<ctime>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

void game2048::add(){
    int x,y;
        srand((unsigned)time(NULL));
        do
        {
            x = rand() % 4;
            y = rand() % 4;
        } while (chessMap[x][y] != 0);

        if (count1 == 0 || count1 == 1){
            chessMap[x][y] = 2;
        }else{
            chessMap[x][y] = 4;
        }
}

void game2048::showMap(){
	system("cls");
    for(int i = 0;i < 4;i++){//打印第一行 
	    printf("+-----");
	}
    printf("+\n");
    for(int i = 0;i < 4;i++){
		for(int j = 0;j < 4;j++){
			printf("|");
			if(chessMap[i][j] != 0){//如果该格子里储存了元素 
                if (chessMap[i][j] > 1000){
                    cout << chessMap[i][j] << " ";
                } else if (chessMap[i][j] > 100)
                {
                    cout << " " << chessMap[i][j] << " ";
                } else if (chessMap[i][j] > 10){
                    cout << " " << chessMap[i][j] << "  ";
                }else{
                    cout << "  " << chessMap[i][j] << "  ";
                }
			}else{
				printf("     ");
			}
		}
		printf("|\n"); 
		for(int i = 0;i < 4;i++){//打印中间行 
			printf("+-----");
	    }
	    printf("+\n");
	}
}

game2048::game2048(){
    count1 = 0;//连消数设置为0
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0;j < 4;j++){
            chessMap[i][j] = 0;
        }
    }
    add();add();
    showMap();
}

void game2048::up(){
   int count = 0;
   //先全部上移
   for (int j = 0;j < 4;j++){
       for (int i = 0;i < 4;i++){
           if (chessMap[i][j] != 0){
               chessMap[count][j] = chessMap[i][j];
               count++;
           }
       }
       for (count;count < 4;count++){
           	chessMap[count][j] = 0;
		}
		count = 0;
    }
   //再合并
   for (int j = 0;j < 4;j++){
       for (int i = 0;i < 3;){
           if (chessMap[i][j] != 0 && chessMap[i][j] == chessMap[i+1][j]){
               chessMap[i][j] *= 2;
               chessMap[i+1][j] = 0;
               i = i + 2;
            } else{
                i = i + 1;
           }
       }
   }
	//再上移，同时清零 
    count = 0;
	for (int j = 0;j < 4;j++){
       for (int i = 0;i < 4;i++){
            if (chessMap[i][j] != 0){
               chessMap[count][j] = chessMap[i][j];
               count++;
           }
       }
       for (count;count < 4;count++){
           	chessMap[count][j] = 0;
		}
		count = 0;
   }
   count = 0;
}

void game2048::down(){
    int count = 0;//用来记录每列有几个数字
    //先将数字全部下移
    for (int j = 0;j < 4;j++){
        for (int i = 3;i >= 0;i--){
            if (chessMap[i][j] != 0)
            {
                chessMap[3 - count][j] = chessMap[i][j];//从最下面的数字开始设置起
                count++;
            }
        }
        for (count;count < 4;count++){
            chessMap[3 - count][j] = 0;//下移之后把最上面的设置为0
        }
        count = 0;//将count归零
    }
    //再将数字合并
    for (int j = 0;j < 4;j++){//仍然是一列列地检查
        for (int i = 3;i > 0;){//从最后一行开始检查起
            if (chessMap[i][j] != 0 && chessMap[i][j] == chessMap[i - 1][j]){//能跟它上面的数字匹配
                chessMap[i][j] *= 2;
                chessMap[i - 1][j] = 0;
                i = i - 2;//在向上两位寻找
            } else{
                i = i - 1;//不匹配，在上一个寻找
            }

        }
    }
    //合并之后再次上移，同时清零
    count = 0;
    for (int j = 0;j < 4;j++){
        for (int i = 3;i >= 0;i--){
            if (chessMap[i][j] != 0)
            {
                chessMap[3 - count][j] = chessMap[i][j];//从最下面的数字开始设置起
                count++;
            }
        }
        for (count;count < 4;count++){
            chessMap[3 - count][j] = 0;//下移之后把最上面的设置为0
        }
        count = 0;//将count归零
    }
    count = 0;
}

void game2048::left(){
	int count = 0;
    //先全部左移动
    for (int i = 0;i < 4;i++){
        for (int j = 0;j < 4;j++){
            if (chessMap[i][j] != 0)
            {
                chessMap[i][count] = chessMap[i][j];
                count++;
            }
        }
        for (count;count < 4;count++){
            chessMap[i][count] = 0;
        }
        count = 0;
    }
    //再合并
    for (int i = 0;i < 4;i++){
        for (int j = 0;j < 3;){
            if (chessMap[i][j] != 0 && chessMap[i][j] == chessMap[i][j+1]){//能够右边的数字匹配
                chessMap[i][j] *= 2;
                chessMap[i][j+1] = 0;
                j = j + 2;
            } else{
                j = j + 1;
            }
        }
    }
    //再次左移
    for (int i = 0;i < 4;i++){
        for (int j = 0;j < 4;j++){
            if (chessMap[i][j] != 0)
            {
                chessMap[i][count] = chessMap[i][j];
                count++;
            }
        }
        for (count;count < 4;count++){
            chessMap[i][count] = 0;
        }
        count = 0;
    }
    count = 0;
}

void game2048::right(){
	int count = 0;
    //先全部右移
    for (int i = 0;i < 4;i++){
        for (int j = 3;j >= 0;j--){
            if (chessMap[i][j] != 0){
                chessMap[i][3-count] = chessMap[i][j];
                count++;
            }
        }
        for (count;count < 4;count++){
            chessMap[i][3-count] = 0;
        }
        count = 0;
    }
    //再合并
    for (int i = 0;i < 4;i++){
        for (int j = 3;j > 0;){
            if (chessMap[i][j] != 0 && chessMap[i][j] == chessMap[i][j-1]){//能跟左边的合并
                chessMap[i][j] *= 2;
                chessMap[i][j-1] = 0;
                j = j - 2;
            } else{
                j = j - 1;
            }
        }
    }
    //再次右移
    for (int i = 0;i < 4;i++){
        for (int j = 3;j >= 0;j--){
            if (chessMap[i][j] != 0){
                chessMap[i][3-count] = chessMap[i][j];
                count++;
            }
        }
        for (count;count < 4;count++){
            chessMap[i][3-count] = 0;
        }
        count = 0;
    }
    count = 0;
}


/**判断游戏是否结束
* 首先检查是否产生2048，若有，游戏结束
*  若无，检查棋盘上是否有空位，若有，游戏继续
*      若无，检查能否进行移动，不能进行移动，游戏结束，可以进行移动，游戏继续
*/
bool game2048::over(){
//第一步，检查有无2048
for (int i = 0;i < 4;i++){
    for (int j = 0;j < 4;j++){
        if (chessMap[i][j] == 2048){//如果出现了2048，游戏获得胜利
            cout << "Congratulations!You win!";
            return true;
        }
    }
}
//第二步，上面没有返回值的话，检查棋盘是否有空位
for (int i = 0;i < 4;i++){
    for (int j = 0;j < 4;j++){
        if (chessMap[i][j] == 0){//有空位，游戏继续
            return false;
        }
    }
}
//第三步，检查是否可以移动
for (int j = 0;j < 4;j++){//先检查上下
    for (int i =0;i < 3;i++){
        if (chessMap[i][j] == chessMap[i+1][j]){//如果可以消除
            return false;
        }
    }
}
for (int i = 0;i < 4;i++){//再检查左右
    for (int j = 0;j < 3;j++){
        if (chessMap[i][j] == chessMap[i][j+1]){
            return false;
        }
    }
}

cout << "no useful move!Game Over!" << endl;//如果不能移动，输出提示语
return true;
}

void delay_time(double t)
{
	clock_t start = clock();
	clock_t delay = (clock_t)t * CLOCKS_PER_SEC;
	while (clock() - start < delay)
		continue;
}

int main(){
    using std::cout;
	using std::cin;
	using std::endl;
	cout << "Welcome to game 2048!!!" << endl;
	delay_time(2.0);

    system("cls");
    game2048 game;//创建对象
    bool is_WASD = NULL;
    while (true)
    {
        if (_kbhit()&&!game.over())
        {
            int input = _getch();
            switch (input)
            {
            case 87://大写W的键值 
            case 119://小写w的键值
                game.up();
                game.add();
                game.showMap();
                game.over();
                break;
            case 83://大写S的键值 
            case 115://小写s的键值
            	game.down();
            	game.add();
            	game.showMap();
            	game.over();
            	break;
			case 65://大写A的键值 
            case 97://小写a的键值
            	game.left();
            	game.add();
            	game.showMap();
            	game.over();
            	break;
			case 68://大写D的键值 
            case 100://小写d的键值
            	game.right();
            	game.add();
            	game.showMap();
            	game.over();
            	break;   
            default:
                is_WASD = false;
                break;
            }

        }
        if (game.over()){
        	break;
		}
      
    }
}
