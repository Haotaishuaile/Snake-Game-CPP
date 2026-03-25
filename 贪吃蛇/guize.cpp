#include "guize.h"

void guize::init1()
{
	s.init();
	start = clock();
	for (int i = 0; i < xzushu; i++)
	{
		for (int j = 0; j < yzushu; j++)
		{
			fuhao[i][j] = 0;
		}
	}
	int a = 0;
	int b = xzushu - 1;
	int c = 0;
	int d = yzushu - 1;
	int x = (rand() % (b - a + 1)) + a;
	int y = (rand() % (d - c + 1)) + c;
	fuhao[x][y] = -100;
	fuhao[5][20] = -100;
	fuhao[13][14] = -100;
	s.showsnake();
	f.biaoji = 0;
	eatchishu = 0;
	fenshumnax = 0;
}

void guize::playhai()
{
	init1();
	int cishu = 0;
	int shike = 0;
	int chushi = 4;
	int biaojishiwangeryi = 0;
	int biaojixunjiebufa = 0;
	int biaojiligunli = 0;
	int biaojiqijixingzhe = 0;
	int biaojijizhiranshao = 0;
	int biaojigaoduanzuizu = 0;
	int sudu = 80;
	int xuanze = 0;
	int ranshaoshike;
	fenshu = 0;

	IMAGE bg_img;
	loadimage(&bg_img, _T("xingkong.png"), 1000, 800);

	while (1)
	{
		char com = ' ';
		BeginBatchDraw();

		putimage(0, 0, &bg_img);
		setbkmode(TRANSPARENT);
		init();
		checkfood(chushi);
		showfoodgui(1);
		shike = (finish - start) / CLOCKS_PER_SEC;
		if (shike == 60 || shike == 150 || shike == 240)
		{
			s.direction = ' ';
			HWND hnd = GetHWnd();
			MessageBox(hnd, _T("海克斯选择，请在控制端输入对应序号"), _T("海克斯时刻"), MB_OK);
			int x = (rand() % (3 - 1 + 1)) + 1;
			showhaikesi(x);
			cin >> xuanze;
			if (x == 1)
			{
				if (xuanze == 1)
				{
					biaojishiwangeryi = 1;
					cishu = 4;
				}
				else if (xuanze == 2)
				{
					fenshu += 50;
					chushi = 8;
				}
				else if (xuanze == 3)
				{
					sudu = 50;
					biaojixunjiebufa = 1;
				}
			}
			else if (x == 2)
			{
				if (xuanze == 1)
				{
					biaojiligunli = 1;
				}
				else if (xuanze == 2)
				{
					fenshu += 20;
					cishu--;
				}
				else if (xuanze == 3)
				{
					biaojiqijixingzhe = 1;
				}
			}
			else if (x == 3)
			{
				if (xuanze == 1)
				{
					biaojijizhiranshao = 1;
					ranshaoshike = shike;
				}
				else if (xuanze == 2)
				{
					cishu++;
					fenshu = fenshu * 2;
				}
				else if (xuanze == 3)
				{
					biaojigaoduanzuizu = 1;
				}
			}
		}

		if (GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000) com = 'W';
		else if (GetAsyncKeyState('S') & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000) com = 'S';
		else if (GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000) com = 'A';
		else if (GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000) com = 'D';
		else if (GetAsyncKeyState('P') & 0x8000) com = 'P';

		if (com == 'P')
		{
			f1.savejilu(3, fenshu);
			break;
		}
		s.move(com);
		int eat = eatchishu;
		eatfood();
		if (biaojishiwangeryi == 1 && eatchishu > eat)
		{
			fenshu += 5;
		}
		if (biaojixunjiebufa == 1 && eatchishu > eat)
		{
			fenshu += 1;
		}
		if (biaojiligunli == 1)
		{
			int lixi = fenshu / 100;
			fenshu += lixi;
		}
		if (biaojiqijixingzhe == 1 && shike % 2 == 0)
		{
			fenshu += 2;
		}
		if (biaojijizhiranshao == 1)
		{
			cishu = 0;
			if (shike - ranshaoshike == 120)
			{
				cishu = 5;
			}
		}
		if (biaojigaoduanzuizu == 1)
		{
			if (eatchishu % 2 != 0)
			{
				eatchishu++;
			}
		}
		if (s.dead() || cishu == 5)
		{
			cishu++;
			if (cishu > 4)
			{
				f1.savejilu(3, fenshu);
				break;
			}
			resnake1();
		}
		s.showsnake();
		showfenshu();
		showchangdu();
		showtime();
		showshengming(cishu, 4);
		showhistory(3);
		EndBatchDraw();
		Sleep(max(sudu, 150 - fenshu * 0.5));
	}
	HWND hnd = GetHWnd();
	MessageBox(hnd, _T("游戏结束"), _T("啊哦"), MB_OK);
}

