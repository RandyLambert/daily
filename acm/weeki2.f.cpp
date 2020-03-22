#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

char a[205],str[205];
char s[27]={'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'};
int main()
{
    while(gets(a))
    {
        if(strcmp(a,"ENDOFINPUT")==0)
        {
            break;
        }
        if(strcmp(a,"START")==0)
        {
            gets(str);
            int len=strlen(str);
            for(int i=0;i<len;i++)
            {
                if(str[i]>='A'&&str[i]<='Z')
                str[i]=s[str[i]-'A'];
            }
            printf("%s\n",str);
        }
    }
    return 0;
}

