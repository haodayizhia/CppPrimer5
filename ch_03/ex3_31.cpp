#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int a[10];
	for (size_t i = 0; i < 10; ++i)
	{
		a[i] = i;
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}
