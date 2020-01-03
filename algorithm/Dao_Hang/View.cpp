#include "View.h"
using std::cin;
using std::cout;
using std::endl;
extern info_user login_data;
extern std::unordered_map<int, myString> mp;
extern my_MySql *OneMysql;
extern Dijkstra *OneDijk;
extern UI_Login *OneUIlog;
extern int maxdin;

void UI_Login::Login_Main()
{
    int choice;
    do
    {
        system("clear");
        std::cout << "\n==============================\n";
        std::cout << "********* 校园导航系统 *********\n";
        std::cout << "         [1]  登录\n";
        std::cout << "         [2]  注册\n";
        std::cout << "         [3]  退出\n";
        std::cout << "\n==============================\n";
        std::cout << "请输出你的选择：";
        std::cin >> choice;
        switch (choice)
        {
            //输入用户名和密码
        case 1:
            if (Login())
            {
                UI_TuMain(OneMysql);
                return;
            }
            break;
        case 2:
            if (Zhuce())
            {
                return;
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            break;
        }
    } while (true);
}

bool UI_Login::Login()
{
    int flag;
    do
    { //输入用户信息直到正确为止

        flag = 0;
        cout << "[小于30字节]usrname:";
        cin >> login_data.username;

        cout << "[小于30字节]password:";
        cin >> login_data.password;

        if (!OneMysql->Query_User(login_data))
        {
            printf("useruid = %d", login_data.uid);
            printf("登录成功\n");
            return true;
        }
        else
        {
            printf("你的用户名和密码不匹配，请重新输入，退出请输【10086】，继续请输【0】");
            cin >> flag;
            if (flag == 10086)
            {
                return 0;
            }
        }
    } while (true);
}
bool UI_Login::Zhuce()
{

    int flag = 0;
    do
    {
        std::cout << "[请小于30个字符]usrname:";
        cin >> login_data.username;

        std::cout << "[请小于30个字符]password:";
        cin >> login_data.password;

        std::cout << "[请小于30个字符]mibao:";
        cin >> login_data.mibao;

        std::cout << "[1]是n|[2]是w|sex:";
        std::cin >> login_data.sex;

        if (OneMysql->Insert_User(login_data))
        {
            flag = 1;
            std::cout << "注册成功,输回车返回登录\n";
            return 0;
        }
        else
        {
            std::cout << "你的用户名以使用过，请重新输入，或者选择退出，退出请输【10086】，继续请输【0】";
            std::cin >> flag;
            if (flag == 10086)
            {
                return 0;
            }
        }
    } while (true);
}

void UI_Login::Init_All_Lu(my_MySql *OneMysql)
{
    OneMysql->Init_Dijk(OneDijk);
    OneMysql->Init_Map(mp);
    cout<<"dsadasdasdas"<<mp.size()<<" dss  "<<endl;
    for(auto x: mp){
        cout<<x.first<<"   dsds"<<x.second<<endl;
    }
    //maxdin = OneMysql->maxxdin;
}

void UI_Login::Print_All_Lu(Dijkstra *One_Dijk)
{
    Init_All_Lu(OneMysql);
    One_Dijk->Print_All();
}

void UI_Login::Dan_Lu(Dijkstra *One_Dijk)
{
    cout<<"请输入起点";
    myString x;
    cin>>x;
    int ans;
    for(auto tp : mp){
        if(tp.second.compare(x)==0){
            ans = tp.first;
        }
    }
    One_Dijk->solve(5,ans);
    One_Dijk->Print_Dan();
}

void UI_Login::UI_TuMain(my_MySql *OneMysql)
{

    int choice;
    do
    {
        system("clear");
        std::cout << "\n==============================\n";
        std::cout << "********* 校园导航系统 *********\n";
        std::cout << "         [1]  加点\n";
        std::cout << "         [2]  加边\n";
        std::cout << "         [3]  打印图\n";
        std::cout << "         [4]  打印最短路\n";
        std::cout << "         [5]  打印最小生成树\n";
        std::cout << "         [6]  删点\n";
        std::cout << "         [7]  删边\n";
        std::cout << "         [8]  退出\n";
        std::cout << "\n==============================\n";
        std::cout << "请输出你的选择：";
        std::cin >> choice;
        myString x;
        switch (choice)
        {
            //输入用户名和密码
        case 1:
            
            cout<<"请输入要插的点叫什么名字\n";
            cin>>x;
            if (OneMysql->Insert_Dian(x))
            {
                break;
            }
            break;
        case 2:
            lu_data tp;
            cout<<"请输入要插的路的起点\n";
            cin>>tp.u;
            cout<<"请输入要插的路的终点\n";
            cin>>tp.v;
            cout<<"请输入要插的路有多长\n";
            cin>>tp.w;

            if (OneMysql->Insert_Lu(tp))
            {
                break;
            }
            break;
        case 3:
            Print_All_Lu(OneDijk);
            break;
        case 4:
            Dan_Lu(OneDijk);
            break;
        case 5:
            /* if (OneMysql->Insert_Lu())
               {
               return;
               }
               break;*/    
        case 6:
            cout<<"请输入要删的点叫什么名字\n";
            cin>>x;
            OneMysql->Delete_Dian(x);
            break;

        case 7:
            cout<<"请输入要删的路的起点\n";
            cin>>tp.u;
            cout<<"请输入要删的路的终点\n";
            cin>>tp.v;
            cout<<"请输入要删的路有多长\n";
            cin>>tp.w;
            OneMysql->Delete_Lu(tp);
            break;
            
        case 8:
            exit(0);
            break;
        default:
            break;
        }
    }while (true);
}
