#include <string>
#include <iostream>

using namespace std;

using namespace std;

class HasPtr {
public:
    HasPtr (const string &s = string()) : ps (new string(s)), i(0) {}
    HasPtr (const HasPtr &hp) : ps (new string(*(hp.ps))), i(hp.i) {}
    
    HasPtr& operator=(const HasPtr& hp) {
        ps = new string(*(hp.ps));
        i = hp.i;
        return *this;
    }
    
    void getPs() {cout << (*ps) << endl;}
    void setPs() {*ps = "Brandon";}

    ~HasPtr() {
        cout << "Run destructor" << endl;
        delete ps;
    }
private:
    string *ps;
    int i;
};

bool fcn(const HasPtr *trans, HasPtr accum) {

    HasPtr p1(*trans), p2(accum);
    return true;
}
int main() {
    HasPtr p1("Brandon");
    HasPtr p2("Stella");
    fcn(&p1, p2);
    int i;
    cin >> i; 


    return 0;
}
