#include <iostream>
using namespace std;

//定义类
class base
{
public:
    base(int a):data(a)
    {
    }
    base(const base &b)
    {
        data = b.data;
    }
    ~base()
    {
    }
public:
    //防止出现异常导致b不可逆转
    base &operator=(const base &b)
    {
        if(&b != this){
            base temp(b);

            int str = temp.data;
            temp.data = data;
            data = str;
        }
        return *this;
    }
    int operator+(const base &b)
    {
        return (base)b.data + data;
    }
//必须声明为友元类型，返回值并不是类的成员，所以不能是成员函数
    friend ostream &operator<<(ostream &out,const base &b)
    {
        out << b.data;

        return out;
    }
private:
    int data;
};
int main()
{
    base b(100);

    cout<<b<<endl;

    return 0;
}
