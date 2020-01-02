#include "View.h"
using std::cin;
using std::cout;
using std::endl;
extern info_user login_data;
extern unordered_map<int,myString> mp;
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
        std::cout << "         [3]  找回密码\n";
        std::cout << "         [4]  退出\n";
        std::cout << "\n==============================\n";
        std::cout << "请输出你的选择：";
        std::cin >> choice;
        switch (choice)
        {
            //输入用户名和密码
        case 1:
            if (Login())
            {
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
            //findpassword();
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
        }
    } while (1);
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

        if (1)
        {
            printf("useruid = %d", login_data.uid);
            printf("登录成功\n");
            return 1;
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

        if (1)
        {
            flag = 1;
            std::cout << "注册成功,输回车返回登录\n";
            return 0;
        }
        else
        {
            std::cout<<"你的用户名以使用过，请重新输入，或者选择退出，退出请输【10086】，继续请输【0】";
            std::cin >> flag;
            if (flag == 10086)
            {
                return 0;
            }
        }
    } while (true);
}

void UI_Login::Dan_Lu(const Dijkstra *One_Dijk){
    cout<<mp[0]<<endl;
    for(int i = 1;i < 10;i++){
        cout<<"====>"<<mp[i]<<endl;
    }

}