void guize::showhaikesi(int i)
{
	if (i == 1)
	{
		cout << "           死亡而已           |           金钱至上           |           迅捷步伐           \n";
		cout << "你的生命被设置为1，但是你每次  场上每次可生成的金币被设置为8，你的最大速度变得更快，你获取的\n";
		cout << "获取金币后会额外获取五金币。   获得50金币。                   金币会因此而增大。            \n";
	}
	else if (i == 2)
	{
		cout << "           利滚利             |           寻仙问道           |           奇迹行者           \n";
		cout << "你每拥有100金币，每次就可以额  额外获得一条生命，并获得20金币 你每2秒钟都会得到2金币         \n";
		cout << "外获得1金币的利息。                                                                         \n";
	}
	else if (i == 3)
	{
		cout << "           极致燃烧           |             掀桌             |           高端购物           \n";
		cout << "你将在2分钟后迎来死亡，但在此  立刻损失一条生命，但你的金币会 你所有生成的金币都会是10及以上\n";
		cout << "期间你可以获得无穷的生命。     翻倍。                                                       \n";
	}
}

void guize::play()
{
	init1();

	IMAGE bg_img;
	loadimage(&bg_img, _T("xingkong.png"), 1000, 800);

	while (1)
	{
		char com = ' ';
		BeginBatchDraw();

		putimage(0, 0, &bg_img);
		setbkmode(TRANSPARENT);
		init();
		checkfood(4);
		showfoodgui(0);

		if (GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000) com = 'W';
		else if (GetAsyncKeyState('S') & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000) com = 'S';
		else if (GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000) com = 'A';
		else if (GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000) com = 'D';
		else if (GetAsyncKeyState('P') & 0x8000) com = 'P';

		if (com == 'P')
		{
			f1.savejilu(0, fenshu);
			break;
		}
		s.move(com);
		eatfood();
		if (s.dead())
		{
			f1.savejilu(0, fenshu);
			break;
		}
		s.showsnake();
		showfenshu();
		showchangdu();
		showtime();
		showhistory(0);
		EndBatchDraw();
		Sleep(max(70, 150 - fenshu * 0.5));
	}
	HWND hnd = GetHWnd();
	MessageBox(hnd, _T("游戏结束"), _T("啊哦"), MB_OK);
}

void guize::play1()
{
	init1();
	int cishu = 0;
	char com = ' ';

	IMAGE bg_img;
	loadimage(&bg_img, _T("xingkong.png"), 1000, 800);

	while (1)
	{
		char com = ' ';
		BeginBatchDraw();

		putimage(0, 0, &bg_img);
		setbkmode(TRANSPARENT);
		init();
		checkfood(4);
		showfoodgui(1);
		node* draw = s.creathead1();

		if (GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000) com = 'W';
		else if (GetAsyncKeyState('S') & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000) com = 'S';
		else if (GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000) com = 'A';
		else if (GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000) com = 'D';
		else if (GetAsyncKeyState('P') & 0x8000) com = 'P';

		if (com == 'P')
		{
			node* bb = draw;
			while (bb != NULL)
			{
				node* q = bb;
				bb = bb->next;
				delete q;
			}
			f1.savejilu(1, fenshumnax);
			break;
		}
		s.move(com);
		eatfood();
		if (s.dead() || dead())
		{
			cishu++;
			int shumu = 0;
			for (int i = 0; i < xzushu; i++)
			{
				for (int j = 0; j < yzushu; j++)
				{
					if (fuhao[i][j] != 0)
					{
						shumu++;
					}
				}
			}
			if (shumu == xzushu * yzushu || cishu > 10)
			{
				f1.savejilu(1, fenshumnax);
				node* bb = draw;
				while (bb != NULL)
				{
					node* q = bb;
					bb = bb->next;
					delete q;
				}
				break;
			}
			node* p = draw;
			while (p != NULL)
			{
				int realx = (p->x - jiemian - houdu) / houdu;
				int realy = (p->y - houdu) / houdu;
				fuhao[realx][realy] = 1;
				p = p->next;
			}
			s.~snake();
			resnake();
		}
		s.showsnake();
		showshengming(cishu, 10);
		showshiti();
		showfenshu();
		showchangdu();
		showtime();
		showhistory(1);
		EndBatchDraw();
		node* bb = draw;
		while (bb != NULL)
		{
			node* q = bb;
			bb = bb->next;
			delete q;
		}
		Sleep(max(70, 150 - fenshu * 0.5));
	}
	HWND hnd = GetHWnd();
	MessageBox(hnd, _T("游戏结束"), _T("啊哦"), MB_OK);
}

