#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	vector<int> ivec = {1, 2, 3};
	for (auto &i : ivec)
		i = (i % 2 ? i * 2 : i);
	return 0;
}
