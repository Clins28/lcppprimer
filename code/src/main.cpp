#include "../h/Screen.h"
#include "../h/Sales_data.h"

using namespace std;


int main() {
	string s = "7562";
	Sales_data A("2345");
	Sales_data B("5679");
	B.combine(s);
}