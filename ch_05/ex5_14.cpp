#include <iostream>

using namespace std;

int main() {
    string pre_word, word, max_repeat_word;
    int count = 1, max_count = 1;
    while (cin >> word) {
        if (word == pre_word)
            ++count;
        else
            count = 1;
        if (count > max_count) {
            max_count = count;
            max_repeat_word = word;
        }
        pre_word = word;
    }
    if (max_count == 1)
        cout << "now word repeat" << endl;
    else
        cout << max_repeat_word << " occurs continuously " << max_count
             << " times" << endl;
    return 0;
}
