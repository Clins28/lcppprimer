#include "../h/Sales_data.h"

using namespace std;


int main(int argc, char *argv[])
{
	ifstream input("../../data/bookstoredata.txt");
	Sales_data total; //保存下一条交易记录的变量
	//读入第一条交易记录，并确保有数据可以处理
	if (read(input, total))
	{
		Sales_data trans;	//保存和的变量
		//读入并处理剩余交易记录
		while(read(input, trans))
		{
			//如果我们仍在处理相同的书
			if (total.isbn() == trans.isbn())
				total.combine(trans);	//更新总销售额
			else
			{
				//打印前一本书的结果
				print(cout, total) << endl;
				total = trans;	//total现在表示下一本书的销售额
			}
		}
		print(cout, total) << endl;	//打印最后一本书的结果
	}
	else
	{
		//没有输入！ 警告读者
		cerr << "No data?!" << endl;
		return -1;	//表示失败
	}
	system("pause");
	return 0;
}
	
		