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
int countleaf(Btptr T) {
    if(T!=NULL) {
        if(T->rc==NULL && T->lc==NULL) {
            return 1;
        }
        else {
            return countleaf(T->lc)+countleaf(T->rc);
        }
    }
}
int countnodes(Btptr T) {
    if(T!=NULL) {
        return countnodes(T->lc)+countnodes(T->rc)+1;
    }
}
int main() {
    int x;
    string s;
    cin>>s;
    int i=0;
    Btptr T;
    int k=s.length();
    T=insert(T,s,k,i);
    int y=countleaf(T);
    cout<<y<<endl;
    int z=countnodes(T);
    cout<<z<<endl;
    return 0;
}
