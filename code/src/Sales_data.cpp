#include "../h/Sales_data.h"

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

