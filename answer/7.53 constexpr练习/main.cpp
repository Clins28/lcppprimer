#include "../h/Screen.h"
#include "../h/debug.h"

using namespace std;


int main() {
	constexpr Debug io_sub(false, true, false);
	if (io_sub.any())
	{
		cerr << "print appropriate error message" << endl;
	}
	constexpr Debug prod(false);
	if (prod.any())
		cerr << "print an error message" << endl;
	system("pause");
}