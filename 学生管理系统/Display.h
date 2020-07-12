#pragma once
#include"DATAIO.h"
#include"Management.h"
#include"Student.h"
#include<string>
#include<sstream>
#include<cstdlib>
constexpr auto Math = 1;;
constexpr auto Physics = 2;;
constexpr auto English = 3;;

using namespace std;

Management managment;

//���³ɼ�
void Update_Grade() {
	cout << "������ѧ��ID" << endl;
	string a;
	cin >> a;
	int s;
	cout << "������Ҫ�ĵĿγ̱�� �ÿո����" << endl << "1.math" << endl << "2.physics" << endl << "3.english" << endl;
	cin >> s;
	
	while (true) {
		if (s <= 0 || s > 3) {
			cout << "���������������" << endl;
			cout << "������Ҫ�ĵĿγ̱�� �ÿո����" << endl << "1.math" << endl << "2.physics" << endl << "3.english" << endl;
			cin >> s;
		}
		else
			break;
	}
	int score;
	cout << "�밴��˳�������޸ĵĳɼ�" << endl;
	cin >> score;
	managment.Update(a, score, s);
}

//ɾ��
void Delete() {
	string ID;
	cout << "������Ҫɾ����id" << endl;
	cin >> ID;
	cout << "1 ȷ�� 0 ����" << endl;
	int flag;
	cin >> flag;
	if (flag)
		managment.Delete(ID);
}

//����
void Add_Infomation() {
	while (true) {
		string ID, name;
		int math, english, physics;
		cout << "ѧ������-1����¼��" << endl;
		cout << "������ѧ��ѧ��:";
		cin >> ID;
		if (ID == "-1")
			break;
		cout << "������ѧ������:";
		cin >> name;
		cout << "������ѧ����ѧ��Ӣ�����ɼ�:";
		cin >> math >> english >> physics;
		Student Stu1(ID, name, math, english, physics);
		managment.ADD(Stu1);
	}
}

//����
void Search_student() {
	cout << "����Ҫ���ҵ�ѧ�Ż�������" << endl;
	string s;
	cin >> s;
	cout << "ID   Name   Math   Physics   English" << endl;
	//���û�в��ҵ������ģ����ѯ
	if (!managment.Search(s)) {
		cout << "��" << endl;
		cout << "ģ������" << endl;
		if (!managment.Fuzzy_Serach(s))
			cout << "��" << endl;
	}
}

//���ݷ���
void Infomatio() {
	cout << "����ƽ���ɼ�" << endl;
	cout << "Math: " << managment.AVG(Math) << endl;
	cout << "Pyhscis: " << managment.AVG(Physics) << endl;
	cout << "English: " << managment.AVG(English) << endl;
	cout << "���ſ��ܷ�ƽ���ɼ���" << managment.AVG() << endl;
	cout << "��׼��Ϊ:" << endl;
	cout << "Math: " << managment.Standard_deviation(1) << endl;
	cout << "Pyhscis: " << managment.Standard_deviation(2) << endl;
	cout << "English: " << managment.Standard_deviation(3) << endl;
	cout << "�ϸ���Ϊ��" << endl;
	cout << "Math: " << managment.Pass_rate(1) << endl;
	cout << "Pyhscis: " << managment.Pass_rate(2) << endl;
	cout << "English: " << managment.Pass_rate(3) << endl;
	system("pause");
}

//����
void Sort_Infomation() {
	cout << "ID                Name        Math   Physics   English" << endl;
	managment.Sort_student();
	system("pause");
}

//�ļ���д
void Input_or_Output() {
	int flag;
	cout << "��������1��������2"<<endl;
	int n;
	cin >> n;
	if (n == 1) {
		Management m = Input();
		for (int i = 0; i < m.Return_Data().size(); i++) {
			managment.ADD(m.Return_Data()[i]);
		}
	}
	else if (n == 2)
		Output(managment);
}

//�˳�ʱ�򿴱��������ļ�
void exit_end() {
	cout << "�Ƿ񽫸��ĵ����ݱ���?" << endl << "1�� 2��" << endl;
	int flag = 1;
	cin >> flag;
	if (flag == 1)
		Output(managment);
	exit(0);
}

//������䣬����������
void Display() {
	int menu;
	while (true) {
		system("cls");
		cout << "-----ѧ���ɼ�����ϵͳ-----" << endl;
		cout << "    (1):���Ӽ�¼" << endl;
		cout << "    (2):ɾ����¼" << endl;
		cout << "    (3):�޸ĳɼ�" << endl;
		cout << "    (4)����ѧ��" << endl;
		cout << "    (5)ͳ��ѧ����Ϣ" << endl;
		cout << "    (6)��ѧ������ " << endl;
		cout << "    (7)����򵼳��ļ�" << endl;
		cout << "    (8)��������" << endl;
		cout << "---------------------------" << endl;
		cin >> menu;
		switch (menu) {
		case 1:Add_Infomation(); break;//����ѧ��
		case 2:Delete(); break;//ɾ��ѧ��
		case 3:Update_Grade(); break;//����ѧ���ɼ�
		case 4:;Search_student(); break;//����
		case 5:Infomatio(); break;//���ݷ���
		case 6:Sort_Infomation(); break;//����
		case 7:Input_or_Output(); break;//�ļ���д
		case 8:exit_end();//�˳�
		}
		system("pause");
	}
}