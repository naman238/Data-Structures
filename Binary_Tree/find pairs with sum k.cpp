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
        if(T->data<x) 
		{
            insert(T->rc,x);
        }
        else 
		{
            insert(T->lc,x);
        }
    }
}
void inorder(Bstptr T,stack<Bstptr> &s) {
    if(T!=NULL) {
        inorder(T->lc,s);
        s.push(T);
        inorder(T->rc,s);
    }
}
void revinorder(Bstptr T,stack<Bstptr> &s) {
    if(T!=NULL) {
        revinorder(T->rc,s);
        s.push(T);
        revinorder(T->lc,s);
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
    int m;
    cin>>m;
    Bstptr L=NULL;
    for(int i=0; i<m; i++) {
        cin>>x;
        insert(L,x);
    }
    stack<Bstptr>s1,s2;
    inorder(T,s1);
    revinorder(L,s2);
    int k;
    cin>>k;
    while(!s1.empty() && !s2.empty())
    {
        if(s1.top()->data+s2.top()->data>k) {
            s1.pop();
        }
        else if(s1.top()->data+s2.top()->data<k) {
            s2.pop();
        }
        else {
            cout<<s1.top()->data<<" "<<s2.top()->data<<endl;
            s1.pop();
            s2.pop();
        }
    } 
    return 0;
}
