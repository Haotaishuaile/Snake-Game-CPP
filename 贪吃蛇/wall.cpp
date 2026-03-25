#include "wall.h"

void wall::set(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;

}

wall::wall()
{
	this->x1 = 0;
	this->y1 = 0;
	this->x2 = 0;
	this->y2 = 0;	
}

wall::~wall()
{
	
}



void wall::showwall()
{
	setfillcolor(BLACK);
	fillrectangle(x1, y1, x2, y2);
}
