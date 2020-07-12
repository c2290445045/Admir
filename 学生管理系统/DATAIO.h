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

//ע�⣡������
//�������data.txt�ļ�Ҫ������Ŀ�ļ�����
//data.txt�ļ��ı�����ANCI���룬�����utf-8������ܻ�����
//�������ļ������������


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

