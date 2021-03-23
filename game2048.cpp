#include<iostream>
#include"game2048.h"
#include<stdlib.h>
#include<time.h>
using namespace std;

void delay_time(double t)
{
	clock_t start = clock();
	clock_t delay = (clock_t)t * CLOCKS_PER_SEC;
	while (clock() - start < delay)
		continue;
}


        
