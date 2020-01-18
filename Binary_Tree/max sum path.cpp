#include<iostream>
typedef
struct bstnode
{
    struct bstnode* lchild;
    int data;
    struct bstnode* rchild;
} *BSTPTR;
using namespace std;
BSTPTR create(int x)
{
    BSTPTR temp=new struct bstnode;
    temp->data=x;
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}
void insert(BSTPTR &t,int k)
{
    BSTPTR temp;
    if(t==NULL)
    {
        temp=create(k);
        t=temp;
        return;
    }
    else {
        if(t->data>k)
        {
            insert(t->lchild,k);
        }
        else insert(t->rchild,k);
    }
}
void print(int a[],int size)
{
    for(int j=0; j<size; j++)
        cout<<a[j]<<" ";
    cout<<endl;
}
int m=0;
int lnode;
void sub(BSTPTR t,int a[],int i,int &s)
{
    if(t==NULL)
    {
        return;
    }
    else if(t->lchild==NULL && t->rchild==NULL) {
        s+=t->data;
        if(s>m)
        {
            lnode=t->data;
            m=s;
        }
        return;
    }
    s+=t->data;
    sub(t->lchild,a,i,s);
    sub(t->rchild,a,i,s);
}
void printmaxpath(BSTPTR t,int a[],int i) {
    if(t==NULL)
        return ;
    else if(t->data==lnode) {
        a[i++]=t->data;
        print(a,i);
    }
    a[i++]=t->data;
    printmaxpath(t->lchild,a,i);
    printmaxpath(t->rchild,a,i);
}
int main()
{
    BSTPTR b=NULL;
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
        insert(b,a[i]);
    }
    int ar[n];
    int p=0;
    sub(b,ar,0,p);
    printmaxpath(b,ar,0);
    return 0;
}
