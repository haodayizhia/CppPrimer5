#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	// string比较
	string s1("i");
	string s2("love");
	cout << (s1 < s2) << endl;

	// C风格字符串比较
	char c1[] = {'i', '\0'};
	char c2[] = {'l', 'o', 'v', 'e', '\0'};
	cout << (strcmp(c1, c2)) << endl;
	return 0;
}
