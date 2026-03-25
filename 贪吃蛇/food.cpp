#include "food.h"



food::food()
{
	this->x = 0;
	this->y = 0;
	this->biaoji = 0;
}

food::~food()
{
}

void food::setfood()
{
	int a = 0;
	int b = xzushu - 1;
	int c = 0;
	int d = yzushu - 1;
	int x = (rand() % (b - a + 1)) + a;
	int y = (rand() % (d - c + 1)) + c;
	int xkuan = (XWIDTH - jiemian - houdu * 2) / xzushu;
	int ykuan = (YHEIGHT - houdu * 2) / yzushu;
	this->x = xkuan * x + jiemian + houdu;
	this->y=ykuan* y + houdu;
}



int food::getbiaofood()
{
	return biaoji;
}

