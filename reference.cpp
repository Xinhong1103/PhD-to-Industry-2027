//
//  reference.cpp
//  
//
//  Created by Xinhong WU on 29.01.26.
//

#include<iostream>

/*
 
 datatype& alias = original_name;
 
 int& b = a;
 
 
 1.must initial when define a reference
 2. after initialate,reference can't be change, but the value can be change
    int &b =a;
    &b =c; (wrong)
    b = c; (right)
 
 reference essence is a pointer constant
 int& ref = a  equals to   int* const ref = &a
 */

void swap_pointer(int* a ,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_reference(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int i = 10;
    int j = 20;
    swap_pointer(&i,&j);
    std::cout<<"i = "<<i<<"    j = "<<j<<std::endl;
    
    swap_reference(i,j);
    std::cout<<"i = "<<i<<"    j = "<<j<<std::endl;
    
    const int& ref = i;
    i=20
    
}
