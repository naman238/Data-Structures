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
void preorder(Bstptr T) {
    if(T!=NULL) {
        cout<<T->data<<" ";
        preorder(T->lc);

        preorder(T->rc);
    }
}
void postorder(Bstptr T) {
    if(T!=NULL) {
        postorder(T->lc);

        postorder(T->rc);
        cout<<T->data<<" ";
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

void greatersumtree(Bstptr &T ) {
    static int sum=0;
    if(T!=NULL) {
        greatersumtree(T->rc);
        	int x=T->data;
            T->data=sum;
            sum+=x;
        greatersumtree(T->lc);
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
    cout<<"postorder: ";
    postorder(T);
    cout<<endl;
    cout<<"preorder: ";
    preorder(T);
    cout<<endl;
    int y=findmax(T);
    int z=findmin(T);
    cout<<y<<" "<<z;
    cout<<endl;
    greatersumtree(T);
//cout<<"hi";
    inorder(T);

    return 0;
}
