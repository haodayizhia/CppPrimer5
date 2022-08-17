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
	decltype(s.size()) i = 0;
	while (i < s.size())
	{
		s[i] = 'X';
		++i;
	}
	cout << s << endl;
	for (i = 0; i < s.size(); ++i)
		s[i] = 'X';
	cout << s << endl;
	return 0;
}
