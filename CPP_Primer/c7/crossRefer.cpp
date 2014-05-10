#include <iostream>

class X {
public:
    class Y;
    Y* yRef;
}; 

class Y {
public:
    X x;
};

int main() {

    X x;
    x.yRef;
    Y y;
    y.x;
    return 0;
}
