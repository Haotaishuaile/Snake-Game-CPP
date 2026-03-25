#include<iostream>
#include<graphics.h>
#include<conio.h>
#include"guize.h"
#include<ctime>
#pragma comment(lib,"Winmm.lib")
using namespace std;

void init()
{
	BeginBatchDraw();
	setbkcolor(WHITE);
	cleardevice();
	IMAGE img;
	loadimage(&img, _T("tanchishe.png"), 1000, 800);
	putimage(0, 0, &img);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(50, 0, _T("宋体"));
	outtextxy(400, 360, _T("基本模式"));
	outtextxy(400, 440, _T("海克斯模式"));
	outtextxy(400, 520, _T("游戏帮助"));
	outtextxy(400, 600, _T("历史记录"));
	outtextxy(400, 680, _T("切换账号"));
	outtextxy(400, 750, _T("退出游戏"));
	EndBatchDraw();
}
void init1()
{
	BeginBatchDraw();
	setbkcolor(WHITE);
	cleardevice();
	IMAGE img;
	loadimage(&img, _T("tanchishe.png"), 1000, 800);
	putimage(0, 0, &img);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(50, 0, _T("宋体"));
	outtextxy(400, 360, _T("入门模式"));
	outtextxy(400, 440, _T("进阶模式"));
	outtextxy(400, 520, _T("高级模式"));
	outtextxy(400, 600, _T("返回主界面"));
	EndBatchDraw();
}
void init2()
{
	BeginBatchDraw();
	setbkcolor(WHITE);
	cleardevice();
	IMAGE img;
	loadimage(&img, _T("tanchishe.png"), 1000, 800);
	putimage(0, 0, &img);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(40, 0, _T("宋体"));
	outtextxy(400, 360, _T("历史记录"));
	outtextxy(400, 420, _T("入门模式  得分："));
	outtextxy(400, 480, _T("进阶模式  得分："));
	outtextxy(400, 540, _T("高级模式  得分："));
	outtextxy(400, 600, _T("海克斯模式  得分："));
	outtextxy(400, 650, _T("返回"));
	outtextxy(500, 650, _T("删除记录"));
	outtextxy(400, 750, _T("（更多详细记录查看控制框）"));
	EndBatchDraw();
}
void init3()
{
	BeginBatchDraw();
	setbkcolor(WHITE);
	cleardevice();
	IMAGE img;
	loadimage(&img, _T("tanchishe.png"), 1000, 800);
	putimage(0, 0, &img);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(40, 0, _T("宋体"));
	outtextxy(400, 360, _T("游戏规则"));
	outtextxy(400, 440, _T("音乐设置"));
	outtextxy(50, 700, _T("返回"));
	EndBatchDraw();
}
int main()
{
	srand((unsigned)time(NULL));
	initgraph(1000, 800);
	init();

	MOUSEMSG msg; // 定义msg变量
	guize g;
	int denglu = 0;
	while (true)
	{
		if (denglu == 0)
		{
			g.loadman();
			denglu = 1;
		}
		msg = GetMouseMsg(); // 获取鼠标消息
		if (msg.uMsg == WM_LBUTTONDOWN) // 判断是否为鼠标左键按下消息
		{
			if (msg.x > 400 && msg.x < 600 && msg.y>360 && msg.y < 400)
			{
				init1();
				MOUSEMSG msg1;
				while (true)
				{
					msg1 = GetMouseMsg();
					if (msg1.uMsg == WM_LBUTTONDOWN)
					{
						if (msg1.x > 400 && msg1.x < 600 && msg1.y>360 && msg1.y < 400)
						{
							g.play();
							init1();
							continue;
						}
						else if (msg1.x > 400 && msg1.x < 600 && msg1.y>440 && msg1.y < 480)
						{
							g.play1();
							init1();
							continue;
						}
						else if (msg1.x > 400 && msg1.x < 600 && msg1.y>520 && msg1.y < 560)
						{
							g.play2();
							init1();
							continue;
						}
						else if (msg1.x > 400 && msg1.x < 600 && msg1.y>600 && msg1.y < 640)
						{
							break;
						}
					}
				}
				init();
				continue;
			}
			else if (msg.x > 400 && msg.x < 600 && msg.y>440 && msg.y < 480)
			{
				g.playhai();
				init();
				continue;
			}
			else if (msg.x > 400 && msg.x < 600 && msg.y>520 && msg.y < 560)
			{
				init3();
				MOUSEMSG msg1;
				while (true)
				{
					msg1 = GetMouseMsg();
					if (msg1.uMsg == WM_LBUTTONDOWN)
					{
						if (msg1.x > 400 && msg1.x < 600 && msg1.y>360 && msg1.y < 400)
						{
							setbkcolor(WHITE);
							cleardevice();
							IMAGE img;
							loadimage(&img, _T("tanchishe.png"), 1000, 800);
							putimage(0, 0, &img);
							setbkmode(TRANSPARENT);
							settextcolor(BLACK);
							settextstyle(40, 0, _T("宋体"));
							outtextxy(50, 50, _T("贪吃蛇操作规则如下"));
							outtextxy(50, 700, _T("返回"));
							settextstyle(25, 0, _T("宋体"));
							outtextxy(50, 100, _T("1.基础模式分为入门模式和进阶模式以及高级模式，初始金币为4，贪吃蛇的长度为1"));
							outtextxy(50, 150, _T("2.按键盘上的大写方向键控制蛇的移动方向,贪吃蛇的长度每增加一节，金币数增加1，"));
							outtextxy(50, 200, _T("贪吃蛇的速度也会增加。"));
							outtextxy(50, 250, _T("3.所有模式下有两种类型的金币，并且只要每达到一定数目的金币获取就会生成高级金币！"));
							outtextxy(50, 300, _T("4.基础模式下蛇只要触碰到墙壁或者自己就会游戏结束"));
							outtextxy(50, 350, _T("5.进阶模式下蛇触碰到墙壁或者自己不会结束游戏，相应的蛇的尸体会变成墙壁，"));
							outtextxy(50, 400, _T("直到撞墙次数>10，或剩余空间不足以生成新的蛇和食物为止。"));
							outtextxy(50, 450, _T("6.高级模式下蛇触碰到墙壁或者自己不会结束游戏，相应的蛇的尸体会变成金币，"));
							outtextxy(50, 500, _T("直到撞墙次数>5，或剩余空间不足以生成新的蛇和食物为止。"));
							outtextxy(50, 550, _T("神秘的宝藏！  在地图的一些区域，会有相应的宝藏等待你发现，他们或许是100金币......"));
							outtextxy(50, 600, _T("海克斯模式：你拥有5条生命，你死亡后分数不会消失，而是会叠加，"));
							outtextxy(50, 650, _T("在1分钟，2.30以及4分钟会弹出相应的海克斯供你选择。"));
							MOUSEMSG msg2;
							while (true)
							{
								msg2 = GetMouseMsg();
								if (msg2.uMsg == WM_LBUTTONDOWN)
								{
									if (msg2.x > 50 && msg2.x < 150 && msg2.y>700 && msg2.y < 750)
									{
										break;
									}
								}
							}
							init3();
							continue;
						}
						else if (msg1.x > 400 && msg1.x < 600 && msg1.y>440 && msg1.y < 480)
						{
							setbkcolor(WHITE);
							cleardevice();
							IMAGE img;
							loadimage(&img, _T("tanchishe.png"), 1000, 800);
							putimage(0, 0, &img);
							setbkmode(TRANSPARENT);
							settextcolor(BLACK);
							settextstyle(40, 0, _T("宋体"));
							outtextxy(400, 360, _T("Glorious morning"));
							outtextxy(400, 440, _T("多远都要在一起"));
							outtextxy(400, 520, _T("青花瓷"));
							outtextxy(400, 600, _T("卜卦"));
							outtextxy(400, 680, _T("关闭音乐"));
							outtextxy(50, 700, _T("返回"));
							MOUSEMSG msg2;
							while (true)
							{
								msg2 = GetMouseMsg();
								if (msg2.uMsg == WM_LBUTTONDOWN)
								{
									if (msg2.x > 400 && msg2.x < 800 && msg2.y>360 && msg2.y < 400)
									{
										mciSendString(_T("close bkmusic"), NULL, 0, NULL);
										mciSendString(_T("open beijingmusic.mp3 alias bkmusic"), NULL, 0, NULL);
										mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
									}
									else if (msg2.x > 400 && msg2.x < 800 && msg2.y>440 && msg2.y < 480)
									{
										mciSendString(_T("close bkmusic"), NULL, 0, NULL);
										mciSendString(_T("open duoyuandouyaozaiyiqi.mp3 alias bkmusic"), NULL, 0, NULL);
										mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
									}
									else if (msg2.x > 400 && msg2.x < 700 && msg2.y>520 && msg2.y < 560)
									{
										mciSendString(_T("close bkmusic"), NULL, 0, NULL);
										mciSendString(_T("open 青花瓷.mp3 alias bkmusic"), NULL, 0, NULL);
										mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
									}
									else if (msg2.x > 400 && msg2.x < 600 && msg2.y>600 && msg2.y < 640)
									{
										mciSendString(_T("close bkmusic"), NULL, 0, NULL);
										mciSendString(_T("open bugua.mp3 alias bkmusic"), NULL, 0, NULL);
										mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
									}
									else if (msg2.x > 400 && msg2.x < 600 && msg2.y>680 && msg2.y < 720)
									{
										mciSendString(_T("close bkmusic"), NULL, 0, NULL);
									}
									else
									if (msg2.x > 50 && msg2.x < 150 && msg2.y>700 && msg2.y < 750)
									{
										break;
									}
								}
							}
							init3();
							continue;
						}
						else if (msg1.x > 400 && msg1.x < 600 && msg1.y>520 && msg1.y < 560)
						{
							
							continue;
						}
						else if (msg1.x > 50 && msg1.x < 150 && msg1.y>700 && msg1.y < 750)
						{
							break;
						}
					}
				}
				init();
				continue;
			}
			else if (msg.x > 400 && msg.x < 600 && msg.y>600 && msg.y < 640)
			{
				file f = g.getfile();
				init2();
				f.loadjilu();
				MOUSEMSG msg3;
				while (true)
				{
					msg3 = GetMouseMsg();
					if (msg3.uMsg == WM_LBUTTONDOWN)
					{

						if (msg3.x > 400 && msg3.x < 500 && msg3.y>650 && msg3.y < 700)
						{
							break;
						}
						else if (msg3.x > 500 && msg3.x < 600 && msg3.y>650 && msg3.y < 700)
						{
							HWND hnd = GetHWnd();
							if (MessageBox(hnd, _T("请在控制台查询数据后输入你要删除的数据，是否现在就开始删除？"), _T("友情提示"), MB_OKCANCEL) == IDOK)
							{
								int line;
								cout << "请输入你要删除的行数" << endl;
								cin >> line;
								f.shanchu(line-1);
								cout << "删除完的记录如下：" << endl;
								init2();
								f.loadjilu();
							}
						}
					}
					
				}
				init();
				continue;
			}
			else if (msg.x > 400 && msg.x < 600 && msg.y>680 && msg.y < 720)
			{
				denglu = 0;
				continue;
			}
			else if (msg.x > 400 && msg.x < 600 && msg.y>750 && msg.y < 800)
			{
				HWND hwnd = GetHWnd();
				if (MessageBox(hwnd, _T("真的要退出吗？"), _T("提示"), MB_YESNO) == IDYES)
				{
					break;
				}
				else
					continue;
			}
		}
	}
	closegraph();
	return 0;
}