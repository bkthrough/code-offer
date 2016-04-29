#include <iostream>
using namespace std;

class binarynode
{
public:
    char data;
    binarynode *left;
    binarynode *right;
};
class binarytreenode
{
public:
    binarynode *rebuild(const char *pre_str,const char *mid_str,int len)
    {
        binarynode *root;
        int i = 0;
        int j = 0;

        if(NULL == pre_str || mid_str == NULL || len <= 0){
            return NULL;
        }
        root = new binarynode;
        root->data = *pre_str;
        while(mid_str[i] != root->data){
            i++;
        }
        root->left = rebuild(pre_str+1,mid_str,i);
        root->right = rebuild(pre_str+i+1, mid_str+i+1, len-i-1);

        return root;
    }
    void show(binarynode *root)
    {
        if(root == NULL){
            return ;
        }
        show(root->left);
        cout << root->data;
        show(root->right);
    }
};
int main()
{
    binarytreenode t;
    binarynode *root;

    root = t.rebuild("abcd","bacd",4);
    t.show(root);
    cout<<endl;

    return 0;
}
