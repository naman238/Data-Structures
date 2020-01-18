#include <bits/stdc++.h>
using namespace std;
struct btnode {
    btnode * lc;
    char data;
    btnode* rc;
};
typedef btnode* Btptr;
void insert(Btptr &T,int n) {
    int i=0;
    char ch;
    char x;
    queue <Btptr> q;
    while(i<n) {
        if(i==0) {
            cout<<"enter root: ";
            cin>>x;
            T=new struct btnode;
            T->data=x;
            T->lc=T->rc=NULL;
            cout<<endl;
            q.push(T);
            i++;
        }
        Btptr l=q.front();
        cout<<"Does it have a lc ";
        cin>>ch;
        if(ch=='y') {
            cin>>x;
            l->lc=new struct btnode;
            l->lc->data=x;
            l->lc->lc=l->lc->rc=NULL;
            q.push(l->lc);
            i++;
        }
        cout<<endl;
        cout<<"Does it have a rc ";
        cin>>ch;
        if(ch=='y') {
            cin>>x;
            l->rc=new struct btnode;
            l->rc->data=x;
            l->rc->lc=l->rc->rc=NULL;
            q.push(l->rc);
            i++;
        }
        q.pop();
    }
}
void inorder(Btptr T) {
    if(T!=NULL) {

        inorder(T->lc);
        cout<<T->data<<" ";
        inorder(T->rc);
    }
}
int main() {
    int n;
    cin>>n;
    Btptr T;
    insert(T,n);
    inorder(T);
    return 0;
}
