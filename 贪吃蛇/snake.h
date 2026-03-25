#pragma once
#include<graphics.h>
#include<iostream>
#include <conio.h>

#define XWIDTH 1000
#define YHEIGHT 800
#define jiemian 200
#define xzushu 38
#define yzushu 38
#define houdu 20

#define snakewidth 20

using namespace std;
struct node
{
	int x;
	int y;
	node* next;
};
class snake
{
	int lenth;
	char direction;
	char taildirection;
	node* head;
	node* tail;
public:
	friend class guize;
	snake();
	~snake();
	void showsnake();
	node* addnode(int x, int y, node* head);
	void move(char com);
	node* creathead1();
	void init();
	bool hitwall();
	bool hitself();
	bool dead();
	char gettaildirection()
	{
		return taildirection;
	}
	int getlenth()
	{
		return lenth;
	}
	int getheadx()
	{
		return head->x;
	}
	int getheady()
	{
		return head->y;
	}
	int gettailx()
	{
		return tail->x;
	}
	int gettaily()
	{
		return tail->y;
	}
	

};
