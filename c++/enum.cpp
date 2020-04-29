#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    enum{
        a,
        b,
        c
    };
    enum color_set1 {RED, BLUE, WHITE, BLACK} color1, color2;
    /* enum color_set2 { GREEN, RED, YELLOW, WHITE} color3, color4;,枚举值不能重复 */
    /* enum color_set2 { "WHITE"} color3, color4;,枚举值不能是字符或者数字类型 */
    enum color_set2 { GREEN, YELLOW } color3, color4;

    string x = "a";
    map<int,int> mp;
    cout<<a<<b<<x<<endl;
    color1 = RED;
    color2 = BLACK;
    /* color3 = color2; 枚举值不能相互赋值 */ 
    /* color3 = 1; 枚举值不能赋数字 */ 
    cout<<color1<<endl;
    cout<<color2<<endl;


    return 0;
}

