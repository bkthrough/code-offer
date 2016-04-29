#include <iostream>
using namespace std;

//求二进制中1的个数
int numofown(int n)
{
    int count = 0;

    while(n){
        n &= n-1;
        count++;
    }

    return count;
}
int main()
{
    int n = 0;

    cin >> n;
    cout << numofown(n) << endl;

    return 0;
}
