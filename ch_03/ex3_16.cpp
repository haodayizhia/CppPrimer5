#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

template <typename T>
void print(const T &a)
{
	cout << a.size() << ' ';
	for (auto i : a)
		cout << i << ' ';
	cout << endl;
}

int main(int argc, char *argv[])
{
	vector<int> v1;
	print(v1);
	vector<int> v2(10);
	print(v2);
	vector<int> v3(10, 42);
	print(v3);
	vector<int> v4{10};
	print(v4);
	vector<int> v5{10, 42};
	print(v5);
	vector<string> v6{10};
	print(v6);
	vector<string> v7{10, "hi"};
	print(v7);
	return 0;
}
