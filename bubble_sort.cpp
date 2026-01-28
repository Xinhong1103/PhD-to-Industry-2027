#include <iostream>
using namespace std;

void swap_arg(int& a,int& b){
    int temp = a;
    a =b;
    b =temp;
}

int main(){
    int arr[] = {1,4,52,43,5,44,34,53,64,6};
    int len = sizeof(arr)/sizeof(int);
    for(int i =0 ; i<len;i++){
        
        for(int j =0;j<len-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap_arg(arr[j],arr[j+1]);
            }
        }
    }
    for(int k =0 ; k<len;k++){
        std:cout<<*(arr+k)<<std::endl;
    }
    
}
