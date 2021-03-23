# lab2说明文档

为了实现这次的lab,首先我定义了一个名为game2048的类，它的属性都是私有的，不可被外部访问的，公共的是我们定义的一些方法与构造方法
```cpp
//game2048.h
#pragma once

#define Size 4

class game2048
{
private:
    int chessMap[4][4];
    int count1;//用来记录连消值(以后可以用来实现随机生成4) 
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
```
然后在main.cpp里重写这些方法
我觉得这里难以实现的主要是移动的方法，我也在网上参考了很多别人的思路，但是感觉各种循环之间的嵌套特别不好理解，于是自己思考的时候想到了一个思路，最终也靠这个思路成功实现了游戏的逻辑。
以向上移动`up()`为例子
先不考虑数字之间能否结合，把数字全部上移，集中在4*4方格的上部分，再从上往下依次检验数字和它下一个数字之间两两能否结合，若能结合，当前数字变为原来的两倍，它的下一个数字清零，且从当前数字的下两个开始检查；若不能结合，数字不变，从它下一个数字开始检查起。第三步，由于结合之后可能产生空位，再进行数字全部上移操作即可。

```cpp
void game2048::up(){
   int count = 0;//用来记录每一列有几个数字
   //先全部上移
   for (int j = 0;j < 4;j++){//j代表列，一列一列地检查
       for (int i = 0;i < 4;i++){
           if (chessMap[i][j] != 0){找到第count个非零值就放在第count位上
               chessMap[count][j] = chessMap[i][j];
               count++;
           }
       }
       //这个for循环是对棋盘没有数字的下部分清零
       for (count;count < 4;count++){
           	chessMap[count][j] = 0;
		}
		count = 0;
    }
   //再合并
   for (int j = 0;j < 4;j++){
       for (int i = 0;i < 3;){
           if (chessMap[i][j] != 0 && chessMap[i][j] == chessMap[i+1][j]){//当前数字与下一个数字能匹配
               chessMap[i][j] *= 2;
               chessMap[i+1][j] = 0;
               i = i + 2;//从当前数字的下两个开始
            } else{
                i = i + 1;//不能匹配
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
```

最后说一下我判断游戏结束的顺序：

 1. 先判断是否产生了2048，若有，游戏胜利，结束；否则，进行第二步
 2. 不满足第一个条件的话，检测棋盘上是否有空位，若有，游戏继续；否则，进行第三步
 3. 判断能否已满的棋盘上是否存在两两可消除的数字，若是，游戏继续；若否，游戏失败，结束

这样就可以做到不重不漏