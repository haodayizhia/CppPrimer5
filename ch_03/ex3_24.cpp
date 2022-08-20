#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int in;
	vector<int> ivec;
	while (cin >> in)
		ivec.push_back(in);
	for (auto it = ++ivec.cbegin(); it != ivec.cend(); ++it)
		cout << *it + *(it - 1) << ' ';
	cout << endl;
	for (auto it = ivec.cbegin(); it < ivec.cbegin() + (ivec.size() + 1) / 2; ++it)
		cout << *it + *(ivec.end() - 1 - (it - ivec.cbegin())) << ' ';
	cout << endl;
	return 0;
}
