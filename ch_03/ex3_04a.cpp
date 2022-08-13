#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 > s2)
		cout << s1 << endl;
	else if (s1 < s2)
		cout << s2 << endl;
	return 0;
}
