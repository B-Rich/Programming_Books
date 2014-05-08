#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    string getName() const {return name;}
    string getAddress() const {return address;}

private:
    string name;
    string address;
}
