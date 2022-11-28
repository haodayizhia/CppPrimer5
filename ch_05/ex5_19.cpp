#include <iostream>
#include <vector>

using namespace std;

int main() {
    string rsp;
    do {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() < s2.size())
            cout << s1 << endl;
        else if (s1.size() > s2.size())
            cout << s2 << endl;
    } while ((cin >> rsp) && rsp[0] != 'n');
    return 0;
}
