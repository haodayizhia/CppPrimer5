#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
	string s = "abc";
	for (auto &i : s)
		i = 'X';
		cout << s << endl;
	return 0;
}
