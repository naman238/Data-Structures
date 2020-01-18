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
void levelorder(queue <Bstptr> q) {
    while(q.size()!=1) {
        Bstptr T=q.front();
        if(T->data==-1) {
            cout<<endl;
            q.pop();
            q.push(T);
            continue;
        }
        if(T->lc!=NULL) {
            q.push(T->lc);
        }
        if(T->rc!=NULL) {
            q.push(T->rc);
        }
        cout<<T->data<<" ";
        q.pop();
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
    queue <Bstptr> q;
    q.push(T);
    Bstptr r=new bstnode;
    r->data=-1;
    r->rc=r->lc=NULL;
    q.push(r);
    levelorder(q);
    return 0;
}
