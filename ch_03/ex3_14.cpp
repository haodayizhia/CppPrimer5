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
	int i;
	vector<int> ivec;
	while (cin >> i)
		ivec.push_back(i);
	for (auto ii : ivec)
		cout << ii << endl;
	return 0;
}
