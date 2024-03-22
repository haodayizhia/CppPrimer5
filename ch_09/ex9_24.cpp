#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<int> iv;
    std::cout << iv.front() << std::endl; //Thread 1 received signal SIGSEGV, Segmentation fault.
    std::cout << iv.back() << std::endl;  //Thread 1 received signal SIGSEGV, Segmentation fault.
    std::cout << iv[0] << std::endl;      //Thread 1 received signal SIGSEGV, Segmentation fault.
    std::cout << iv.at(0) << std::endl;   //terminate called after throwing an instance of 'std::out_of_range'
    return 0;
}
