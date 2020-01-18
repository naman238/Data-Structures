#include <bits/stdc++.h>
using namespace std;
struct bstnode {
    bstnode * lc;
    int data;
    bstnode* rc;
};
typedef bstnode* Bstptr;
Bstptr create(int x) {
    Bstptr l=new bstnode;
    l->data=x;
    l->lc=l->rc=NULL;
    return l;
}
void inorder(Bstptr T) {
    if(T!=NULL) {

        inorder(T->lc);
        cout<<T->data<<" ";
        inorder(T->rc);
    }
}
int i;

Bstptr pre_recur(int a[],int l,int h) {


    if(l>h) {
        return NULL;
    }
    Bstptr T=create(a[l]);
//1 cout<<T->data<<" ";
    i=l;
    i++;

    while(i<=h && T->data>a[i] ) {
        i++;
    }

    T->lc=pre_recur(a,l+1,i-1);
    T->rc=pre_recur(a,i,h);
//cout<<i<<" ";
    return T;
}
int main() {
    int n;
    cin>>n;
    int a[n];

    int y;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    int l=0;
    int h=n-1;
    Bstptr T=pre_recur(a,l,h);
    inorder(T);
    cout<<endl;
    return 0;
}
