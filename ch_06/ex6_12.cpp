// 使用引用更方便，自动管理内存
#include <iostream>

using namespace std;

void exchange(int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}

int main(int argc, char *argv[]) {
    int num1 = 0, num2 = 42;
    exchange(num1, num2);
    cout << num1 << ' ' << num2 << endl;
    return 0;
}
