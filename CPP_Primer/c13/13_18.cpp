#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Employee {
public:
    Employee() : ID(IDcount++), name("") {}
    Employee(string name) : name(name), ID(IDcount++) {}
    Employee(const Employee& e) : name(e.name), ID(IDcount++){}
    
    Employee& operator=(const Employee& e) {
        name = e.name;
    }

    void getID() {cout << "Employee: " <<  ID << endl;}
private:
    string name;
    int ID;
    static int IDcount;
};

int Employee::IDcount = 0;

int main() {
    Employee e1;
    e1.getID();
    Employee e2;
    e2.getID();

    Employee e3 = e1;
    e3.getID();

    Employee e4;
    e4 = e2;
    e4.getID();


    return 0;
}

