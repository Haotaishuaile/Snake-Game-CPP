#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>
#include<fstream>
#include<graphics.h>
#include<iostream>
#include <windows.h>
#include<vector>



using namespace std;

class file
{
public:
	string Name;
	string Id;
	file();
	int load(int leixing);
	void loadman();
	void savejilu(int leixing, int mark);
	void loadjilu();
	void shanchu(int line);
};

