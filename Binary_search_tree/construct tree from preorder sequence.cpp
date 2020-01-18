#include <bits/stdc++.h>
using namespace std;
struct bstnode {
    bstnode * lc;
    int data;
    bstnode* rc;
};
typedef bstnode* Bstptr;
void create(Bstptr &T,int x) {
    Bstptr l=new bstnode;
    l->data=x;
    l->lc=l->rc=NULL;
    T=l;
}
void inorder(Bstptr T) {
    if(T!=NULL) {
        inorder(T->lc);
        cout<<T->data<<" ";
        inorder(T->rc);
    }
}
int main() {
    int n;
    cin>>n;
    int a[n];
    Bstptr T=NULL;
    int y;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    int i=0;
    stack<Bstptr> s;
    while(i<n) {
        if(i==0) {
            create(T,a[i]);
            s.push(T);
        }
        else if(s.top()->data>a[i]) {
            create(s.top()->lc,a[i]);
            s.push(s.top()->lc);
        }
        else {
            Bstptr l;
            while(s.size()!=0 && s.top()->data<a[i]) {
                l=s.top();
                s.pop();
            }
            create(l->rc,a[i]);
            s.push(l->rc);
        }
        i++;
    }
    inorder(T);
    cout<<endl;
    return 0;
}
