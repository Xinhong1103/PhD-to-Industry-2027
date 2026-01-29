//
//  constructor.cpp
//
//
//  Created by Xinhong WU on 29.01.26.
//
#include<iostream>

class Person {
    
public:
    int age;
    Person(){
        age = 18;
    };
    Person(int x){
        age = x;
    };
    
    Person(const Person& p){
        age = p.age;
    };
    ~Person(){
        std::cout <<" clear person"<<std::endl;
    }
};

int main(){
    
    class Person p ;
    std::cout<<p.age<<std::endl;
    class Person p1 = Person(p);
    std::cout<<p1.age<<std::endl;
}

