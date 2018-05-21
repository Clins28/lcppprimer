#include "../h/Sales_data.h"
#include <iostream>
#include <string>

using namespace std;

double Sales_data::avg_price() const		//const 把该函数定义为静态的成员函数
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs)	//函数返回左值
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;										//返回一个 this 指针的解引用，即执行该函数的对象
}

istream &read(istream &is, Sales_data &item) 
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

