#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int a[3] = {1, 2, 3};
	for (int *i = begin(a); i != end(a); ++i)
	{
		*i = 0;
		cout << *i << ' ';
	}
	cout << endl;
	return 0;
}
