#include <iostream>
#include <stdexcept>
using namespace std;

//对于旋转数组找到最小值
//如3,4,5,1,2
int find_pos(int array[],int len)
{
    int mid = 0;
    int left = 0;
    int right = len - 1;
    int min = 0;

    if(NULL == array || len <= 0){
        logic_error("invalid arg");
    }
    while(array[left] >= array[right]){
        if(right - left == 1){
            mid = right;
            break;
        }
        mid = left + (right - left) / 2;
        //为了防止有一种情况
        //1,1,0,1,1,1,1,1
        if(array[mid] == array[left] && array[mid] == array[right]){
            min = left;
            for(int i = left; i < right-1; ++i){
                if(array[i] > array[i+1]){
                    min = i + 1;
                    return min;
                }
            }
        }
        //找前面数组的最后一个元素
        if(array[mid] >= array[left]){
            left = mid + 1;
            //找后面数组的第一个元素
        }else if(array[mid] <= array[right]){
            right = mid - 1;
        }
    }
    return mid;
}
int main()
{
    //int array[5] = {2,3,4,5,1};
    int array[7] = {1,1,1,1,1,0,1};

    cout << find_pos(array,7) << endl;

    return 0;
}
