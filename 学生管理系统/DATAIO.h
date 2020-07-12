#pragma once
#include"Display.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include"Management.h"
#include<iostream>
using namespace std;

Management m;

//注意！！！！
//这里面的data.txt文件要放在项目文件夹中
//data.txt文件的编码是ANCI编码，如果是utf-8编码可能会乱码
//以下是文件读入读出函数


Management Input() {
	ifstream input("data.txt",ios::in);
	while (!input.eof()) {
		string id, name;
		int math, english, physics;
		input >> id >> name >> math >> physics >> english;
		Student s(id, name, math, english, physics);
		m.ADD(s);
	}
	return m;
}


void Output(Management m) {
	ofstream ofs("data.txt", ios::out);
	for (int i = 0; i < m.Return_Data().size(); i++) {
		Student s = m.Return_Data()[i];
		ofs << s.Return_ID() << " " << s.Return_name() << " " << s.Return(1) << " " << s.Return(2) << " " << s.Return(3) << endl;
	}
}

