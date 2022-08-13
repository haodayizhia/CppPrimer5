#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
	string str, largeStr;
	if (cin >> str)
	{
		largeStr = str;
		while (cin >> str)
		{
			largeStr += " " + str;
		}
		cout << largeStr << endl;
		return 0;
	}
	cerr << "input error" << endl;
	return -1;
}
