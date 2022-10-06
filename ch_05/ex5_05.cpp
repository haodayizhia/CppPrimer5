#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
	string lettergrade;
	int grade = 100;
	if (grade < 60)
		lettergrade = scores[0];
	else
	{
		lettergrade = scores[(grade - 50) / 10];
		if (grade != 100)
			if (grade % 10 > 7)
				lettergrade += '+';
			else if (grade % 10 < 3)
				lettergrade += '-';
	}
	return 0;
}
