#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	vector<int> ivec(10, 1);
	for (auto it = ivec.begin(); it != ivec.end(); ++it)
	{
		*it *= 2;
		cout << *it << ' ';
	}
	cout << endl;
	return 0;
}
