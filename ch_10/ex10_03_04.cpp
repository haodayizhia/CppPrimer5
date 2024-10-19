#include <iostream>
#include <numeric>
#include <vector>
int main(int argc, char *argv[]) {
    // 10.3
    std::vector<int> ivec = {1, 2, 3};
    std::cout << std::accumulate(ivec.cbegin(), ivec.cend(), 0) << std::endl;
    // 10.4
    std::vector<double> dvec = {1.2, 2.1, 3.3};
    std::cout << std::accumulate(dvec.cbegin(), dvec.cend(), 0) << std::endl;
    // 输出结果为6而不是6.6, 因为
    // accumulate的第三个参数决定了参与运算的元素类型,
    // 序列中的元素类型必须与第三个元素匹配,
    // 或者转换为第三个参数的类型
    // 所以都被转换为了int类型
}
