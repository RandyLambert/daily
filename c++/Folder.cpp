//
// Created by adl on 2020/6/26.
//

#include "Folder.h"
#include "Message.h"
void Folder::addMsg(Message*m) {
    msgs.insert(m);
    m->folders.insert(this);
}
void Folder::remMsg(Message *m){
    std::cout<<"m "<<m<<"  "<<"f "<<this<<std::endl;
//    std::cout<<m->getContents()<<std::endl;
//    puts("@");
    for(const auto &m:msgs){
        std::cout<<m<<std::endl ;
    }
    auto f=msgs.find(m);
    if(f!=msgs.cend()){
        std::cout<<"m:"<<*f<<std::endl;
        msgs.erase(f);
        std::cout<<"!!!"<<std::endl;
    }else{
        std::cout<<"not find"<<std::endl;
    }
  //错误出在这里

//    puts("?");
    m->folders.erase(this);
//    puts("!");
}

const std::set<Message *> &Folder::getMsgs() const {
    return msgs;
}
