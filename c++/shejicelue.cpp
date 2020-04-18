#include <iostream>
using namespace std;
//抽象武器 武器策略
class WeaponStrategy
{
public:
    virtual void useWeapon() = 0;
};

class knife : public WeaponStrategy
{
public:
    virtual void useWeapon()
    {
        cout << "knife" << endl;
    }
};

class ak : public WeaponStrategy
{
public:
    virtual void useWeapon()
    {
        cout << "ak" << endl;
    }
};

class character
{
public:
    void setWeapon(WeaponStrategy *weapon)
    {
        this->pWeapon = weapon;
    }

    void ThrowWeapon()
    {
        pWeapon->useWeapon();
    }

private:
    WeaponStrategy *pWeapon;
};

void test01()
{
    //创建角色
    character *acter = new character;

    //武器策略
    WeaponStrategy *knif = new knife;
    WeaponStrategy *ak47 = new ak;

    acter->setWeapon(knif);
    acter->setWeapon(ak47);
}
int main()
{

    return 0;
}