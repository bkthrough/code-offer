#include <iostream>
#include <string>
using namespace std;

extern "C"
{
#include <string.h>
}
void replaceblank(char *str,int len)
{
    int blank = 0;
    int i = 0;
    int new_len = len;

    if(str == NULL || len < 0){
        return ;
    }
    while(str[i] != '\0'){
        if(str[i] == ' '){
            blank++;
        }
        i++;
    }
    new_len += blank * 2;
    i--;
    new_len--;
    while(new_len >= 0){
        if(str[i] != ' '){
            str[new_len--] = str[i--];
        }else{
            str[new_len--] = '0';
            str[new_len--] = '2';
            str[new_len--] = '%';
            i--;
        }
    }
}
int main()
{
    char *str = new char[100];

    strcpy(str,"  i'm super man haha sb ");
    replaceblank(str,strlen(str));
    cout<< str <<endl;

    return 0;
}
