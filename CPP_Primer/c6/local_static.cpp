#include <iostream>
#include "local_static.h"

using namespace std;
int count_calls() {

    static int ctr = 0; //only initilize once and persist through the program
    return ctr++;

}

