#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int a[3] = {1, 2, 3};
	int b[4] = {1, 2, 3, 4};
	if (sizeof(a) == sizeof(b))
	{
		for (size_t i = 0; i < sizeof(a); ++i)
			if (a[i] != b[i])
			{
				cout << "a != b" << endl;
				return 0;
			}
		cout << "a == b" << endl;
	}
	cout << "a != b" << endl;

	vector<int> v1 = {1, 2, 3};
	vector<int> v2 = {1, 2, 3, 4};
	cout << (v1 == v2 ? "v1 == v2" : "v1 != v2") << endl;
	return 0;
}
