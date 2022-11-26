// for版本
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec1 = {0, 1, 1, 2};
    vector<int> ivec2 = {0, 1, 1, 2, 3, 5, 8};
    vector<int>::size_type mini_size =
        ivec1.size() > ivec2.size() ? ivec2.size() : ivec1.size();
    for (decltype(ivec1.size()) i = 0; i < mini_size; ++i)
        if (ivec1[i] != ivec2[i]) {
            cout << "false" << endl;
            return 0;
        }
    cout << "true" << endl;
    return 0;
}
// while版本
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec1 = {0, 1, 1, 2};
    vector<int> ivec2 = {0, 1, 1, 2, 3, 5, 8};
    vector<int>::size_type mini_size =
        ivec1.size() > ivec2.size() ? ivec2.size() : ivec1.size();
    decltype(ivec1.size()) i = 0;
    while (i < mini_size && ivec1[i] == ivec2[i]) ++i;
    if (i == mini_size)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
