//
//  complex.cpp
//  
//
//  Created by Xinhong WU on 01.02.26.
//

//houjie

#ifndef __complex__
//#define __complex__
class Complex(){
public:
    complex(double r = 0,double i = 0): re(r),im(i)
    {}
    complex& operator += (const complex &);
    deuble real() {return re;}
    double imag() {return im;}
private:
    double re,im;
}

int main(){
    complex c1(4,5);
    std::cout<<c1.real();
}







#endif
