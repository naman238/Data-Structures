#include <iostream>
using namespace std;
struct btnode {
    btnode * lc;
    char data;
    btnode* rc;
};
typedef btnode* Btptr;
//Btptr T=NULL;

Btptr insert(Btptr &T,string s,int k,int &i) {
    if(i==k-1 || s[i]=='.') {
        return NULL;
    }
    else {
        T=new struct btnode;
        T->data=s[i];
        T->lc=insert(T->lc,s,k,++i);
        T->rc=insert(T->rc,s,k,++i);
        return T;
    }
}
int m=0;
void leftview(Btptr T,int level) {
    if(T==NULL) {
        return ;
    }
    else if(level>m) {
        cout<<T->data<<" ";
        m=level;
    }
    leftview(T->lc,level+1);
    leftview(T->rc,level+1);
}
void rightview(Btptr T,int level) {
    if(T==NULL) {
        return ;
    }
    else if(level>m) {
        cout<<T->data<<" ";
        m=level;
    }
    rightview(T->rc,level+1);
    rightview(T->lc,level+1);
}
int main() {
    int x;
    string s;
    cin>>s;
    int i=0;
    Btptr T;
    int k=s.length();
    T=insert(T,s,k,i);
    leftview(T,1);
    m=0;
    cout<<endl;
    rightview(T,1);
    return 0;
}
