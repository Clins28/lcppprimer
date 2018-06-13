#pragma once
#include <string>
#include <vector>

using namespace std;

class Account {
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);
	static double rate = 6.5;	//需要使用const给static初始化
	static const int vecSize = 20;
	static vector<double> vec(vecSize);	//????

private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initrate();
};

double Account::rate;
vector<double> Account::vec;