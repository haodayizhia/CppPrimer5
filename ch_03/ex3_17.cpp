#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string str;
	vector<string> vs;
	while (cin >> str)
	{
		for (auto &i : str)
			i = toupper(i);
		vs.push_back(str);
	}
	for (const auto &i : vs)
		cout << i << endl;
	return 0;
}
