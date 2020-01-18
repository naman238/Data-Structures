#include <iostream>
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
        else 
			insert(t->rchild,k);
    }
}
void print(int a[],int size)
{
    for(int j=0; j<size; j++)
        cout<<a[j]<<" ";
    cout<<endl;
}

void sub(BSTPTR t,int a[],int i)
{
    if(t==NULL)
    {
        return;
    }
    else if(t->lchild==NULL && t->rchild==NULL) {
        a[i++]=t->data;
        print(a,i);
        return;
    }
    a[i++]=t->data;
    sub(t->lchild,a,i);
    sub(t->rchild,a,i);
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
    sub(b,ar,0);
    return 0;
}
