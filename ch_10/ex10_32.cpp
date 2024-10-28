#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "../include/Sales_item.h"

int main(int argc, char *argv[]) {
    std::istream_iterator<Sales_item> item_iter(std::cin), eof;
    std::vector<Sales_item> vec(item_iter, eof);
    std::sort(vec.begin(), vec.end(), compareIsbn);
    for (auto beg = vec.cbegin(), end = beg; beg != vec.end(); beg = end) {
        end = std::find_if(beg, vec.cend(), [beg](const Sales_item &s) {
            return s.isbn() != beg->isbn();
        });
        std::cout << std::accumulate(beg, end, Sales_item(beg->isbn()))
                  << std::endl;
    }
}
