#include<iostream>
int main()
{
    int scores[3][3] = {{100,100,100}, {90,50,100}, {60,70,80}};
    
    for(int i = 0; i < 3; i++){
        int sum = 0;
        cout << "第" << i+1 << "个人的成绩: ";
        
        for(int j = 0; j < 3; j++){
            cout << *(*(scores+i)+j) << " ";  // scores[i][j]
            sum += *(*(scores+i)+j);
        }
        
        cout << " 总分: " << sum << endl;
    }
}
