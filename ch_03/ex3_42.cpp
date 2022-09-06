#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    vector<int> ivec = {1, 2, 3};
    int arr[3];
    for(size_t i = 0; i < sizeof(arr); ++i)
        arr[i] = ivec[i];
    return 0;
}
