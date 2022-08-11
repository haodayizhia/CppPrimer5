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

// use `using` for 2.6.2

#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::string;

class Sales_data
{
public:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(int argc, char *argv[])
{
    Sales_data total, currData;
    // 保存计数
    int cnt = 1;
    double price = 0.0;
    // 保存第一个Sales_data
    if (cin >> total.bookNo >> total.units_sold >> price)
    {
        total.revenue = total.units_sold * price;
        // 循环读入
        while (cin >> currData.bookNo >> currData.units_sold >> price)
        {
            currData.revenue = currData.units_sold * price;
            if (currData.bookNo == total.bookNo)
            {
                total.units_sold += currData.units_sold;
                total.revenue += currData.revenue;
                ++cnt;
            }
            else
            {
                cout << total.bookNo << " occur " << cnt << " times " << endl;
                cout << total.bookNo << ' ' << total.units_sold << ' ' << total.revenue << ' ';
                if (total.units_sold != 0)
                    cout << total.revenue / total.units_sold << endl;
                total.bookNo = currData.bookNo;
                total.revenue = currData.revenue;
                total.units_sold = currData.units_sold;
            }
        }
        cout << total.bookNo << ' ' << total.units_sold << ' ' << total.revenue << ' ';
        if (total.units_sold != 0)
            cout << total.revenue / total.units_sold << endl;
        return 0;
    }
    return -1;
}
