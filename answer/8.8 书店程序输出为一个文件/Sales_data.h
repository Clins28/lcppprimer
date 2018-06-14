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
	//���캯��
	//Sales_data(std::string s) : bookNo(s){}
	Sales_data(std::string s = ""):bookNo(s){}		//���һ�����캯��Ϊ���в������ṩ��Ĭ��ʵ�Σ�����ʵ����Ҳ������Ĭ�Ϲ��캯��
	Sales_data(const std::string &s, unsigned n, double price):bookNo(s), units_sold(n), revenue(n*price){}
	Sales_data(std::istream &);
	string isbn() const { return bookNo; }			//https://www.cnblogs.com/thefirstfeeling/p/5848593.html
	Sales_data& combine(const Sales_data& rhs);		//const����

	//ί�й��캯��
	//Sales_data() : Sales_data("", 0, 0){}
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