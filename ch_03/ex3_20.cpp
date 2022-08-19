#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    int in;
    vector<int> ivec;
    while (cin >> in)
        ivec.push_back(in);
    for (vector<int>::size_type i = 0; i + 1 < ivec.size(); ++i)
        cout << ivec[i] + ivec[i + 1] << ' ';
    cout << endl;
    for (vector<int>::size_type i = 0; i < (ivec.size() + 1) / 2; ++i)
        cout << ivec[i] + ivec[ivec.size() - 1 - i] << ' ';
    cout << endl;
    return 0;
}
