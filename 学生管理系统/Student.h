#pragma once
#include<string>
using namespace std;
class Student
{
public:
	Student(string,string,int,int ,int);//���캯��
	bool _ID(string);//�ж��Ƿ��ѧ��һ��
	void Update_Greade(int, int);//���³ɼ�
	void Print_Infomation();//��ӡѧ����Ϣ
	string Return_ID();//����ѧ��
	bool _NAME(string);
	string Return_name();//��������
	int Return(int);//���ص��Ƴɼ����ܷ�
private:
	string m_id, m_name;
	int m_math, m_english, m_physics;
};

