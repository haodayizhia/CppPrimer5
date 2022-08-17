#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char *argv[])
{
	string s;
	vector<string> svec;
	while (cin >> s)
		svec.push_back(s);
	for (auto ss : svec)
		cout << ss << endl;
	return 0;
}
