#include <string>
#include <iostream>
#include <set>

using namepspace std;

class Folder;

class Message {
    friend class Folder;
public:
    explicit Message(const string &str = "") : contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
private:
    string contents;
    set<Folder*> folders;
    void addToFolders(const Message&);
    void removeFromFolders();
}; 

void Message::addtoFolders(const Message &m) {
    for (auto f : m.folders) {
        f->addMsg(this);
    }
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

class Folder {
    friend class Message;
public:
    Folder(string name) : folderName(name) {}

private:
    string folderName;
    set<Message*> messages;
    void addMsg(Message*);
    void remMsg(Message*);
};

int main() { 
    return 0;
}
