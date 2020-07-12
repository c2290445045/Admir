#include "Student.h"
#include<string>
#include<iostream>
using namespace std;
//在Student中  1表示为数学 2表示为物理  3表示为英语



//构造函数
Student::Student(string ID, string name, int math, int english, int physics)
{
	m_name = name;
	m_id = ID;
	m_math = math;
	m_physics = physics;
	m_english = english;
}

bool Student::_ID(string ID)
{
	return ID == m_id;
}

void Student::Update_Greade(int score, int flag)
{
	if (flag == 1)
		m_math = score;
	else if (flag == 2)
		m_physics = score;
	else if (flag == 3)
		m_english = score;
	else
		cout << "输入错误" << endl;
}

void Student::Print_Infomation(){
	cout << m_id << "       " << m_name << "        " << m_math << "      " << m_physics << "      " << m_english << endl;
}

string Student::Return_ID()
{
	return m_id;
}

bool Student::_NAME(string name){
	return m_name == name;
}

string Student::Return_name()
{
	return m_name;
}

int Student::Return(int flag){
	if (flag == 1)
		return this->m_math;
	else if (flag == 2)
		return this->m_physics;
	else if (flag == 3)
		return this->m_english;
	else if (flag == 4)
		return this->m_english + this->m_math + this->m_physics;
}
