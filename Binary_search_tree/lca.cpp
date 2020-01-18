#include <iostream>
using namespace std;
struct bstnode {
    bstnode * lc;
    int data;
    bstnode* rc;
};
typedef bstnode* Bstptr;
void insert(Bstptr &T,int x) {
    if(T==NULL) {
        Bstptr l=new bstnode;
        l->data=x;
        l->lc=l->rc=NULL;
        T=l;
    }
    else {
        if(T->data<x) {
            insert(T->rc,x);
        }
        else {
            insert(T->lc,x);
        }
    }
}
int lca(Bstptr &T,int k1,int k2) {
    if(T->data<k1 && T->data<k2) {
        return lca(T->rc,k1,k2);
    }
    else if(T->data>k1 && T->data>k2) {
        return lca(T->lc,k1,k2);
    }
    else {
        return T->data;
    }
}

int main() {
    int n;
    cin>>n;
    Bstptr T=NULL;
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        insert(T,x);
    }
    int k1,k2;
    cout<<"enter nodes whose lca u want to find: ";
    cin>>k1>>k2;
    cout<<endl;
    int y=lca(T,k1,k2);
    cout<<"lca: "<<y<<endl;

    return 0;
}
