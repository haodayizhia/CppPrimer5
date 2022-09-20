#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  // 第一种简单但是第二种易读
	double grade;
	cin >> grade;
	string finalgrade = grade > 90 ? "high pass" : grade < 60 ? "fail"
											   : grade > 75	  ? "pass"
															  : "low pass";
	cout << finalgrade << endl;
	if (grade > 90)
		cout << "pass" << endl;
	else if (grade < 60)
		cout << "fail" << endl;
	else if (grade > 75)
		cout << "pass" << endl;
	else
		cout << "low pass" << endl;
	return 0;
}
