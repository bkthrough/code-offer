#include <iostream>
using namespace std;

long fibonacci(unsigned int n)
{
    if(n == 0){
        return 0;
    }
    if(n == 1 || n == 2){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n - 2);
}
long fibonacci2(unsigned int n)
{
    int first = 1;
    int second = 1;
    int result = 0;

    result = first;
    if(n == 0){
        return 0;
    }else if(n == 1 || n == 2){
        return result;
    }
    while(n >= 2){
        result += first;
        first   = second;
        second  = result;
        n--;
    }
    return result;
}
int main()
{
    cout << fibonacci2(3) << endl;
    return 0;
}
