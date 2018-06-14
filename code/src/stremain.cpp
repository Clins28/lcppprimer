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
		record.str(line);	//��line���浽record��
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
		record.clear();	//ÿ����Ҫ��λ�����������str����ʱ�������
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