#define NDEBUG


#include <iostream>
#include <cassert>
using namespace std;

int main() {

    int i = 2;
    assert(i == 1);

    cout << __func__ << endl;
    return 0;

}
