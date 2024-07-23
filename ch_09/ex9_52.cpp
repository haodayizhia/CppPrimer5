// Type your code here, or load an example.
#include <iostream>
#include <stack>

int main(int argc, char* argv[]) {
    std::string expr = "(1+2)/(3*4)";
    std::stack<char> stk;
    for (auto i : expr) {
        if (i == ')') {
            while (stk.top() != '(') stk.pop();
            stk.pop();
        } else
            stk.push(i);
    }
    std::string s;
    while (!stk.empty()) {
        s.insert(s.begin(), stk.top());
        stk.pop();
    }
    std::cout << s << std::endl;
    return 0;
}
