#ifndef VIEW_H_
#define VIEW_H_
#include <iostream>
#include <algorithm>
#include "Init.h"
class UI_Login
{
public:
    static UI_Login *getInstance(){return uilogin;}
    void Login_Main();
    void View_Main();
    bool Login();
    bool Zhuce();
    void All_Lu();
    void Dan_Lu();
    void Min_Lu();
private:
    UI_Login(){}
    UI_Login(const UI_Login& c){}
    static UI_Login *uilogin;
};

UI_Login * UI_Login::uilogin = new UI_Login;
UI_Login *OneUIlog = UI_Login::getInstance();

#endif
