#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string word;
	vector<string> text;
	while (cin >> word)
		text.push_back(word);
	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
		for (auto it1 = it->begin(); it1 != it->end(); ++it1)
			*it1 = toupper(*it1);
	for (auto &s : text)
		cout << s;
	cout << endl;
	return 0;
}
