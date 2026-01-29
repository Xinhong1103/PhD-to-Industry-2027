//
//  whole.cpp
//  
//
//  Created by Xinhong WU on 05.02.26.
//
#ifndef _COMPLEX_
#define _COMPLEX_
#include <iostream>
using namespace std

class complex
{
public:
    complex( double r = 0,double i = 0)
    : re(r),im(i)// inline define
    {}
    complex& operator += (const complex&);
    double real() const {return re;}
    double imag() const {return im;}
    
private:
    double re;
    double im;
    
    friend complex& __doapl(complex*, const complex&);
}

int main(){
    complex c1(2,1);
    c1.real();
    std::cout<< c1.real()<<std::endl;
}







#endif

