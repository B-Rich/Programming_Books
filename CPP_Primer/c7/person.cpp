#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person() = default;
    Person(const string &name, const string& address) : name(name), address(address) {}
    string getName() const {return name;}
    string getAddress() const {return address;}

private:
    //in class initialization
    string name = "Brandon";
    string address = "Defoors";

friend istream &read(istream &is, Person &ps);
friend ostream &print(ostream &os, const Person &p);
};


istream &read(istream &is, Person &ps) {
    is >> ps.name >> ps.address;
    return is;
}

ostream &print(ostream &os, const Person &p) {
    os << p.getName() << " " << p.getAddress() << " ";
    return os;
}

int main() {
    Person p("Stella", "Westmar");
    //read(cin, p);
    print(cout, p)  << endl;

    return 0;
}
