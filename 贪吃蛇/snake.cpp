	#include "snake.h"



snake::snake()
{
	direction = ' ';
	taildirection = ' ';
	head = tail = NULL;
	lenth = 1;
}

snake::~snake()
{
	node* p = head;
	while (p != NULL)
	{
		node* q = p;
		p = p->next;
		delete q;
	}
}

void snake::showsnake()
{
	setfillcolor(GREEN);
	node* p = head;
	while (p != NULL)
	{
		if (p == head)
		{
			setfillcolor(RGB(218, 112, 214));
		}
		else
		{
			setfillcolor(RGB(199, 21, 133));
		}
		fillrectangle(p->x, p->y, p->x + snakewidth, p->y + snakewidth);
		p = p->next;
	}
}
node* creatnode(int x, int y)
{
	node* p = new(nothrow) node;
	if (p == NULL)
	{
		cout << "error" << endl;
		exit(1);
	}
	p->x = x;
	p->y = y;
	p->next = NULL;
	return p;
}
node* snake::addnode(int x, int y, node* head)
{
	node* p = creatnode(x, y);
	if (head == NULL)
	{
		head = p;
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
	lenth++;
	return head;
}

node* snake::creathead1()
{
	node* head1 = creatnode(head->x, head->y);
	node* cc = head;
	node* q = head1;
	while (cc->next != NULL)
	{
		cc = cc->next;
		node* aa = creatnode(cc->x, cc->y);
		q->next = aa;
		q = aa;
	}
	return head1;
}

void snake::move(char com)
{
	node* r = new(nothrow)node;
	if (r == NULL)
	{
		cout << "error" << endl;
		exit(1);
	}
	r->x =tail->x;
	r->y = tail->y;
	switch (com) {
	case'P':
	{

	}
	case'W':
	{
		
		node* p = tail;
		while (true)
		{
			node* q = head;
			while (q->next != NULL && q->next != p  )
			{
				q = q->next;
			}
			p->x = q->x;
			p->y = q->y;
			p = q;
			if (p == head)
			{
				break;
			}
		}
		if (direction == 'S')
		{
			com = 'S';
			head->y += snakewidth;
		}
		else
		{
			head->y -= snakewidth;
		}
		break;
	}
	case'S':
	{
		
		node* p = tail;
		while (true)
		{
			node* q = head;
			while (q->next != NULL && q->next != p)
			{
				q = q->next;
			}
			p->x = q->x;
			p->y = q->y;
			p = q;
			if (p == head)
			{
				break;
			}
		}
		if (direction == 'W')
		{
			com = 'W';
			head->y -= snakewidth;
		}
		else
		{
			head->y += snakewidth;
		}
		break;
	}
	case'A':
	{
		
		node* p = tail;
		while (true)
		{
			node* q = head;
			while (q->next != NULL && q->next != p )
			{
				q = q->next;
			}
			p->x = q->x;
			p->y = q->y;
			p = q;
			if (p == head)
			{
				break;
			}
		}
		if (direction == 'D')
		{
			com = 'D';
			head->x += snakewidth;
		}
		else
		{
			head->x -= snakewidth;
		}
		break;
	}
	case'D':
	{
		
		node* p = tail;
		while (true)
		{
			node* q = head;
			while (q->next != NULL && q->next != p)
			{
				q = q->next;
			}
			p->x = q->x;
			p->y = q->y;
			p = q;
			if (p == head)
			{
				break;
			}
		}
		if (direction == 'A')
		{
			com = 'A';
			head->x -= snakewidth;
		}
		else
		{
			head->x += snakewidth;
		}
		break;
	}
	default:
	{
		if (direction == ' ')
		{
			break;
		}
		else
		{
			switch (direction)
			{
			case'W':
			{
				
				node* p = tail;
				while (true)
				{
					node* q = head;
					while (q->next != NULL && q ->next != p  )
					{
						q = q->next;
					}
					p->x = q->x;
					p->y = q->y;
					p = q;
					if (p == head)
					{
						break;
					}
				}
				head->y -= snakewidth;
				break;
			}
			case'S':
			{
				
				node* p = tail;
				while (true)
				{
					node* q = head;
					while (q->next != NULL && q->next != p  )
					{
						q = q->next;
					}
					p->x = q->x;
					p->y = q->y;
					p = q;
					if (p == head)
					{
						break;
					}
				}
				head->y += snakewidth;
				break;
			}
			case'A':
			{
				
				node* p = tail;
				while (true)
				{
					node* q = head;
					while (q->next != NULL && q->next != p )
					{
						q = q->next;
					}
					p->x = q->x;
					p->y = q->y;
					p = q;
					if (p == head)
					{
						break;
					}
				}
				head->x -= snakewidth;
				break;
			}
			case'D':
			{
				
				node* p = tail;
				while (true)
				{
					node* q = head;
					while (q->next != NULL && q->next != p )
					{
						q = q->next;
					}
					p->x = q->x;
					p->y = q->y;
					p = q;
					if (p == head)
					{
						break;
					}
				}
				head->x += snakewidth;
				break;
			}
			}
		}
		break;
	}
	}
	if (com == 'W' || com == 'S' || com == 'A' || com == 'D')
	{
		direction = com;
	}
	int taildirectionx = tail->x - r->x;	
	int taildirectiony = tail->y - r->y;
	if (taildirectionx == 0 && taildirectiony == snakewidth)
	{
		taildirection = 'S';
	}
	else if (taildirectionx == 0 && taildirectiony == -snakewidth)
	{
		taildirection = 'W';
	}
	else if (taildirectionx == snakewidth && taildirectiony == 0)
	{
		taildirection = 'D';
	}
	else if (taildirectionx == -snakewidth && taildirectiony == 0)
	{
		taildirection = 'A';
	}
	else
	{
		taildirection = direction;
	}
	delete r;
}



void snake::init()
{
	int a = 0;
	int b = xzushu - 1;
	int c = 0;
	int d = yzushu - 1;
	int x = (rand() % (b - a + 1)) + a;
	int y = (rand() % (d - c + 1)) + c;
	int xkuan = (XWIDTH - jiemian - houdu * 2) / xzushu;
	int ykuan = (YHEIGHT - houdu * 2) / yzushu;
	tail = head = creatnode(xkuan * x + jiemian + houdu,ykuan * y + houdu);
	lenth = 1;
	direction = ' ';
}


bool snake::hitwall()
{
	if (head->x < (jiemian+houdu) || head->x >= XWIDTH - houdu || head->y < houdu || head->y >= YHEIGHT - houdu)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool snake::hitself()
{
	node* p = head->next;
	while (p != NULL)
	{
		if (head->x == p->x && head->y == p->y)
		{
			return true;
		}
		p = p->next;
	}
	return false;
}

bool snake::dead()
{
	if (hitself() || hitwall())
	{
		return true;
	}
	else
	{
		return false;
	}
}
