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
int findmin(Bstptr T) {
    if(T==NULL) {
        return -1;
    }
    else if(T->lc==NULL) {
        return T->data;
    }
    else {
        return findmin(T->lc);
    }
}
int findmax(Bstptr T) {
    if(T==NULL)
        return -1;
    else if(T->rc==NULL)
        return T->data;
    else
        return findmax(T->rc);
}
void findrange(Bstptr T,int ll,int ul) 
{
    if(T==NULL)
        return ;
    if(ll==ul) {
        cout<<T->data<<" ";
    }
    else {
        findrange(T->lc,ll,T->data-1);

        findrange(T->rc,T->data+1,ul);

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
    int min=0;
    int max=1000;
    findrange(T,min,max);
    return 0;
}
