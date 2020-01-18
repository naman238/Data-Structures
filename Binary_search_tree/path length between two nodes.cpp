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
int flag=0;
int counter=0;
int pl(Bstptr T,int k1,int k2) {

    if(flag==0) {

        if(T->data>k1 && T->data>k2) {
            pl(T->lc,k1,k2);
        }
        else if(T->data<k1 && T->data<k2) {
            pl(T->rc,k1,k2);
        }
        else if(T->data==k1) {

            flag=1;
            pl(T,k1,k2);
        }
    }
    else {
        counter++;
        if(T->data>k2) {
            pl(T->lc,k1,k2);
        }
        else if(T->data<k2) {
            pl(T->rc,k1,k2);
        }
        else {
            return counter;
        }
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
    cout<<"enter nodes whose path length u want to find: ";
    cin>>k1>>k2;
    cout<<endl;
    int y=lca(T,k1,k2);
    int l1=pl(T,T->data,k1);
    counter=0;
    int l2=pl(T,T->data,k2);
    counter=0;
    int l3=pl(T,T->data,y);
    cout<<l1+l2-2*l3<<endl;

    return 0;
}
