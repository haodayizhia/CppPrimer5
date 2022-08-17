#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
	string s = "p,u,n,c,t";
	string res;
	for (auto c : s)
		if (!ispunct(c))
			res += c;
	cout << res << endl;
	return 0;
}
