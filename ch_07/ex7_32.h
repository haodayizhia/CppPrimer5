class Screen;

class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

private:
    std::vector<Screen> screens;
};

class Screen
{
    // 声明友元类
    // friend class Window_mgr;
    // 只声明友元类成员函数
    friend void Window_mgr::clear(ScreenIndex);

public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c)
        : height(ht), width(wd), contents(ht * wd, c) {}
    // ex7_24
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    char get() const { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    void some_member() const;
    // ex7_27
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr = 0;
    // ex7_27
    void do_display(std::ostream &os) const { os << contents; }
};
inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}
char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}
void Screen::some_member() const
{
    ++access_ctr;
    std::cout << access_ctr << std::endl;
}
inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}
