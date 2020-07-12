#pragma once
#include<vector>
#include<string>
#include"Student.h"
class Management
{
public:
	void ADD(Student);//增加学生
	void Delete(string);//删除学生
	void Update(string, int, int);//更新成绩
	bool Fuzzy_Serach(string);//模糊查找
	bool Search(string);
	void Sort_student();//排序
	double Pass_rate(int);//合格率
	double AVG(int);//平均成绩单科
	double AVG();//平均成绩总分
	double Standard_deviation(int);//标准差
	vector<Student> Return_Data();//返回数据
private:
	vector<Student>m_students;
	bool Fuzzy_search_ID(Student,string);//学号模糊查找
	bool Fuzzy_search_name(Student,string);//姓名模糊查找
};

