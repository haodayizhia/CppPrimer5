// sum the numbers from 50 to 100 (use while)
#include <iostream>

int main(int argc, char *argv[])
{
	int sum = 0, val = 50;
	while (val <= 100)
	{
		sum += val;
		++val;
	}
	std::cout << "sum of 50 to 100 inclusive is " << sum << std::endl;
	return 0;
}

// output: the sum is 3825
