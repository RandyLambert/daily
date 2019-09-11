#include <iostream>
#include <string>

class Animal
{
public:
    std::string mouth;
    
    void eat();
    void sleep();
    void drool();
};

class Pig : public Animal
{
public:
    void climb();
};

class Turtle : public Animal
{
public:
    void swim();
};

void Animal::eat()
{
    std::cout<< "eating??"<<std::endl;
}

void Animal::sleep()
{
    std::cout<<"im sleep"<<std::endl;
}

void Animal::drool()
{
    std::cout<<"fuck i have water"<<std::endl;
}

void Pig::climb()
{
    std::cout<<"i am a beautiful pig"<<std::endl;
}

void Turtle::swim()
{
    std::cout<<"i am a xiaojiayu"<<std::endl;
}
int main(){

    Turtle turtle;
    turtle.drool();
    turtle.eat();
    turtle.swim();

    Pig pig;
    pig.climb();

    return 0;
}

