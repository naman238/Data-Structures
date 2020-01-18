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
void mergsort(DPTR &l,DPTR &l2) {
    DPTR p=l;
    DPTR t=l2;
    while(p->right!=NULL && t->right!=NULL) {
        if(p->data<=t->data) {
            p=p->right;
        }
        else {
            p->left->right=t;
            t->left=p->left;
            while(t->data<p->data&& t->right!=NULL) {
                t=t->right;
            }
            t->left->right=p;
            p->left=t->left;
        }
    }
    if(t->right==NULL) {
        p=p->right;
        p->left->right=t;
        t->left=p->left;
        p->left=t;
        t->right=p;
    }
    else {
        t=t->right;
        t->left->right=p;
        p->left=t->left;
        t->left=p;
        p->right=t;
    }
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
    DPTR l1=NULL;
    add(l1,5);
    add(l1,6);
    add(l1,8);
    add(l1,10);
    mergsort(l,l1);
    printlst(l);
    return 0;
}
