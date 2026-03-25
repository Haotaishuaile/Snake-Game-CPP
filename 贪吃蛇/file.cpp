#include "file.h"

file::file()
{
	Name = "";
	Id = "";
}
void file::savejilu(int leixing, int mark)
{
	ofstream ofs;
	string tm = Name +"jilu.txt";
	ofs.open(tm, ios::app);
	if (leixing == 0)
	{
		ofs << "入门模式  用户名：";
	}
	else if (leixing == 1)
	{
		ofs << "进阶模式  用户名：";
	}
	else if (leixing == 2)
	{
		ofs << "高级模式  用户名：";
	}
	else if (leixing == 3)
	{
		ofs << "海克斯模式  用户名：";
	}
	ofs << Name << " 得分：";
	ofs << mark << endl;
}
void file::loadjilu()
{
	wifstream wifs;
	string tm = Name + "jilu.txt";
	wifs.open(tm);
	if (!wifs.is_open())
	{
		cout << "读取文件失败！" << endl;
		return;
	}
	wstring str;

	TCHAR max1[10];
	int mmax1 = load(0);
	_stprintf_s(max1, _T("%d"),mmax1 );
	outtextxy(700, 420,max1);
	TCHAR max2[10];
	int mmax2 = load(1);
	_stprintf_s(max2, _T("%d"), mmax2);
	outtextxy(700, 480, max2);
	TCHAR max3[10];
	int mmax3 = load(2);
	_stprintf_s(max3, _T("%d"), mmax3);
	outtextxy(700, 540, max3);
	TCHAR max4[10];
	int mmax4 = load(3);
	_stprintf_s(max4, _T("%d"), mmax4);
	outtextxy(750, 600, max4);
	while (getline(wifs, str))
	{
		wcout << str<< endl;
	}
	wifs.close();
}
void file::shanchu(int line)
{
	ifstream ifs;
	string tm = Name + "jilu.txt";
	ifs.open(tm);
	if (!ifs.is_open())
	{
		cout << "读取文件失败！" << endl;
		return;
	}
	string allthedata = "";
	string str;
	int i = 0;
	while (getline(ifs, str))
	{
		if (i != line)
		{
			allthedata += str;
			allthedata += "\n";
		}
		i++;
	}
	ifs.close();
	ofstream ofs;
	ofs.open(tm);
	if (!ofs.is_open())
	{
		cout << "打开文件失败！" << endl;
		return;
	}
	ofs << allthedata;
	ofs.close();
	cout << "第"<<line << "记录删除成功！" << endl;
}
int file::load(int leixing)
{
	ifstream ifs;
	string tm = Name + "jilu.txt";
	ifs.open(tm);
	if (!ifs.is_open())
	{
		return 0;
	}
	string str;
	int returnmark = 0;
	while (getline(ifs, str))
	{
		if (leixing == 0)
		{
			if (str.find("入门模式") != string::npos && str.find(Name) != string::npos)
			{
				int i = int(str.find("得分："));
				string s = str.substr(i + 6);
				if (returnmark < atoi(s.c_str()))
				{
					returnmark = atoi(s.c_str());
				}
			}
		}
		else if (leixing == 1)
		{
			if (str.find("进阶模式") != string::npos && str.find(Name) != string::npos)
			{
				int i =int( str.find("得分："));
				string s = str.substr(i + 6);
				if (returnmark < atoi(s.c_str()))
				{
					returnmark = atoi(s.c_str());
				}
			}
		}
		else if (leixing == 2)
		{
			if (str.find("高级模式") != string::npos && str.find(Name) != string::npos)
			{
				int i = int(str.find("得分："));
				string s = str.substr(i + 6);
				if (returnmark < atoi(s.c_str()))
				{
					returnmark = atoi(s.c_str());
				}
			}
		}
		else if (leixing == 3)
		{
			if (str.find("海克斯模式") != string::npos && str.find(Name) != string::npos)
			{
				int i = int(str.find("得分："));
				string s = str.substr(i + 6);
				if (returnmark < atoi(s.c_str()))
				{
					returnmark = atoi(s.c_str());
				}
			}
		}
	}
	return returnmark;
}

void file::loadman()
{
	wchar_t wstr[100] = {}; // 假设这是从InputBox获取的宽字符串
	InputBox(wstr, 100, _T("请输入你的名字(英文)"));
	int size = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
	if (size == 0) {
		std::cerr << "获取长度失败" << std::endl;
		return ;
	}
	char* str = new char[size + 1]; // 分配足够空间，多分配一个字节用于存放'\0'
	if (WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, size, nullptr, nullptr) == 0) {
		std::cerr << "转换失败" << std::endl;
		delete[] str;
		return ;
	}
	std::string result(str); // 构造std::string对象
	delete[] str; // 释放内存
	Name = result;
}

