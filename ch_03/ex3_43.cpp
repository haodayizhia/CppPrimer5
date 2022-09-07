#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
	for (auto &i : ia)
	{
		for (auto &j : i)
			cout << j << ' ';
		cout << endl;
	}
	for (size_t i = 0; i < sizeof(ia) / sizeof(ia[0]); ++i)
	{
		for (size_t j = 0; j < sizeof(ia[0]) / sizeof(ia[0][0]); ++j)
			cout << ia[i][j] << ' ';
		cout << endl;
	}
	for (int(*i)[4] = begin(ia); i != end(ia); ++i)
	{
		for (int *j = begin(*i); j != end(*i); ++j)
			cout << *j << ' ';
		cout << endl;
	}
	return 0;
}
