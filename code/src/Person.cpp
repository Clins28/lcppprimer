#include "../h/Person.h"

istream &read(istream &is, Person &readdata) {
	is >> readdata.name >> readdata.adress;
	return is;
}

ostream &print(ostream &os, const Person &pdata) {
	os << pdata.name << "" << pdata.adress;
	return os;
}

Person::Person(std::istream &is) {
	read(is, *this);		//为什么使用this指针 *this
}

Person::Person(const string& ns, const string& as) {
	(*this).name = ns;
	this->adress = as;		//为什么这里直接用this->, this->和this.有什么区别
}
