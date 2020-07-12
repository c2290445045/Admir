#include "Management.h"
#include"Student.h"
#include<iostream>
#include<algorithm>
#include<istream>
#include<sstream>
using namespace std;

void Management::ADD(Student Stu)
{
	m_students.push_back(Stu);
}

//�����������������������
bool cmp(Student &s1, Student &s2) {
	if (s1.Return(4) == s2.Return(4)) {
		if (s1.Return(1) != s2.Return(1))
			return s1.Return(1) > s2.Return(1);
		else if (s2.Return(2) != s2.Return(2))
			return s1.Return(2) > s2.Return(2);
		else if (s2.Return(3) != s2.Return(3))
			return s1.Return(3) > s2.Return(3);
		else
			return s1.Return_ID() > s2.Return_ID();
	}
	else
		return s1.Return(4) > s2.Return(4);
}

//�������еĶ�vector���в��Ҷ�ʹ�õ�����������ɾ�����������е�Ԫ��
void Management::Delete(string ID)
{
	vector<Student>::iterator ite;
	for (ite = m_students.begin(); ite != m_students.end();) {
		if ((*ite)._ID(ID)) {
			ite = m_students.erase(ite);
			cout << "ɾ���ɹ�!" << endl;
			return;
		}
		else
			ite++;
	}
	cout << "���޴��� ɾ��ʧ��" << endl;
}

void Management::Update(string ID,int score ,int flag)
{
	vector<Student>::iterator ite;
	for (ite = m_students.begin(); ite != m_students.end();) {
		if ((*ite)._ID(ID)) {
			(*ite).Update_Greade(score, flag);
			cout << "�޸ĳɹ�" << endl;
			return;
		}
		else
			ite++;
	}
	cout << "�޸�ʧ��!" << endl;
}

//ģ����ѯ�����ж������ַ����Ƿ�����ͬ�Ĳ��֣������Ϊ�棬��֮��Ϊ��
bool Management::Fuzzy_Serach(string s){
	vector<Student>::iterator ite;
	int flag = 0;
	for (ite = m_students.begin(); ite != m_students.end();) {
		if (Fuzzy_search_ID((*ite), s)) {
			(*ite).Print_Infomation();
			flag = 1;
		}
		else if (Fuzzy_search_name((*ite), s)) {
			(*ite).Print_Infomation();
			flag = 1;
		}
		ite++;
	}
	if (flag)
		return true;
	return false;
}

//���Һ�����ֱ�Ӳ���ѧ�Ż�������
bool Management::Search(string s){
	vector<Student>::iterator ite;
	for (ite = m_students.begin(); ite != m_students.end();) {
		if ((*ite)._ID(s)) {
			(*ite).Print_Infomation();
			return true;
		}
		else if ((*ite)._NAME(s)) {
			(*ite).Print_Infomation();
			return true;
		}
		else
			ite++;
	}
	return false;
}

//��������������Ȼ���������Ԫ�أ������õ���sort������cmp�����μ�����
void Management::Sort_student(){
	sort(m_students.begin(), m_students.end(), cmp);
	for (int i = 0; i < m_students.size(); i++)
		m_students[i].Print_Infomation();
}

//��ѯ�ϸ���
double Management::Pass_rate(int flag){
	int count = 0;
	for (int i = 0; i < m_students.size(); i++)
		if (m_students[i].Return(flag) >= 60)
			count++;
	return (double)count / (double)m_students.size();
}

//��ѯ����ƽ���ɼ�
double Management::AVG(int flag){
	double sum = 0;
	for (int i = 0; i < m_students.size(); i++)
		sum += m_students[i].Return(flag);
	sum /= m_students.size();
	return sum;
}

//��ѯ�ܷ�ƽ���ɼ�
double Management::AVG(){
	double sum = 0;
	for (int i = 0; i < m_students.size(); i++)
		sum += m_students[i].Return(1) + m_students[i].Return(2) + m_students[i].Return(3);
	sum /= m_students.size();
	return sum;
}

//��׼��
double Management::Standard_deviation(int flag){
	double avg = AVG(flag);
	double sum = 1;
	for (int i = 0; i < m_students.size(); i++)
		sum += pow((m_students[i].Return(flag) - avg), 2);
	sum /= m_students.size();
	sum = pow(sum, 0.5);
	return sum;
}

//��������ѧ��
vector<Student> Management::Return_Data(){
	return m_students;
}

//ģ����ѯ
bool Management::Fuzzy_search_ID(Student s,string id){
	string str=s.Return_ID();
	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < id.size(); j++)
			if (str[i] == id[j])
				return true;
	}
	return false;
}

//ģ����ѯ
bool Management::Fuzzy_search_name(Student s,string name){
	string str = s.Return_name();
	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < name.size(); j++)
			if (str[i] == name[j])
				return true;
	}
	return false;
}
