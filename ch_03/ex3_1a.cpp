// use `using` for 1.4.1

ex1_9
// sum the numbers from 50 to 100 (use while)
#include <iostream>

using std::cout; using std::endl;

int main(int argc, char *argv[])
{
	int sum = 0, val = 50;
	while (val <= 100)
	{
		sum += val;
		++val;
	}
	cout << "sum of 50 to 100 inclusive is " << sum << endl;
	return 0;
}

// output: the sum is 3825

ex1_10
#include <iostream>

using std::cout; using std::endl;

int main(int argc, char *argv[])
{
	int val = 10;
	while (val >= 0)
	{
		cout << val << ' ';
		--val;
	}
	cout << endl;
	return 0;
}

ex1_11
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main(int argc, char *argv[])
{
	int num1, num2, a;
	cout << "Please input two integer number: " << endl;
	cin >> num1 >> num2;
	if (num1 >= num2)
	{
		a = num2;
		while (a <= num1)
		{
			cout << a << ' ';
			++a;
		}
	}
	if (num1 < num2)
	{
		a = num1;
		while (a <= num2)
		{
			cout << a << ' ';
			++a;
		}
	}
	cout << endl;
	return 0;
}
