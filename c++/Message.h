//
// Created by adl on 2020/6/26.
//

#ifndef UNTITLED_MESSAGE_H
#define UNTITLED_MESSAGE_H

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <set>
#include "Folder.h"

//* 就是message类和Folder类相互维护一个彼此指针的set，
//析构的时候需要将Folder对象f中的msgs的set成员里所有msg的成员遍历，
//从每个msg的folders的set成员中erase每个包含这个f的项。

/*在main程序执行这个函数在Message析构的时候找进去是Folder的erase段错误。

 *void MessageFolderTest(){
    Message m1("A");
    Message m2("B");
    Message m3("C");
    Folder f1;
    Folder f2;
    Folder f3;
    m1.addFolder(&f1);
    m1.addFolder(&f2);
    m1.addFolder(&f3);
    f1.addMsg(&m3);
    f1.addMsg(&m2);
    f2.addMsg(&m3);
    f3.addMsg(&m2);
//    cout<<"消息"<<&m1<<endl;
//    for(const auto &f:m1.getFolders()){
//        cout<<"盒子"<<f<<endl;
//    }
//    cout<<"----------"<<endl;
//    cout<<"消息"<<&m2<<endl;
//    for(const auto &f:m2.getFolders()){
//        cout<<"盒子"<<f<<endl;
//    }
    cout<<"----------"<<endl;
    cout<<"消息"<<&m3<<endl;
    for(const auto &f:m3.getFolders()){
        cout<<"盒子"<<f<<endl;
    }
    cout<<"----------"<<endl;
    cout<<"盒子"<<&f1<<endl;
    for(const auto &i:f1.getMsgs()){
        cout<<i<<endl;
        cout<<i->getContents()<<endl;
    }
    cout<<"----------"<<endl;
    cout<<"盒子"<<&f2<<endl;

    for(const auto &i:f2.getMsgs()){
        cout<<i<<endl;
        cout<<i->getContents()<<endl;
    }
    cout<<"----------"<<endl;
    cout<<"盒子"<<&f3<<endl;
    for(const auto &i:f3.getMsgs()){
        cout<<i<<endl;
        cout<<i->getContents()<<endl;
    }
    cout<<"----------"<<endl;
//    f1.remMsg(&m3);
//    f2.remMsg(&m3);


}

 */

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);

public:
    explicit Message(const std::string &str = ""):contents(str){}

    Message(const Message &);

    Message &operator=(const Message &);

    virtual ~Message();

    void save(Folder &);

    void remove(Folder &);

    void addFolder(Folder *);
    void remFolder(Folder *);

    const std::string &getContents() const;

    const std::set<Folder *> &getFolders() const;

private:
    std::string contents;
    std::set<Folder *> folders;

    void add_to_Folders(const Message &);

    void remove_from_Folders();
};


#endif //UNTITLED_MESSAGE_H
