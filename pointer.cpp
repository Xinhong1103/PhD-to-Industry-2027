//
//  pointer.cpp
//  
//
//  Created by Xinhong WU on 29.01.26.
//
#include <iostream>


void const_pointer(){
    // const define pointer or data
    int a =20;
    int b = 30;
    const int* p1 = &a;
    // const is close to int, so the int can't be change , but the pointer can be changed
    int* const p2 =&a;
    //const is close to pointer, so the address that the pointer pointed can't be changed, but the value can be changed
    p1 = & a;
    *p2 = 10;
    std::cout<< *p1<<std::endl;
    std::cout <<*p2<<std::endl;
    
}

void arr_pointer(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len_arr = sizeof(arr)/sizeof(int);
    
    for (int i =0 ;  i<len; i++){
        std::cout<<*(arr+i)<<std::endl;
    }
    
}

// address to pass

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
 void swap( int& a , int& b){}
 reference to pass, looks like the parameter is variable, but bottom of mechanism is pass value and address
 */

void pass_by_address(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len_arr = sizeof(arr)/sizeof(int);
    for (int i =0 ;  i<len_arr/2; i++){
        swap(&arr[i],&arr[len_arr-i-1]);
    }
    for (int j =0 ;  j<len_arr; j++){
        std::cout<<*(arr+j)<<std::endl;
    }
}


void bubble_sort(int *arr, int len_arr){
    for (int i =0 ;  i<len_arr; i++){
        for(int j = 0; j<len_arr-1;j++){
            if (*(arr+j)<*(arr+j+1)){
                swap(&arr[j],&arr[j+1]);
            }
        }
        
    }
    for (int j =0 ;  j<len_arr; j++){
        std::cout<<*(arr+j)<<std::endl;
    }
    
}


int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len_arr = sizeof(arr)/sizeof(int);
    bubble_sort(arr,len_arr);
    
    
    
    
    const_pointer();
    arr_pointer();
    pass_by_address()
    return 0;
}
