#include "local_static.h"
#include <iostream>

using namespace std;
int main() {

    for (int i = 0; i < 10; i++) 
        cout << count_calls() << endl;

    return 0;
}
