//
// Created by adl on 2020/6/26.
//



#include "Message.h"
#include "Folder.h"

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}
//void Message::save2(const Folder &f) {
//    folders.insert(&f);
//    f.addMsg(this);
//}
void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
    for(auto &f:m.folders){
        f->addMsg(this);
    }
}

Message::Message(const Message &m):contents(m.contents),folders(m.folders) {
    add_to_Folders(m);
}

void Message::remove_from_Folders() {
    for( auto &f:folders){
        puts("删除");
        std::cout<<"f "<<f<<" "<<"m "<<this<<std::endl;
        f->remMsg(this);
        puts("del");
    }
}

const std::set<Folder *> &Message::getFolders() const {
    return folders;
}

Message::~Message() {
    puts("析构");
    remove_from_Folders();
}

Message &Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents=rhs.contents;
    folders=rhs.folders;
    add_to_Folders(*this);
    return *this;
}

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for (auto &f:lhs.folders) {
        f->remMsg(&lhs);
    }
    for (auto &f:rhs.folders) {
        f->remMsg(&rhs);
    }
    swap(lhs.folders,rhs.folders);
    swap(lhs.contents,rhs.contents);
    for( auto &f:lhs.folders){
        f->addMsg(&lhs);
    }
    for( auto &f:rhs.folders){
        f->addMsg(&rhs);
    }
}

void Message::addFolder(Folder *f) {
    folders.insert(f);
    f->msgs.insert(this);
}

void Message::remFolder(Folder *f) {
    folders.erase(f);
    f->msgs.erase(this);
}

const std::string &Message::getContents() const {
    return contents;
}


