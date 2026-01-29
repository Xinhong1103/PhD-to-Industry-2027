//
//  class.cpp
//  
//
//  Created by Xinhong WU on 29.01.26.
//

#include<iostream>
#define PI 3.14
class Circle{
protected:
    int x;

private:
    int y;

    
    
public:
    int m_r;
    
    double calcu_zc(){
        return 2*PI*m_r;
    }
    void func(){
        x = 10;
        std::cout<<x<<std::endl;
    }
};




int main(){
    
    Circle c1;
    c1.m_r = 10;
    double zc = c1.calcu_zc();
    c1.x = 10;
    c1.func();
   
    std::cout<<zc<<std::endl;
}
