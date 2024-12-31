#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<int>> pvec() {
    return std::make_shared<std::vector<int>>();
}
void input(std::shared_ptr<std::vector<int>> p) {
    int i;
    while (std::cin >> i) p->push_back(i);
}
void print(std::shared_ptr<std::vector<int>> p) {
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::copy(p->cbegin(), p->cend(), out_iter);
    std::cout << std::endl;
}
int main(int argc, char *argv[]) {
    auto p = pvec();
    input(p);
    print(p);
    return 0;
}
