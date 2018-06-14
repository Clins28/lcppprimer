#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

istream& read(vector<string>& vec, istream& is) {
	string temp;
	while (is) {
		getline(is, temp);
		vec.push_back(temp);
	}
	return is;
}

int main() {
	vector<string> vec;
	ifstream input("test.txt");
	read(vec, input);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
	system("pause");
	return 0;
}

