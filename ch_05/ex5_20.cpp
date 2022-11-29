// inappropriate
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string pre_word, word;
    while (cin >> word && (pre_word.empty() || (pre_word != word))) {
        pre_word = word;
        word = '\0';
    }
    if (!word.empty() && (pre_word == word))
        cout << word << " repeated" << endl;
    else
        cout << "no repeated" << endl;
    return 0;
}

// better
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string pre_word, word;
    int repeat = 0;
    while (cin >> word) {
        if (word == pre_word) {
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
