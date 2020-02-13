#pragma once
#pragma once
#include<iostream>
#include <fstream>
#include<conio.h>
#include"C:\Users\10561\source\repos\LibrarySystem-master\findbook.h"
#include"CModify.h"
using namespace std;
class CUser {
private:
	char UserName[100];
	char Password[100];
public:
	CUser(char a[100],char b[100]) {
		for (int i = 0; i < 100; ++i) {
			UserName[i] = a[i];//储存账号（虽然不清楚有什么用）
			Password[i] = b[i];
		}//for循环结束
//用户界面，功能有查找图书、借阅图书、修改密码
		User(UserName);//用户界面函数
	}
	void User(char* name) {
		while (*name) {
			putchar(*name++);
		}
		cout << "同学，你好，欢迎使用图书管理系统，请选择你需要的功能" << endl;
		cout << "1、查找书籍" << endl;
		cout << "2、借阅书籍" << endl;
		cout << "3、修改密码" << endl;
		cout << "4、退出" << endl;
		int t=_getche();
		if (t == 49) {
			cout << "查找书籍";
			findbook();
		}
		if (t == 50) {
			cout << "借阅书籍";
			borrowbook();
		}
		if (t == 51) {
			cout << "修改密码";
			CModify::CModify(Password);
		}
		if (t == 52) {
			cout << "退出"<<endl;
			return;
		}
	}
};