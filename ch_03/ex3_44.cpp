#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	using int_array = int[4];
	// typedef int int_array[4];
	int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
	for (int_array *i = begin(ia); i != end(ia); ++i)
	{
		for (int *j = begin(*i); j != end(*i); ++j)
			cout << *j << ' ';
		cout << endl;
	}
	return 0;
}
