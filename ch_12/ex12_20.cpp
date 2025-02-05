#include "ex12_19.h"
int main(int argc, char *argv[]) {
    std::ifstream in("1.txt");
    StrBlob sb;
    std::string s;
    while (getline(in, s)) sb.push_back(s);
    StrBlobPtr sbp(sb);
    for (auto pbeg = sb.begin(), pend = sb.end(); pbeg != pend; pbeg.incr())
        std::cout << pbeg.deref() << std::endl;
}
