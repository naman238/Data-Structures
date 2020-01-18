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
void inorder(Bstptr T) {
    if(T!=NULL) {
        inorder(T->lc);
        cout<<T->data<<" ";
        inorder(T->rc);
    }
}

bool isbst(Bstptr T,int max,int min) {
    if(T==NULL)
        return true;
    else if(T->data>min && T->data<max && isbst(T->lc,T->data,min) && isbst(T->rc,max,T->data)) {
        return true;
    }
    else {
        return false;
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
    cout<<"inorder: ";
    inorder(T);
    cout<<endl;
    int m=INT_MAX;
    int p=INT_MIN;
    cout<<isbst(T,m,p);
    return 0;
}
