#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
private:
	string name = "";
	string adress = "";

public:
	string Getname() const { return name; }		// const�ڲ��������е����� https://blog.csdn.net/zheng19880607/article/details/23883437
	string Getadress() const { return adress; }	// ����Ϊconst��Ա�������Ա�֤�����޸����ݳ�Ա
};



#endif