#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	char c1[] = "w";
	char c2[] = "hy";
	strcat(c1, c2);
	// c3不能为空?
	char c3[4];
	strcpy(c3, c1);
	for (size_t i = 0; i <= strlen(c3); ++i)
		cout << c3[i];
	cout << endl;
	cout << "c3 size: " << strlen(c3) << endl;
	return 0;
}
