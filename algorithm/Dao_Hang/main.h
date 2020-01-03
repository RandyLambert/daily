#ifndef MAIN_H_
#define MAIN_H_
#include <unordered_map>
#include "Tu_Alog.h"
#include "Template_Tool.hpp"
#include "View.h"
#include "Init.h" 
#include "myString.h"

Kruskal * Kruskal::kruskal = new Kruskal;
Kruskal *OneKrus = Kruskal::getInstance();

Dijkstra *Dijkstra::dijkstra = new Dijkstra;
Dijkstra *OneDijk = Dijkstra::getInstance();

my_MySql * my_MySql::my_mysql = new my_MySql;
my_MySql *OneMysql = my_MySql::getInstance();

UI_Login * UI_Login::uilogin = new UI_Login;
UI_Login *OneUIlog = UI_Login::getInstance();

std::unordered_map<int, myString> mp;
info_user login_data;

int maxdin = 5;
#endif