#pragma once
#include<graphics.h>
#include<conio.h>


#define houdu 20

class wall
{
	int x1;
	int y1;
	int x2;
	int y2;
public:
	void set(int x1, int y1, int x2, int y2);
	wall();
	~wall();
	void showwall();
	int getx1()
	{
		return x1;
	}
	int gety1()
	{
		return y1;
	}
};

