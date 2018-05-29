#pragma once
#ifndef SALESDATA_H
#define SALESDATA_H
#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
public:
	//���캯��
	Sales_data() = default;
	Sales_data(const std::string &s):bookNo(s){}
	Sales_data(std::istream &);
	Sales_data(const std::string &s, unsigned n, double p);
	string isbn() const { return bookNo; }			//https://www.cnblogs.com/thefirstfeeling/p/5848593.html
	Sales_data& combine(const Sales_data& rhs);		//const����

private:
	string bookNo = "";
	unsigned int units_sold = 0;
	double revenue = 0.0;
	double avg_price() const
	{
		return units_sold ? revenue / units_sold : 0; 
	}

	//��Ԫ����
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend ostream &print(ostream&, const Sales_data&);
	friend istream &read(istream&, Sales_data&);
};

// Sales_data�ķǳ�Ա�ӿں���
Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);


#endif