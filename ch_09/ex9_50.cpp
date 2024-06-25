#include <iostream>
#include <vector>
int main(int argc, char *argv[]) {
    std::vector<std::string> vs = {"1", "2", "12"};
    int sum1 = 0;
    double sum2 = 0;
    for (auto i : vs) sum1 += stoi(i);
    std::cout << sum1 << std::endl;
    for (auto i : vs) sum2 += stod(i);
    std::cout << sum2 << std::endl;
}
