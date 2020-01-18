#include <bits/stdc++.h>
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
int x=0;
int findheight(Bstptr T) {
    if(T==NULL)
        return 0;
    else {
        int a=findheight(T->lc);
        int b=findheight(T->rc);
        return a>b?a+1:b+1;
    }
}
void printrl(Bstptr T,int level) {
    if(T==NULL)
        return;
    else if(level==1)
        cout<<T->data<<" ";
    else if(level>1) {
        printrl(T->rc,level-1);
        printrl(T->lc,level-1);
    }
}
void printlr(Bstptr T,int level) {
    if(T==NULL)
        return;
    else if(level==1)
        cout<<T->data<<" ";
    else if(level>1) {
        printlr(T->lc,level-1);
        printlr(T->rc,level-1);
    }
}
void zigzag(Bstptr T,int flag) {
    if(T==NULL)
        return;
    int h=findheight(T);
    for(int i=h; i>=1; i--) {
        if(flag==0) {
            printlr(T,i);
            flag=1;
        }
        else if(flag==1) {
            printrl(T,i);
            flag=0;
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
    cout<<"inorder: ";
    inorder(T);
    cout<<endl;
    int flag=0;
    zigzag(T,flag);
    return 0;
}
