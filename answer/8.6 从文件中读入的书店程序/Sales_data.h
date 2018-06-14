#pragma once
#ifndef SALESDATA_H
#define SALESDATA_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Sales_data
{
public:
	//构造函数
	//Sales_data(std::string s) : bookNo(s){}
	Sales_data(std::string s = ""):bookNo(s){}		//如果一个构造函数为所有参数都提供了默认实参，则他实际上也定义了默认构造函数
	Sales_data(const std::string &s, unsigned n, double price):bookNo(s), units_sold(n), revenue(n*price){}
	Sales_data(std::istream &);
	string isbn() const { return bookNo; }			//https://www.cnblogs.com/thefirstfeeling/p/5848593.html
	Sales_data& combine(const Sales_data& rhs);		//const引用

	//委托构造函数
	//Sales_data() : Sales_data("", 0, 0){}
private:
	string bookNo = "";
	unsigned int units_sold = 0;
	double revenue = 0.0;
	double avg_price() const
	{
		return units_sold ? revenue / units_sold : 0; 
	}

	//友元声明
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend ostream &print(ostream&, const Sales_data&);
	friend istream &read(istream&, Sales_data&);
};

// Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);


#endif