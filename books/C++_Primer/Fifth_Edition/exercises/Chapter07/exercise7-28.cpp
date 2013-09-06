#include <iostream>
#include <string>

using std::cout;

class Screen {

public:
    typedef std::string::size_type pos;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht*wd, ' ') { }
    Screen(pos ht, pos wd, char c) : height(ht), width(wd),
                                     contents(ht*wd, c) { }

    char get() const
        { return contents[cursor]; }
    inline char get(pos ht, pos wd) const;

    Screen set(char);
    Screen set(pos, pos, char);

    void some_member() const;
    Screen move(pos r, pos c);

    Screen display(std::ostream &os)
            { do_display(os); return *this; }
    const Screen display(std::ostream &os) const
            { do_display(os); return *this; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;

    void do_display(std::ostream &os) const {os << contents;}
};

void Screen::some_member() const
{
    ++access_ctr;
}

inline
Screen Screen::move(pos r, pos c)
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

inline Screen Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}

int main()
{
    Screen myScreen(5, 5, 'X');

    // move creates first copy, then set creates a copy of this copy where it
    // sets '#' and then this one is displayed.
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";

    // Shows the original unmodified screen.
    myScreen.display(cout);
    cout << "\n";
}