void guize::play2()
{
	init1();
	int cishu = 0;

	IMAGE bg_img;
	loadimage(&bg_img, _T("xingkong.png"), 1000, 800);

	while (1)
	{
		char com = ' ';
		BeginBatchDraw();

		putimage(0, 0, &bg_img);
		setbkmode(TRANSPARENT);
		init();
		checkfood(4);
		showfoodgui(1);
		node* draw = s.creathead1();

		if (GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000) com = 'W';
		else if (GetAsyncKeyState('S') & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000) com = 'S';
		else if (GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000) com = 'A';
		else if (GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000) com = 'D';
		else if (GetAsyncKeyState('P') & 0x8000) com = 'P';

		if (com == 'P')
		{
			node* bb = draw;
			while (bb != NULL)
			{
				node* q = bb;
				bb = bb->next;
				delete q;
			}
			f1.savejilu(2, fenshumnax);
			break;
		}
		s.move(com);
		eatfood();
		if (s.dead() || dead())
		{
			cishu++;
			int shumu = 0;
			for (int i = 0; i < xzushu; i++)
			{
				for (int j = 0; j < yzushu; j++)
				{
					if (fuhao[i][j] != 0)
					{
						shumu++;
					}
				}
			}
			if (shumu == xzushu * yzushu || cishu > 5)
			{
				f1.savejilu(2, fenshumnax);
				node* bb = draw;
				while (bb != NULL)
				{
					node* q = bb;
					bb = bb->next;
					delete q;
				}
				break;
			}
			node* p = draw;
			while (p != NULL)
			{
				int realx = (p->x - jiemian - houdu) / houdu;
				int realy = (p->y - houdu) / houdu;
				fuhao[realx][realy] = -1;
				f.biaoji++;
				p = p->next;
			}
			s.~snake();
			resnake();
		}
		s.showsnake();
		showshengming(cishu, 5);
		showfenshu();
		showchangdu();
		showtime();
		showhistory(2);
		EndBatchDraw();
		node* bb = draw;
		while (bb != NULL)
		{
			node* q = bb;
			bb = bb->next;
			delete q;
		}
		Sleep(max(70, 150 - fenshu * 0.5));

	}
	HWND hnd = GetHWnd();
	MessageBox(hnd, _T("游戏结束"), _T("啊哦"), MB_OK);
}

void guize::loadman()
{
	f1.loadman();
}

void guize::showshiti()
{
	for (int i = 0; i < xzushu; i++)
	{
		for (int j = 0; j < yzushu; j++)
		{
			if (fuhao[i][j] == 1)
			{
				setfillcolor(BLACK);
				fillrectangle(i * houdu + jiemian + houdu, j * houdu + houdu, i * houdu + jiemian + houdu + foodwidth, j * houdu + houdu + foodwidth);
			}
		}
	}
}

