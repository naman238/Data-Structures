#include <iostream>
using namespace std;
struct dnode {
    int data;
    struct dnode* right;
    struct dnode* left;
};
typedef struct dnode * DPTR;
DPTR create(DPTR & t,int x) {
    DPTR temp=new struct dnode;
    temp->data=x;
    temp->right=NULL;
    temp->left=t;
    return temp;
}
void add(DPTR &l,int x) {
    DPTR t=l;
    if(t==NULL) {
        l=new struct dnode;
        l->data=x;
        l->left=l->right=NULL;
    }
    else {
        while(t->right!=NULL) {
            t=t->right;
        }
        t->right=create(t,x);
    }
}
DPTR reverse(DPTR l,int k,int p,DPTR &z) {
    DPTR curr=l;
    DPTR next=NULL;
    DPTR prev=NULL;
    int count=0;
    while(curr!=NULL && count<k) {
        next=curr->right;
        curr->right=prev;
        curr->left=next;
        p++;
        if(p==k-1) {
        	next->left=l;
            z=next;
        }
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL) {

        l->right=reverse(next,k,p,z);
    }

    return prev;




}
void printlst(DPTR l) {
    if(l!=NULL) {
        cout<<l->data<<" ";
        printlst(l->right);
    }
}
int main() {
    DPTR l=NULL;
    add(l,3);
    add(l,4);
    add(l,7);
    add(l,9);
    add(l,11);
    int k;
    cin>>k;
    reverse(l,k,0,l);
    printlst(l);
}
