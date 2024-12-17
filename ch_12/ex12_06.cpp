#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> *pvec() { return new std::vector<int>(); }
void input(std::vector<int> *p) {
    int i;
    while (std::cin >> i) p->push_back(i);
}
void print(std::vector<int> *p) {
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::copy(p->cbegin(), p->cend(), out_iter);
    std::cout << std::endl;
}
int main(int argc, char *argv[]) {
    auto p = pvec();
    input(p);
    print(p);
    delete p;
    p = nullptr;
    return 0;
}
