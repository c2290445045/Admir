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

//更新成绩
void Update_Grade() {
	cout << "请输入学生ID" << endl;
	string a;
	cin >> a;
	int s;
	cout << "请输入要改的课程标号 用空格隔开" << endl << "1.math" << endl << "2.physics" << endl << "3.english" << endl;
	cin >> s;
	
	while (true) {
		if (s <= 0 || s > 3) {
			cout << "输入错误重新输入" << endl;
			cout << "请输入要改的课程标号 用空格隔开" << endl << "1.math" << endl << "2.physics" << endl << "3.english" << endl;
			cin >> s;
		}
		else
			break;
	}
	int score;
	cout << "请按照顺序输入修改的成绩" << endl;
	cin >> score;
	managment.Update(a, score, s);
}

//删除
void Delete() {
	string ID;
	cout << "请输入要删除的id" << endl;
	cin >> ID;
	cout << "1 确认 0 返回" << endl;
	int flag;
	cin >> flag;
	if (flag)
		managment.Delete(ID);
}

//增加
void Add_Infomation() {
	while (true) {
		string ID, name;
		int math, english, physics;
		cout << "学号输入-1结束录入" << endl;
		cout << "请输入学生学号:";
		cin >> ID;
		if (ID == "-1")
			break;
		cout << "请输入学生姓名:";
		cin >> name;
		cout << "请输入学生数学，英语，物理成绩:";
		cin >> math >> english >> physics;
		Student Stu1(ID, name, math, english, physics);
		managment.ADD(Stu1);
	}
}

//查找
void Search_student() {
	cout << "输入要查找的学号或者姓名" << endl;
	string s;
	cin >> s;
	cout << "ID   Name   Math   Physics   English" << endl;
	//如果没有查找到则进行模糊查询
	if (!managment.Search(s)) {
		cout << "无" << endl;
		cout << "模糊查找" << endl;
		if (!managment.Fuzzy_Serach(s))
			cout << "无" << endl;
	}
}

//数据分析
void Infomatio() {
	cout << "单科平均成绩" << endl;
	cout << "Math: " << managment.AVG(Math) << endl;
	cout << "Pyhscis: " << managment.AVG(Physics) << endl;
	cout << "English: " << managment.AVG(English) << endl;
	cout << "三门课总分平均成绩：" << managment.AVG() << endl;
	cout << "标准差为:" << endl;
	cout << "Math: " << managment.Standard_deviation(1) << endl;
	cout << "Pyhscis: " << managment.Standard_deviation(2) << endl;
	cout << "English: " << managment.Standard_deviation(3) << endl;
	cout << "合格率为：" << endl;
	cout << "Math: " << managment.Pass_rate(1) << endl;
	cout << "Pyhscis: " << managment.Pass_rate(2) << endl;
	cout << "English: " << managment.Pass_rate(3) << endl;
	system("pause");
}

//排序
void Sort_Infomation() {
	cout << "ID                Name        Math   Physics   English" << endl;
	managment.Sort_student();
	system("pause");
}

//文件读写
void Input_or_Output() {
	int flag;
	cout << "导入输入1导出输入2"<<endl;
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

//退出时候看保不保存文件
void exit_end() {
	cout << "是否将更改的内容保存?" << endl << "1是 2否" << endl;
	int flag = 1;
	cin >> flag;
	if (flag == 1)
		Output(managment);
	exit(0);
}

//开关语句，程序总流程
void Display() {
	int menu;
	while (true) {
		system("cls");
		cout << "-----学生成绩管理系统-----" << endl;
		cout << "    (1):增加记录" << endl;
		cout << "    (2):删除记录" << endl;
		cout << "    (3):修改成绩" << endl;
		cout << "    (4)查找学生" << endl;
		cout << "    (5)统计学生信息" << endl;
		cout << "    (6)对学生排序 " << endl;
		cout << "    (7)导入或导出文件" << endl;
		cout << "    (8)结束程序！" << endl;
		cout << "---------------------------" << endl;
		cin >> menu;
		switch (menu) {
		case 1:Add_Infomation(); break;//新增学生
		case 2:Delete(); break;//删除学生
		case 3:Update_Grade(); break;//更新学生成绩
		case 4:;Search_student(); break;//查找
		case 5:Infomatio(); break;//数据分析
		case 6:Sort_Infomation(); break;//排序
		case 7:Input_or_Output(); break;//文件读写
		case 8:exit_end();//退出
		}
		system("pause");
	}
}