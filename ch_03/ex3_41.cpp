#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int i[] = {1, 2, 3};
	vector<int> iv(begin(i), end(i));
	for (auto &j : iv)
		cout << j << ' ';
	cout << endl;
	return 0;
}
