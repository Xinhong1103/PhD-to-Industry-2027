//
//  multi.cpp
//
//
//  Created by Xinhong WU on 29.01.26.
//
#include <iostream>
class Animal {
    public:
    
    virtual void speak(){
        std::cout<< "animal speak"<<std::endl;
    };
};

class Cat: public Animal{
    public:
    void speak(){
        std::cout<<" cat speak "<<std::endl;
    };
};

class Dog: public Animal{
public:
    virtual void speak(){
        std::cout<<"Dog speak"<<std::endl;
    };
};

void dospeak(Animal& animal){
    animal.speak();
};

int main(){
    Cat cat;
    cat.speak();
    dospeak(cat);
    
    Dog dog;
    dog.speak();
    dospeak(dog);
    
    
}

