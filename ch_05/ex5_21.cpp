#include <iostream>
#include <vector>

using namespace std;

int main() {
    string pre_word, word;
    int repeat = 0;
    while (cin >> word) {
        if (word == pre_word && isupper(word[0])) {
            repeat = 1;
            break;
        }
        pre_word = word;
    }
    if (repeat)
        cout << word << " repeated" << endl;
    else
        cout << "no repeated" << endl;
    return 0;
}
