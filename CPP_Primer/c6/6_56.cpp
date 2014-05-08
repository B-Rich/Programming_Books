#include <iostream>
#include <vector>

using namespace std;


int add(int a, int b) {
    return a + b;
}


int sub(int a, int b) {
    return a - b;
}


int mul(int a, int b) {
    return a * b;
}


int divide(int a, int b) {
    return a / b;
}


int main() {

    vector<int (*)(int, int)> funcList = {add, sub, mul, divide};

    for (auto p : funcList) {
        cout << p(2,2) << endl;
    }
    return 0;
}
