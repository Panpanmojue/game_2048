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
    for(int i = 0;i < 4;i++){//��ӡ��һ�� 
	    printf("+-----");
	}
    printf("+\n");
    for(int i = 0;i < 4;i++){
		for(int j = 0;j < 4;j++){
			printf("|");
			if(chessMap[i][j] != 0){//����ø����ﴢ����Ԫ�� 
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
		for(int i = 0;i < 4;i++){//��ӡ�м��� 
			printf("+-----");
	    }
	    printf("+\n");
	}
}

game2048::game2048(){
    count1 = 0;//����������Ϊ0
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
   //��ȫ������
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
   //�ٺϲ�
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
	//�����ƣ�ͬʱ���� 
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
    int count = 0;//������¼ÿ���м�������
    //�Ƚ�����ȫ������
    for (int j = 0;j < 4;j++){
        for (int i = 3;i >= 0;i--){
            if (chessMap[i][j] != 0)
            {
                chessMap[3 - count][j] = chessMap[i][j];//������������ֿ�ʼ������
                count++;
            }
        }
        for (count;count < 4;count++){
            chessMap[3 - count][j] = 0;//����֮��������������Ϊ0
        }
        count = 0;//��count����
    }
    //�ٽ����ֺϲ�
    for (int j = 0;j < 4;j++){//��Ȼ��һ���еؼ��
        for (int i = 3;i > 0;){//�����һ�п�ʼ�����
            if (chessMap[i][j] != 0 && chessMap[i][j] == chessMap[i - 1][j]){//�ܸ������������ƥ��
                chessMap[i][j] *= 2;
                chessMap[i - 1][j] = 0;
                i = i - 2;//��������λѰ��
            } else{
                i = i - 1;//��ƥ�䣬����һ��Ѱ��
            }

        }
    }
    //�ϲ�֮���ٴ����ƣ�ͬʱ����
    count = 0;
    for (int j = 0;j < 4;j++){
        for (int i = 3;i >= 0;i--){
            if (chessMap[i][j] != 0)
            {
                chessMap[3 - count][j] = chessMap[i][j];//������������ֿ�ʼ������
                count++;
            }
        }
        for (count;count < 4;count++){
            chessMap[3 - count][j] = 0;//����֮��������������Ϊ0
        }
        count = 0;//��count����
    }
    count = 0;
}

void game2048::left(){
	int count = 0;
    //��ȫ�����ƶ�
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
    //�ٺϲ�
    for (int i = 0;i < 4;i++){
        for (int j = 0;j < 3;){
            if (chessMap[i][j] != 0 && chessMap[i][j] == chessMap[i][j+1]){//�ܹ��ұߵ�����ƥ��
                chessMap[i][j] *= 2;
                chessMap[i][j+1] = 0;
                j = j + 2;
            } else{
                j = j + 1;
            }
        }
    }
    //�ٴ�����
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
    //��ȫ������
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
    //�ٺϲ�
    for (int i = 0;i < 4;i++){
        for (int j = 3;j > 0;){
            if (chessMap[i][j] != 0 && chessMap[i][j] == chessMap[i][j-1]){//�ܸ���ߵĺϲ�
                chessMap[i][j] *= 2;
                chessMap[i][j-1] = 0;
                j = j - 2;
            } else{
                j = j - 1;
            }
        }
    }
    //�ٴ�����
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


/**�ж���Ϸ�Ƿ����
* ���ȼ���Ƿ����2048�����У���Ϸ����
*  ���ޣ�����������Ƿ��п�λ�����У���Ϸ����
*      ���ޣ�����ܷ�����ƶ������ܽ����ƶ�����Ϸ���������Խ����ƶ�����Ϸ����
*/
bool game2048::over(){
//��һ�����������2048
for (int i = 0;i < 4;i++){
    for (int j = 0;j < 4;j++){
        if (chessMap[i][j] == 2048){//���������2048����Ϸ���ʤ��
            cout << "Congratulations!You win!";
            return true;
        }
    }
}
//�ڶ���������û�з���ֵ�Ļ�����������Ƿ��п�λ
for (int i = 0;i < 4;i++){
    for (int j = 0;j < 4;j++){
        if (chessMap[i][j] == 0){//�п�λ����Ϸ����
            return false;
        }
    }
}
//������������Ƿ�����ƶ�
for (int j = 0;j < 4;j++){//�ȼ������
    for (int i =0;i < 3;i++){
        if (chessMap[i][j] == chessMap[i+1][j]){//�����������
            return false;
        }
    }
}
for (int i = 0;i < 4;i++){//�ټ������
    for (int j = 0;j < 3;j++){
        if (chessMap[i][j] == chessMap[i][j+1]){
            return false;
        }
    }
}

cout << "no useful move!Game Over!" << endl;//��������ƶ��������ʾ��
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
    game2048 game;//��������
    bool is_WASD = NULL;
    while (true)
    {
        if (_kbhit()&&!game.over())
        {
            int input = _getch();
            switch (input)
            {
            case 87://��дW�ļ�ֵ 
            case 119://Сдw�ļ�ֵ
                game.up();
                game.add();
                game.showMap();
                game.over();
                break;
            case 83://��дS�ļ�ֵ 
            case 115://Сдs�ļ�ֵ
            	game.down();
            	game.add();
            	game.showMap();
            	game.over();
            	break;
			case 65://��дA�ļ�ֵ 
            case 97://Сдa�ļ�ֵ
            	game.left();
            	game.add();
            	game.showMap();
            	game.over();
            	break;
			case 68://��дD�ļ�ֵ 
            case 100://Сдd�ļ�ֵ
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
