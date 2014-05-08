#include <initializer_list>
#include <iostream>


using namespace std;

void print(initializer_list<int> list) {

    for (auto beg = list.begin(); beg != list.end(); beg++)
        cout << *beg << endl;
} 

int main() {
    print({1,2,3,4,5});
    return 0;

} 
