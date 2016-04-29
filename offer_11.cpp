#include <iostream>
#include <stack>
using namespace std;

double unexponent(double,unsigned int);

double pow(double value,int exponent)
{
    double result = 0.0;

    if(exponent >= 0){
        result = unexponent(value,exponent);
    }else{
        exponent *= -1;
        result = unexponent(value,exponent);
        result = 1/result;
    }

    return result;
}
double unexponent(double value,unsigned int exponent)
{
    //非递归解法
    double result = 1.0;
    stack <double> s;
    double *res = new double[exponent];
    int count = 0;
    double flag = 0.0;
    //如果指数是奇数，那么就设置一个标记位
    for(int i = exponent; i > 0; i /= 2){
        if(i & 0x1 == 1)
            res[count] = 1.0;
        s.push(res[count++]);
    }
    while(!s.empty()){
        flag = s.top();
        s.pop();
        if(flag == 1.0){
            result *= result;
            result *= value;
        }else{
            result *= result;
        }
    }
    return result;
    //递归解法
    /*
    double result = 1.0;
    if(exponent == 0){
        return 1;
    }
    if(exponent == 1){
        return value;
    }
    result = unexponent(value,exponent>>1);
    result *= result;
    //如果指数是奇数，再乘一次
    if(exponent & 0x1 == 1)
        result *= value;

    return result;
    */
}
int main()
{
    double value;
    int exponent;

    cout << "input value :";
    cin >> value;
    cout << "input exponent :";
    cin >> exponent;
    cout << pow(value,exponent) << endl;

    return 0;
}
