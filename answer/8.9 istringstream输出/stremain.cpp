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

string line, word;
vector<PersonInfo> people;

int main() {
	ifstream input("../../data/phone.txt");
	while (getline(input, line)) {
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
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