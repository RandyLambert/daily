#include "View.h"

void UI_Login(int conn_fd)
{
    int choice;
    do
    {
        system("clear");
        std::cout<<"\n==============================\n";
        std::cout<<"********* 校园导航系统 *********\n";
        std::cout<<"         [1]  登录\n";
        std::cout<<"         [2]  注册\n";
        std::cout<<"         [3]  找回密码\n";
        std::cout<<"         [4]  退出\n";
        std::cout<<"\n==============================\n";
        std::cout<<"请输出你的选择：";
        std::cin>>choice;
        switch (choice)
        {
            //输入用户名和密码
        case 1:
            if (login(conn_fd))
            {
                return;
            }
            break;
        case 2:
            if (UI_zhuce(conn_fd))
            {
                return;
            }
            break;
        case 3:
            findpassword(conn_fd);
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
        }
    } while (1);
}

int login(int conn_fd)
{

	int flag;
	do
	{ //输入用户信息直到正确为止


		PACK *senddata = NULL;
		senddata = (PACK *)malloc(sizeof(PACK));
		senddata->type = LOGIN;

		flag = 0;
		printf("[小于20字节]usrname:");
		scanf("%s", senddata->data.send_name);

		printf("[小于20字节]password:");
		scanf("%s", senddata->data.recv_name);

		senddata->data.send_fd = conn_fd;
		input_userinfo(conn_fd, senddata); //发

		PACK *recvdata = NULL;
		recvdata = (PACK *)malloc(sizeof(PACK));

		int len_pack = LEN_PACK;
		char *p = (char *)(recvdata);
		while (len_pack > 0)
		{
			size_t n;
			if ((n = recv(conn_fd, p, len_pack, 0)) < 0)
			{
				if (errno != EAGAIN)
				{
					perror("recv");
					exit(1);
				}
			}

			len_pack -= n;
			p += n;
		}

		if (recvdata->type == LOGIN)
		{
			if (recvdata->data.mes[0] == 'y')
			{
				flag = 1;
				useruid = recvdata->data.recv_fd;
				strcpy(username, senddata->data.send_name);
				strcpy(password, senddata->data.recv_name);
				printf("useruid = %d", useruid);
				printf("登录成功\n");
				return 1;
			}
			else
			{
				printf("你的用户名和密码不匹配，请重新输入，退出请输【10086】，继续请输【0】");
				scanf("%d", &flag);
				getchar();
				if (flag == 10086)
				{
					return 0;
				}
			}
		}
		free(recvdata);
		free(senddata);
	} while (1);
	
}
int UI_zhuce(int conn_fd)
{

    int flag = 0;
    do
    {
        std::cout<<"[请小于20个字符]usrname:";
        scanf("%s", senddata->data.send_name);

        std::cout<<"[请小于20个字符]password:";
        scanf("%s", senddata->data.recv_name);

        std::cout<<"[请小于20个字符]mibao:";
        scanf("%s", senddata->data.mes);

        std::cout<<"[1]是n|[2]是w|sex:";
        std::cin>>senddata->data.send_fd;

        if (recvdata->type == REGISTER)
        {
            if (recvdata->data.mes[0] == 'y')
            {
                flag = 1;
                //recive(conn_fd,recvdata);
                std::cout<<"注册成功,输回车返回登录\n";
                return 0;
            }
            else
            {
                std::cout<<"你的用户名以使用过，请重新输入，或者选择退出，退出请输【10086】，继续请输【0】");
                std::cin>>flag;
                if (flag == 10086)
                {
                    return 0;
                    //exit(0);
                }
            }
        }
    } while (1);
}
