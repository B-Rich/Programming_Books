#include <string>
#include <iostream>

using namespace std;

using namespace std;

class HasPtr {
public:
    HasPtr (const string &s = string()) : ps (new string(s)), i(0) {}
    HasPtr (const HasPtr &hp) : ps (new string(*(hp.ps))), i(hp.i) {}
    
    void getPs() {cout << (*ps) << endl;}
    void setPs() {*ps = "Brandon";}
private:
    string *ps;
    int i;
};

int main() {
    HasPtr p("Hello");
    HasPtr p2(p);
    p.setPs();
    p.getPs();
    p2.getPs();


    return 0;
}
