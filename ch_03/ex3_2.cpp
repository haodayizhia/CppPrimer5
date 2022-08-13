#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
	string s;
	while (getline(cin, s))
		cout << s << endl;
	while (cin >> s)
		cout << s << endl;
	return 0;
}
