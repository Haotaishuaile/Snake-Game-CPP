#pragma once
#include"wall.h"
#include"snake.h"
#include"food.h"
#include<graphics.h>
#include"file.h"
#include<time.h>
#include<stdio.h>

#define XWIDTH 1000
#define YHEIGHT 800
#define jiemian 200
#define xzushu 38
#define yzushu 38
#define foodwidth 20
class guize
{
private:
	int fenshu;
	int history;
	int miao;
	int fen;
	int shi;
	int fuhao[xzushu][yzushu];
	int eatchishu;
	int fenshumnax ;
	int shengmingzhi;
	wall w1;
	wall w2;
	wall w3;
	wall w4;
	food f;
	snake s;
	file f1;
	clock_t start;
	clock_t finish;
public:
	void showfenshu();
	void showchangdu();
	void showhistory(int leixing);
	void showtime();
	void play();
	void init();
	void eatfood();
	guize();
	void checkfood(int i);
	void play1();
	void resnake();
	bool dead();
	void play2();
	void loadman();
	void showfoodgui(int leixing);
	void showshiti();
	void init1();
	void showshengming(int cishu, int all);
	void resnake1();
	void playhai();
	void showhaikesi(int i);
	file getfile()
	{
		return f1;
	}
};
