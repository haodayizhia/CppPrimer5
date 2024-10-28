#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <iterator>

int main(int argc, char *argv[])
{
    std::ifstream in("a.txt");
    std::ofstream out1("b.txt");
    std::ofstream out2("c.txt");
    std::istream_iterator<int> in_iter(in), eof;
    std::ostream_iterator<int> out_iter1(out1, " ");
    std::ostream_iterator<int> out_iter2(out2, "\n");
    std::for_each(in_iter, eof, [&out_iter1, &out_iter2](int i)
                  {
        if (i % 2)
            *out_iter1++ = i;
        else
            *out_iter2++ = i; });
}
