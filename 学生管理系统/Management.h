#pragma once
#include<vector>
#include<string>
#include"Student.h"
class Management
{
public:
	void ADD(Student);//����ѧ��
	void Delete(string);//ɾ��ѧ��
	void Update(string, int, int);//���³ɼ�
	bool Fuzzy_Serach(string);//ģ������
	bool Search(string);
	void Sort_student();//����
	double Pass_rate(int);//�ϸ���
	double AVG(int);//ƽ���ɼ�����
	double AVG();//ƽ���ɼ��ܷ�
	double Standard_deviation(int);//��׼��
	vector<Student> Return_Data();//��������
private:
	vector<Student>m_students;
	bool Fuzzy_search_ID(Student,string);//ѧ��ģ������
	bool Fuzzy_search_name(Student,string);//����ģ������
};

