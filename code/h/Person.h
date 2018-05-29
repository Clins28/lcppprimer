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
	//���캯��
	Person() = default;
	Person(const string&ns) : name(ns) {}
	Person(std::istream &);
	Person(const string&, const string&);

	string Getname() const { return name; }		// const�ڲ��������е����� https://blog.csdn.net/zheng19880607/article/details/23883437
	string Getadress() const { return adress; }	// ����Ϊconst��Ա�������Ա�֤�����޸����ݳ�Ա

	friend istream &read(istream&, Person&);
	friend ostream &print(ostream&, const Person&);
};

istream &read(istream&, Person&);
ostream &print(ostream&, const Person&);

#endif