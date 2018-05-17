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
	string Getname() const { return name; }		// const在参数传递中的作用 https://blog.csdn.net/zheng19880607/article/details/23883437
	string Getadress() const { return adress; }	// 声明为const成员变量可以保证不会修改数据成员
};



#endif