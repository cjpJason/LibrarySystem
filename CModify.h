#pragma once
#include<iostream>
#include<fstream>
#include <string.h>
#include"CUser.h"
//本文件修改密码，修改思路：将文件1中数据读取到文件2，遇到需要修改的则修改，
//然后清空文件1，再将文件2数据复制到文件按1
class CModify {
private:
	char password[100];
	char data[100];
public:
	CModify(char a[100]) {
		for (int i = 0; i < 100; ++i) {
			password[i] = a[i];
		}
		ifstream infile;
		infile.open("UserInformation1.txt");
		ofstream outfile;
		outfile.open("UserInformation2.txt",ios::ate);
		if (!infile)cout << "error" << endl;
		//先确认密码
		cout << "请输入原密码";
		char temp[100];
		cin.getline(temp, 100);
		if (strcmp(password, temp) == 0) {//密码正确，允许修改密码
			cout << "请输入想要修改的密码";
			char temp1[100];
			cin.getline(temp1, 100);
			while (infile.getline(data, 100)) {
				if (strcmp(data,password)==0) {//找到密码所在位置
					strncpy_s(data, temp1,100);
					outfile << data << endl;
					continue;
				}//if语句结束
				outfile << data << endl;
			}//while语句结束
			infile.close();
			outfile.close();
			ifstream in;
			ofstream out;
			in.open("UserInformation2.txt");
			out.open("UserInformation1.txt",ios::ate);
			while (in.getline(data, 100)) {
				out << data << endl;
			}
			in.close();
			out.close();
			cout << endl;
			
		}
	}
};