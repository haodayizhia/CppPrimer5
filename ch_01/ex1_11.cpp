#include <iostream>
int main(int argc, char *argv[])
{
	int num1, num2, a;
	std::cout << "Please input two integer number: " << std::endl;
	std::cin >> num1 >> num2;
	if (num1 >= num2)
	{
		a = num2;
		while (a <= num1)
		{
			std::cout << a << ' ';
			++a;
		}
	}
	if (num1 < num2)
	{
		a = num1;
		while (a <= num2)
		{
			std::cout << a << ' ';
			++a;
		}
	}
	std::cout << std::endl;
	return 0;
}