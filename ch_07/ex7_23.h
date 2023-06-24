#include <iostream>
#include <string>

class screen {
   public:
    typedef std::string::size_type pos;
    screen() = default;
    screen(pos ht, pos wd, char c)
        : height(ht), width(wd), contents(ht * wd, c) {}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    screen &move(pos r, pos c);
    void some_member() const;

   private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr = 0;
};
inline screen &screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}
char screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}
