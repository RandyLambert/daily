#ifndef VIEW_H_
#define VIEW_H_
#include <iostream>
#include <algorithm>
#include "Init.h"
#include "myString.h"
#include <unordered_map>
class UI_Login
{
public:
    static UI_Login *getInstance(){return uilogin;}
    void Login_Main();
    void View_Main();
    bool Login();
    bool Zhuce();
    void Init_All_Lu(my_MySql *OneMysql);
    void Print_All_Lu(Dijkstra *One_Dijk);
    void Dan_Lu(Dijkstra *One_Dijk);
    void Min_Lu();
    void UI_TuMain(my_MySql *OneMysql);
private:
    UI_Login(){}
    UI_Login(const UI_Login& c){}
    static UI_Login *uilogin;
};
//extern int maxdin;

#endif
