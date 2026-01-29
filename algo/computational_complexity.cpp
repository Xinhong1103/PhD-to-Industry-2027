//
//  computational_complexity.swift
//
//
//  Created by Xinhong WU on 29.01.26.
//

#include <iostream>

/*
 LOOP
 
 */
// 1
int forLoop(int n){
    int sum = 0 ;
    for(int i=0; i<n;i++){
        std::cout<< i<<std::endl;
        sum +=i;
    }
    return sum;
}


//2
int whileLoop(int n){
    int sum = 0;
    int i = 0;
    while(i<n){
        sum +=i;
        i++;
    }
    std::cout<<sum<<std::endl;
    return sum;
}

//3

void nestedForLoop(int n){
    for(int i =1 ; i <n;i++){
        for(int j = 1; j <=i;j++){
            std::cout<<i<<" * "<<j<<" = "<<i*j<<"  ";
        }
        std::cout<<std::endl;
    }
}


int main() {
    int n = 5;
    int res;

    res = forLoop(n);


    res = whileLoop(n);


    nestedForLoop(n);


    return 0;
}

/*

 recursion
 
 */

//1
int recur(int n){
    // end condition
    if (n==1){
        return 1;
    }
    else{ // recursion
        n--;
        std::cout<<n<<std::endl;
        return recur(n);
    }
    /*
     n--;
     std::cout<<n<<std::endl;
     return recur(n);
     */
}
   
//2

int forLoopRecur(int n){
    std::stack<int> stack;
    int res = 0;
    for(int i = n;i>0;i--){
        stack.push(i);
    }
    while(!stack.empty()){// end condition
        res += stack.top();
        std::cout<<stack.top()<<std::endl;
        stack.pop();
    }
    return res;
}

//
int tailRecur(int n, int res){
    //end condition
    if(n == 0){
        return res;
    }
    return tailRecur(n-1,res+n);
}

int fib(int n){
    //end condition
    if (n==1||n==2){
        return n -1;
    }
    return fib(n-1)+fib(n-2);
}


int main() {
    int n = 5;
    int res;

    res = recur(n);
    std::cout << "\n递归函数的求和结果 res = " << res << std::endl;

    res = forLoopRecur(n);
    std::cout << "\n使用迭代模拟递归求和结果 res = " << res << std::endl;

    res = tailRecur(n, 0);
    std::cout << "\n尾递归函数的求和结果 res = " << res << std::endl;

    res = fib(n);
    std::cout << "\n斐波那契数列的第 " << n << " 项为 " << res << std::endl;

    return 0;
}

/*
 time complexity
 */
//1
int constant(int n){
    int count =0 ;
    int size = 10000;
    for(int i =0 ; i<size;i++){
        count++;
    }
    return count;
}

//2
int linear(int n){
    int count = 0;
    for(int i =0; i<n;i++){
        count++;
    }
    return count;
}

//3
int arrayTraversal(std::vector<int>& nums){
    int count =0;
    for(int num:nums){
        count++;
    }
    return count;
}

//4
int quadratic(int n){
    int count = 0;
    for (int i =0 ;i < n; i++){
        for(int j=0;j<n;j++){
            count++;
        }
    }
    return count;
}

//5 = quadratic
int bubbleSort(std::vector<int>& nums){
    int count = 0;
    for(int i = 0 ;i<nums.size();i++){
        for(int j =i;j<nums.size()-1;j++){
            if (nums[j]>nums[j+1]){
                int temp = nums[j];
                nums[j]=nums[j+1];
                nums[j+1] = temp;
                count+=3;
            }
            count++;
        }
    }
    return count;
}

int exponential(int n){
    int count = 0,base =1;
    for(int i =0;i<n;i++){
        for (int j = 0; j<base;j++){
            count++;
        }
        base *=2;
        
    }
    return count;
}


int logarithmic(int n){
    int count =0 ;
    while(n>1){
        n =n/2;
        count++;
    }
    return count;
}


int logRecur(int n){
    
    if(n<=1)
        return 1;
    
    
    return 1+ logRecur(n/2);
}


int linearLogRecur(int n){
    if(n<=1){
        return 1;
    }
    int count = linearLogRecur(n/2)+linearLogRecur(n/2);
    for (int i =0;i<n;i++){
        count++;
    }
    return count;
}

int factorialRecur(int n){
    if(n==0){
        return 1;
    }
    int count = 0;
    for(int i= 0;i<n;i++){
        count+= factorialRecur(n-1);
    }
    return count;
}
/* Driver Code */
int main() {
    // 可以修改 n 运行，体会一下各种复杂度的操作数量变化趋势
    int n = 8;
    cout << "输入数据大小 n = " << n << endl;

    int count = constant(n);
    cout << "常数阶的操作数量 = " << count << endl;

    count = linear(n);
    cout << "线性阶的操作数量 = " << count << endl;
    vector<int> arr(n);
    count = arrayTraversal(arr);
    cout << "线性阶（遍历数组）的操作数量 = " << count << endl;

    count = quadratic(n);
    cout << "平方阶的操作数量 = " << count << endl;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        nums[i] = n - i; // [n,n-1,...,2,1]
    count = bubbleSort(nums);
    cout << "平方阶（冒泡排序）的操作数量 = " << count << endl;

    count = exponential(n);
    cout << "指数阶（循环实现）的操作数量 = " << count << endl;
 
    count = logarithmic(n);
    cout << "对数阶（循环实现）的操作数量 = " << count << endl;
    count = logRecur(n);
    cout << "对数阶（递归实现）的操作数量 = " << count << endl;

    count = linearLogRecur(n);
    cout << "线性对数阶（递归实现）的操作数量 = " << count << endl;

    count = factorialRecur(n);
    cout << "阶乘阶（递归实现）的操作数量 = " << count << endl;

    return 0;
}

/*
 
 */
