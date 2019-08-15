#include<iostream>
#include<graphics.h>
//#include<list>
#include<time.h>
#include<conio.h>
#include <stdio.h>
using namespace std;
char key;
char a[5];
int score=0;
class rect
{
public:
	int left;
	int top;
	int right;
	int bottom;//初始化为0
	int num;//编号1~4
	int exist;//初始化为1
rect(int key)
{
	num=key;
	exist=1;
	bottom=0;
	top=-80;
	left=(key-1)*50;
	right=key*50;
	setfillcolor(BLACK);
	fillrectangle(left,top,right,bottom);
}
rect()
{}
void move()
{
	if(exist==0)
	{
		clearrectangle(left,0,right,400);
		return;
	}
	else
	top++;
	bottom++;
	clearrectangle(left,0,right,top-1);
	clearrectangle(right+1,0,200,400);
	clearrectangle(0,0,left-1,400);
	setfillcolor(BLACK);
	fillrectangle(left,top,right,bottom);
	clearrectangle(left,bottom+1,right,400);
}
};
DWORD WINAPI ThreadFun1(LPVOID pM) 
{
	setbkcolor(WHITE);
	//typedef list<rect> LISTINT;
	//LISTINT r_list;
	//LISTINT::iterator i;
	int p;
	srand((unsigned)time(0));
	while(1)
	{
		
		p=rand()%4+1;
		rect r(p);
		while(1)
		{
			Sleep(1);
				r.move();	//此时不能用.来调用类成员函数要用->来调用
			if(r.exist==0) break;
			switch(key)
			{
			case 'a':
				if(r.num==1) 
				{
					r.exist=0;
					score++; 
					setbkcolor(BLACK);
					sprintf(a,"%d",score);
					outtextxy(205,30,a);
					setbkcolor(WHITE);
				}
				else 
					return 0;
				break;
			case 's':
				if(r.num==2) 
				{
					r.exist=0;
					score++; 
					setbkcolor(BLACK);
					sprintf(a,"%d",score);
					outtextxy(205,30,a);
					setbkcolor(WHITE);
				}
				else 
					return 0;
				break;
			case 'd':
				if(r.num==3) 
				{
					r.exist=0;
					score++; 
					setbkcolor(BLACK);
					sprintf(a,"%d",score);
					outtextxy(205,30,a);
					setbkcolor(WHITE);
				}
				else 
					return 0;
				break;
			case 'f':
				if(r.num==4) 
				{
					r.exist=0;
					score++; 
					setbkcolor(BLACK);
					sprintf(a,"%d",score);
					outtextxy(205,30,a);
					setbkcolor(WHITE);
				}
				else 
					return 0;
				break;
			}
			key=0;
		}
	}
} 
DWORD WINAPI ThreadFun2(LPVOID pM)
{
	setbkcolor(WHITE);
	while(1)
	{
		key=getch();
	}
}
void main()
{
	initgraph(250,400);
	outtextxy(205,10,"得分:");
    HANDLE handle1 = CreateThread(NULL, 0, ThreadFun1, &key, 0,NULL);  
    HANDLE handle2 = CreateThread(NULL, 0, ThreadFun2, NULL, 0,NULL);
    WaitForSingleObject(handle1, INFINITE);  
    WaitForSingleObject(handle2, INFINITE);  
}