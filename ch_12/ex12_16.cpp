#include <iostream>
#include <memory>

int main(int argc, char *argv[]) {
    std::unique_ptr<int> p1(new int(42));
    std::unique_ptr<int> p2 = p1;
    return 0;
}

报错显示：拷贝构造函数已被删除
/app/main.cpp:6:31: error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int; _Dp = std::default_delete<int>]'
    6 |     std::unique_ptr<int> p2 = p1;
      |                               ^~
In file included from /opt/compiler-explorer/gcc-10.3.0/include/c++/10.3.0/memory:83,
                 from /app/main.cpp:2:
/opt/compiler-explorer/gcc-10.3.0/include/c++/10.3.0/bits/unique_ptr.h:468:7: note: declared here
  468 |       unique_ptr(const unique_ptr&) = delete;
      |       ^~~~~~~~~~
gmake[2]: *** [CMakeFiles/the_executable.dir/build.make:79: CMakeFiles/the_executable.dir/main.cpp.o] Error 1
gmake[1]: *** [CMakeFiles/Makefile2:87: CMakeFiles/the_executable.dir/all] Error 2
gmake: *** [Makefile:91: all] Error 2
