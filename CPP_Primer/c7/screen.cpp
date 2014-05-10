#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Screen;//incomplete type
class windowMgr {
public:
    using screenIndex = vector<Screen>::size_type;
    void clear(screenIndex);
    windowMgr();
private:
    vector<Screen> screens;
};



class Screen {

public:
    using pos = string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' '){}
    inline char get() const {return contents[cursor];}
    char get(pos r, pos c) const;
    Screen &move(pos r, pos c);
    Screen &set(char ch);
    Screen &set(pos r, pos c, char ch);
    Screen &display(ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;

private:
    void do_display(ostream &os) const {
        os << contents;
    }
    
    friend void windowMgr::clear(screenIndex);

};

inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c]; 
}


Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen &Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch) {
    contents[r*width + c] = ch;
    return *this;
}

windowMgr::windowMgr() : screens({Screen(24, 80, ' ')}){}

void windowMgr::clear(screenIndex i) {

    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

int main() {
    windowMgr mgr;
    mgr.clear(0);
}
