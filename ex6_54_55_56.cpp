using namespace std;

#include <iostream>
#include <vector>

int test(int, int);

int my_plus(int num1, int num2) { return num1 + num2; }
int my_minus(int num1, int num2) { return num1 - num2; }
int my_times(int num1, int num2) { return num1 * num2; }
int my_divide(int num1, int num2) { return num1 / num2; }

int main(int argc, char* argv[]) {
  vector<decltype(test)*> vf = {my_plus, my_minus, my_times, my_divide};
  cout << vf[0](4, 2) << endl;
  cout << vf[1](4, 2) << endl;
  cout << vf[2](4, 2) << endl;
  cout << vf[3](4, 2) << endl;
}

/*
typedef int test(int, int);
int main(int argc, char* argv[]) { vector<test*> vf; }
typedef int (*test)(int, int);
int main(int argc, char* argv[]) { vector<test> vf; }

using test = int(int, int);
int main(int argc, char* argv[]) { vector<test*> vf; }

using test = int(*)(int, int);
int main(int argc, char* argv[]) { vector<test> vf; }
*/
