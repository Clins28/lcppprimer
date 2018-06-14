#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};



int main() {
	ifstream input("../../data/phone.txt");
	string line, word;
	vector<PersonInfo> people;

	istringstream record;
	while (getline(input, line)) {
		PersonInfo info;
		record.str(line);	//将line保存到record中
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
		record.clear();	//每次需要复位流，否则进行str操作时流会出错
	}
	for (int i = 0; i < people.size(); i++)
	{
		cout << people[i].name << endl;
		for (int j = 0; j < people[i].phones.size(); j++)
		{
			cout << people[i].phones[j] << endl;
		}
	}
	system("pause");
	return 0;
}