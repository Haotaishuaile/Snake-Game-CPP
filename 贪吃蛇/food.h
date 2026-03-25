#pragma once
#include<graphics.h>

#define XWIDTH 1000
#define YHEIGHT 800
#define jiemian 200
#define xzushu 38
#define yzushu 38
#define houdu 20

#define foodwidth 20
class food
{
	int x;
	int y;
	int biaoji;
public:
	friend class guize;
	food();
	~food();
	void setfood();
	int getbiaofood();
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
};

