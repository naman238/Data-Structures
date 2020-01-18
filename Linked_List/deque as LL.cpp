#include <iostream>
using namespace std;
struct dnode {
    int data;
    struct dnode* right;
    struct dnode* left;
};
typedef struct dnode * deque;
deque creatend(deque & t,int x) {
    deque temp=new struct dnode;
    temp->data=x;
    temp->right=NULL;
    temp->left=t;
    return temp;
}
deque createfront(deque &t,int x) {
    deque temp=new struct dnode;
    temp->data=x;
    temp->right=t;
    temp->left=NULL;
    return temp;
}
deque front=NULL;
deque rear=NULL;
void addend(deque &l,int x) {
    deque t=l;
    if(t==NULL) {
        l=new struct dnode;
        l->data=x;
        l->left=l->right=NULL;
        front=l;
        rear=l;
    }
    else {
        while(t->right!=NULL) {
            t=t->right;
        }
        t->right=creatend(t,x);
        rear=t->right;
    }
}
void addfornt(deque &l,int x) {
    deque t=l;
    if(t==NULL) {
        l=new struct dnode;
        l->data=x;
        l->left=l->right=NULL;
        front=l;
        rear=l;
    }
    else {
        t->left=createfront(t,x);
        front=t->left;
        l=front;
    }
}
void printlst(deque l) {
    if(l!=NULL) {
        cout<<l->data<<" ";
        printlst(l->right);
    }
}
void delfront(deque &l) {
    deque t=l;
    if(l->right==NULL) {
        l=NULL;
        rear=NULL;
        front=NULL;
        return;
    }
    else {
        l=l->right;
        front=l;
        delete t;
    }
}
void delend(deque &l) {
    deque t=l;
    if(l->right==NULL) {
        l=NULL;
        rear=NULL;
        front=NULL;
        return;
    }
    else {
        while(t->right!=NULL) {
            t=t->right;
        }
        rear=t->left;
        rear->right=NULL;
        delete t;
    }
}
int main() {
    deque l=NULL;
    addfornt(l,3);
    addfornt(l,4);
    addfornt(l,7);
    addend(l,9);
    addend(l,11);
    delfront(l);
    delend(l);
    printlst(l);
}
