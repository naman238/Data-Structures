#include <bits/stdc++.h>
using namespace std;
struct bstnode {
    bstnode * lc;
    int data;
    bstnode* rc;
};
typedef bstnode* Bstptr;
void add(Bstptr &T,int x) {
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
vector<Bstptr> v;
void findrange(Bstptr T,int ll,int ul) {

    if(T==NULL)
        return ;
    cout<<ll<<" "<<ul<<" ";
    if(T->data<ll || T->data>ul) {
        v.push_back(T);
    }
    else {
        findrange(T->lc,ll,T->data-1);

        findrange(T->rc,T->data+1,ul);

    }
}
void swap(Bstptr &x,Bstptr &y) {
    int temp=x->data;
    x->data=y->data;
    y->data=temp;
}



int main() {
    Bstptr T;
    add(T,18);
    add(T->lc,9);
    add(T->rc,45);
    add(T->lc->lc,5);
    add(T->lc->rc,20);
    add(T->rc->lc,15);
    add(T->rc->rc,72);
    inorder(T);		//write inorder with three pointers solve
    cout<<endl;
    int min=0;
    int max=1000;
    findrange(T,min,max);
    cout<<endl;
    swap(v[0],v[1]);
    inorder(T); 
    return 0;
}
