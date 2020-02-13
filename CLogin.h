#pragma once
#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include"CUser.h"
using namespace std;
class CLogin {
private:

public:
	CLogin() {
		Login();
	}
	void Login() {
		char input[100];//用户输入手机号（手机号作为登录账号）
		char data[100];//表示txt文件内的手机号
		char password[100];//用户密码
		char PW[100];//数据库内密码
		static int flag=0;//标志是否找到对应手机号
		cout << "请输入手机号";
		cin.getline(input, 100);
		ifstream infile;
		infile.open("UserInformation1.txt");
		if (!infile)cout << "error" << endl;//打不开文件就报错（一般没用）
		while (infile.getline(data, 100)) {//按行读取
			if (strcmp(data, input) == 0) {//判断手机号是否对应，对应则往下读一行作为密码
				flag= 1;//找到对应账号，flag变成1
				cout << "请输入密码"<<endl;
				cin.getline(password, 100);
				infile.getline(PW, 100);
				if (strcmp(PW, password) == 0) {//密码正确，允许登录
					infile.close();
					cout << "密码正确";
					flag = 1;
					//找到手机号对应的名字
					CUser user(findname(data),PW);//进入用户界面
				}//密码if结束
			}//账户if结束
		}//while结束
		infile.close();
		if (flag == 0) 
			cout << "用户名错误，按q退出，按任意键继续使用" << endl;
		else{
			flag = 0;
			cout << "用户登录"<<endl<<"按q退出，按任意键继续使用";
		}
		char temp = 'q';
		char ch = _getche();
		if (ch == temp) {
			return;
		}
		else {
			Login();
		}
	}
	char* findname(char* a) {
		ifstream infile;
		infile.open("UserInformation1.txt");
		char name[100], temp[100];
		int i = 2;
		//采用循环储存，temp1和temp2轮流储存一行数据，故互为上一行
		while (infile.getline(temp, 100)) {//整个txt文件检索
			char temp1[100], temp2[100];
			if (i % 2 == 0) {
				if (strcmp(temp, a) == 0) {
					for (int j = 0; j < 100; ++j)
						name[j] = temp2[j];
					return name;
				}
				for (int n = 0; n < 100; ++n)
					temp1[n] = temp[n];
				++i;
			}
			if (i % 2 == 1) {
				if (strcmp(temp, a) == 0) {
					for (int j = 0; j < 100; ++j)
						name[j] = temp1[j];
					return name;
				}
				for (int n = 0; n < 100; ++n)
					temp2[n] = temp[n];
				++i;
			}
		}//while结束
	}//findname结束
};