void guize::resnake()
{
	while (true)
	{
		s.init();
		int realx = (s.getheadx() - jiemian - houdu) / houdu;
		int realy = (s.getheady() - houdu) / houdu;
		if (fuhao[realx][realy] == 1)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	s.direction = ' ';
	fenshu = 0;
}

void guize::resnake1()
{
	while (true)
	{
		s.init();
		int realx = (s.getheadx() - jiemian - houdu) / houdu;
		int realy = (s.getheady() - houdu) / houdu;
		if (fuhao[realx][realy] == 1)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	s.direction = ' ';
}

bool guize::dead()
{
	int realx = (s.getheadx() - jiemian - houdu) / houdu;
	int realy = (s.getheady() - houdu) / houdu;
	if (fuhao[realx][realy] == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void guize::showshengming(int cishu, int all)
{
	shengmingzhi = all - cishu;
	settextcolor(BLUE);
	settextstyle(30, 0, _T("宋体"));
	outtextxy(0, 400, _T("剩余生命值："));
	TCHAR dd[10];
	_stprintf_s(dd, _T("%d"), shengmingzhi);
	outtextxy(0, 450, dd);
	outtextxy(0, 500, _T("P键退出"));
}

void guize::showfenshu()
{
	settextcolor(BLUE);
	settextstyle(30, 0, _T("宋体"));
	outtextxy(0, 0, _T("分数："));
	TCHAR s[10];
	_stprintf_s(s, _T("%05d"), fenshu);
	outtextxy(100, 0, s);
}

void guize::showchangdu()
{
	settextcolor(BLUE);
	settextstyle(30, 0, _T("宋体"));
	outtextxy(0, 100, _T("长度："));
	TCHAR aa[10];
	_stprintf_s(aa, _T("%03d"), s.getlenth());
	outtextxy(100, 100, aa);
}

void guize::showhistory(int leixing)
{
	history = f1.load(leixing);
	if (fenshumnax < fenshu)
	{
		fenshumnax = fenshu;
	}
	history = max(history, fenshumnax);
	settextcolor(BLUE);
	settextstyle(30, 0, _T("宋体"));
	outtextxy(0, 300, _T("历史最高分："));
	TCHAR bb[10];
	_stprintf_s(bb, _T("%05d"), history);
	outtextxy(0, 350, bb);
}

void guize::showtime()
{
	settextcolor(BLUE);
	settextstyle(30, 0, _T("宋体"));
	outtextxy(0, 200, _T("时间："));
	TCHAR cc[10];
	miao = 0;
	fen = 0;
	shi = 0;
	finish = clock();
	miao = (finish - start) / CLOCKS_PER_SEC;
	while (miao >= 60)
	{
		miao -= 60;
		fen++;
	}
	while (fen >= 60)
	{
		fen -= 60;
		shi++;
	}
	_stprintf_s(cc, _T("%d:%02d:%02d"), shi, fen, miao);
	outtextxy(80, 200, cc);
}

void guize::checkfood(int i)
{
	if (f.getbiaofood() < i)
	{
		f.setfood();
		while (true)
		{
			int realx = (f.getx() - jiemian - houdu) / houdu;
			int realy = (f.gety() - houdu) / houdu;
			if (fuhao[realx][realy] == 0)
			{
				break;
			}
			else if (fuhao[realx][realy] != 0)
			{
				f.setfood();
			}
		}
		node* p = s.head;
		while (p != NULL)
		{
			if (p->x == f.getx() && p->y == f.gety())
			{
				f.setfood();
				p = s.head;
			}
			else
			{
				p = p->next;
			}
		}
		if (eatchishu % 2 == 0)
		{
			fuhao[(f.getx() - jiemian - houdu) / houdu][(f.gety() - houdu) / houdu] = -2;
			f.biaoji++;
		}
		else if (eatchishu % 9 == 0)
		{
			fuhao[(f.getx() - jiemian - houdu) / houdu][(f.gety() - houdu) / houdu] = -3;
			f.biaoji++;
		}
		else
		{
			fuhao[(f.getx() - jiemian - houdu) / houdu][(f.gety() - houdu) / houdu] = -1;
			f.biaoji++;
		}
	}
}

void guize::showfoodgui(int leixing)
{
	static IMAGE coin_img;
	static bool is_coin_loaded = false;
	if (!is_coin_loaded)
	{
		loadimage(&coin_img, _T("jinbi.png"), foodwidth + 2, foodwidth + 2);
		is_coin_loaded = true;
	}

	for (int i = 0; i < xzushu; i++)
	{
		for (int j = 0; j < yzushu; j++)
		{
			if (fuhao[i][j] == -1)
			{
				if (leixing == 1)
				{
					setfillcolor(LIGHTRED);
					fillrectangle(i * houdu + jiemian + houdu, j * houdu + houdu, i * houdu + jiemian + houdu + foodwidth, j * houdu + houdu + foodwidth);
				}
				else if (leixing == 0)
				{
					putimage(i * houdu + jiemian + houdu, j * houdu + houdu, &coin_img);
				}
			}
			else if (fuhao[i][j] == -2)
			{
				if (leixing == 1)
				{
					setfillcolor(LIGHTBLUE);
					fillrectangle(i * houdu + jiemian + houdu, j * houdu + houdu, i * houdu + jiemian + houdu + foodwidth, j * houdu + houdu + foodwidth);
				}
				else if (leixing == 0)
				{
					putimage(i * houdu + jiemian + houdu, j * houdu + houdu, &coin_img);
				}
			}
			else if (fuhao[i][j] == -3)
			{
				if (leixing == 1)
				{
					setfillcolor(LIGHTGREEN);
					fillrectangle(i * houdu + jiemian + houdu, j * houdu + houdu, i * houdu + jiemian + houdu + foodwidth, j * houdu + houdu + foodwidth);
				}
				else if (leixing == 0)
				{
					putimage(i * houdu + jiemian + houdu, j * houdu + houdu, &coin_img);
				}
			}
		}
	}
}

void guize::init()
{
	w1.set(jiemian, 0, XWIDTH, houdu);
	w2.set(jiemian, YHEIGHT - houdu, XWIDTH, YHEIGHT);
	w3.set(jiemian, houdu, jiemian + houdu, YHEIGHT - houdu);
	w4.set(XWIDTH - houdu, houdu, XWIDTH, YHEIGHT - houdu);
	w1.showwall();
	w2.showwall();
	w3.showwall();
	w4.showwall();
}

void guize::eatfood()
{
	int realx = (s.getheadx() - jiemian - houdu) / houdu;
	int realy = (s.getheady() - houdu) / houdu;
	if ((s.getheadx() == f.getx() && s.getheady() == f.gety()) || fuhao[realx][realy] == -1 || fuhao[realx][realy] == -2 || fuhao[realx][realy] == -3 || fuhao[realx][realy] == -100)
	{

		if (fuhao[realx][realy] == -1)
		{
			eatchishu++;
			fenshu += 5;
			fuhao[realx][realy] = 0;
			f.biaoji--;
		}
		else if (fuhao[realx][realy] == -2)
		{
			eatchishu++;
			fenshu += 10;
			fuhao[realx][realy] = 0;
			f.biaoji--;
		}
		else if (fuhao[realx][realy] == -3)
		{
			eatchishu++;
			fenshu += 20;
			fuhao[realx][realy] = 0;
			f.biaoji--;
		}
		else if (fuhao[realx][realy] == -100)
		{
			fenshu += 100;
			fuhao[realx][realy] = 0;
			HWND hnd = GetHWnd();
			MessageBox(hnd, _T("恭喜你，你捡到了100元"), _T("金钱至上！"), MB_OK);
			s.direction = ' ';
		}
		switch (s.gettaildirection())
		{
		case'W':
		{
			s.head = s.addnode(s.gettailx(), s.gettaily() + snakewidth, s.head);
			break;
		}
		case'S':
			s.head = s.addnode(s.gettailx(), s.gettaily() - snakewidth, s.head);
			break;
		case'A':
			s.head = s.addnode(s.gettailx() + snakewidth, s.gettaily(), s.head);
			break;
		case'D':
			s.head = s.addnode(s.gettailx() - snakewidth, s.gettaily(), s.head);
			break;
		}
	}
}

guize::guize()
{
	this->fenshu = 0;
	this->history = 0;
	miao = 0;
	fen = 0;
	shi = 0;
	eatchishu = 0;
	fenshumnax = 0;

	for (int i = 0; i < xzushu; i++)
	{
		for (int j = 0; j < yzushu; j++)
		{
			fuhao[i][j] = 0;
		}
	}
}