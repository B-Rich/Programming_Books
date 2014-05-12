#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class numbered {
public:
    numbered() : mysn(rand()) {}
    numbered(const numbered& num) : mysn(rand()) {
        cout << "numbered(const numbered&) " << endl;
    }
        
    int mysn;
};

void f(const numbered &s) {
    cout << s.mysn << endl;
}

int main() {
    numbered a, b = a ,c = b; // copy constructed b, c
    f(a);
    f(b);
    f(c);

    return 0;
}
