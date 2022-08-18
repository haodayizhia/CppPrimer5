#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	vector<int> ivec;
	vector<int>::size_type i = 0;
	if (ivec.empty() && i < ivec.size())
		ivec[0] = 42;
	return 0;
}
