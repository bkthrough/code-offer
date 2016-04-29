#include <iostream>
using namespace std;
//二维数组查找，该二维数组从左向右数字增大，从上向下数字增大
//1 2 3  6  7
//2 4 9  10 12
//4 6 10 11 15

bool find(int array[3][3],int row,int col,int value)
{
    if(array == NULL || row < 0 || col < 0){
        return false;
    }
    for(int i = 0; i < row; ++i){
        for(int j = col - 1; j >= 0; --j){
            if(array[i][j] > value){
                j--;
            }else if(array[i][j] < value){
                i++;
            }else{
                return true;
            }
        }
    }

    return false;
}
int main()
{
    int array[3][3] = {1,2,3,2,5,9,4,10,12};

    if(!find(array,3,3,10)){
        cout<< "find it!!" <<endl;
    }else{
        cout<< "not find !!!" <<endl;
    }
    return 0;
}
