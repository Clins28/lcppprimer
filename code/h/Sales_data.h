#pragma once
#ifndef SALESDATA_H
#define SALESDATA_H
#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
public:
	string bookNo = "";
	unsigned int units_sold = 0;
	double revenue = 0.0;

public:
	string isbn() const { return bookNo; }			//https://www.cnblogs.com/thefirstfeeling/p/5848593.html
	Sales_data& combine(const Sales_data& rhs);		//const引用
	double avg_price() const;

};

// Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);


#endif