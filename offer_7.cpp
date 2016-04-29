#include <iostream>
#include <stack>
using namespace std;

template <typename T> class CQueue
{
public:
    void push(const T &node)
    {
        stack1.push(node);
    }
    T pop()
    {
        T t;

        if(0 == stack2.size()){
            while(0 != stack1.size()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        t = stack2.top();
        stack2.pop();
        return t;
    }
private:
    stack <T> stack1;
    stack <T> stack2;
};
int main()
{
    CQueue<int> q;

    q.push(3);
    q.push(4);
    cout << q.pop() << endl;
    q.push(5);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    return 0;
}
