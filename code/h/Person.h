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
	//构造函数
	Person() = default;
	Person(const string&ns) : name(ns) {}
	Person(std::istream &);
	Person(const string&, const string&);

	string Getname() const { return name; }		// const在参数传递中的作用 https://blog.csdn.net/zheng19880607/article/details/23883437
	string Getadress() const { return adress; }	// 声明为const成员变量可以保证不会修改数据成员

	friend istream &read(istream&, Person&);
	friend ostream &print(ostream&, const Person&);
};

istream &read(istream&, Person&);
ostream &print(ostream&, const Person&);

#endif