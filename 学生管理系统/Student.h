#pragma once
#include<string>
using namespace std;
class Student
{
public:
	Student(string,string,int,int ,int);//构造函数
	bool _ID(string);//判断是否和学号一样
	void Update_Greade(int, int);//更新成绩
	void Print_Infomation();//打印学生信息
	string Return_ID();//返回学号
	bool _NAME(string);
	string Return_name();//返回姓名
	int Return(int);//返回单科成绩，总分
private:
	string m_id, m_name;
	int m_math, m_english, m_physics;
};

