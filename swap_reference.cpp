#include <iostream>
using namespace std;

void swap_arg(int& a,int& b){
    int temp = a;
    a = b;
    b =temp;
    
}
void swap_arr(int* arr, int len){
    int* start = arr;
    int* end = arr+len-1;
    
    
    while(start<end){
        swap_arg(*start,*end);
        start++;
        end--;
    }
}


int main()

{
    
    int arr[] = {1,2,3,4,5,2,4,43,5,54,6,56,5,6,5,6,5};
    
    int  len = sizeof(arr)/sizeof(int);
    swap_arr(arr,len);
    for(int j=0;j<len;j++){
        
        std::cout<<arr[j]<<std::endl;
        
    }
}
