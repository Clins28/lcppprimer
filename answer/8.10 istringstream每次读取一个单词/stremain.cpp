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

	vector<string> vec;
	while (input) {
		getline(input, line);
		vec.push_back(line);
	}

	
	for (int i = 0; i < vec.size(); i++){
		istringstream record(vec[i]);
		string output;
		while (record >> output) {
			cout << output << endl;
		}
	}

	system("pause");
	return 0;
}