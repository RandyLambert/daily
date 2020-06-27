//
// Created by adl on 2020/6/26.
//

#ifndef UNTITLED_FOLDER_H
#define UNTITLED_FOLDER_H
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "Message.h"

class Message;
class Folder {
friend class Message;

public:
    Folder():msgs(std::set<Message*>()){}
    void addMsg(Message*);
    void remMsg(Message*);

    const std::set<Message *> &getMsgs() const;

private:
    std::set<Message*>msgs;
};



#endif //UNTITLED_FOLDER_H
