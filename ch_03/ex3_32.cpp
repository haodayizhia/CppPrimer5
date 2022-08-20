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
	int b[10];
	for (size_t i = 0; i < 10; ++i)
	{
		b[i] = a[i];
		cout << b[i] << ' ';
	}
	cout << endl;
	
	vector<int> iv1;
	for (int i = 0; i < 10; ++i)
		iv1.push_back(i);
	vector<int> iv2 = iv1;
	for (auto &i : iv2)
		cout << i << ' ';
	cout << endl;
	return 0;
}
