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
void reverse(DPTR &l,DPTR t) {
    if(t->right==NULL) {
        l=t;
        return;
    }
    else {
        reverse(l,t->right);
        t->right->left=t->right->right;
        t->right->right=t;
        if(t->left==NULL)
        {	t->left=t->right;
			t->right=NULL;
		}
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
    reverse(l,l);
    printlst(l);
}
