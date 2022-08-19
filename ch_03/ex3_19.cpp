#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> ivec1(10, 42);
    vector<int> ivec2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> ivec3;
    for (int i = 0; i < 10; ++i)
        ivec3.push_back(42);
    return 0;
}
