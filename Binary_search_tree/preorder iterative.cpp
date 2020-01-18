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
int main() {
    int n;
    cin>>n;
    Bstptr T=NULL;
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        insert(T,x);
    }
    cout<<"preorder: ";
    stack<Bstptr> s;
    s.push(T);
    while(!s.empty()) {
        Bstptr l=s.top();
        s.pop();
        while(l!=NULL) {
            cout<<l->data<<" ";
            if(l->rc!=NULL) {
                s.push(l->rc);
            }
            l=l->lc;
        }

    }
    return 0;
}
