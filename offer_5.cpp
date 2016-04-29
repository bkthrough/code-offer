#include <iostream>
#include <list>
using namespace std;

list <int> l;
int main()
{
    list <int>::iterator j;
    for(int i = 0; i < 10; ++i){
        l.push_front(i);
    }
    for(j = l.end(); j != l.begin(); --j){
        cout << *j << endl;
    }
    return 0;
}
