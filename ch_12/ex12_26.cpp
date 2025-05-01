#include <iostream>
#include <iterator>

int main(int argc, char* argv[]) {
    size_t n = 42;
    std::string s;
    std::ostream_iterator<std::string> out_iter(std::cout, " ");
    std::allocator<std::string> alloc;
    auto p = alloc.allocate(42);
    std::string* q = p;
    while (std::cin >> s && q != p + n) alloc.construct(q++, s);
    std::copy(p, q, out_iter);
    std::cout << std::endl;
    for (auto i = p; i != q; ++i) alloc.destroy(i);
    alloc.deallocate(p, q - p);
    return 0;
}
