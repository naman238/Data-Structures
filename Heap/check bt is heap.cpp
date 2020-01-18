#include<iostream>
using namespace std;
typedef
struct btnode {
    btnode *lchild;
    btnode *rchild;
    int data;
    int x;
}*btptr;
btptr newnode(int z)
{
    btptr t=new struct btnode;
    t->data=z;
    t->lchild=t->rchild=NULL;
}
int retind(int a[],int x,int n)
{
    int j;
    for(j=0; j<n; j++)
    {
        if(a[j]==x) break;
    }
    return j;
}
int count=0;
void create(btptr &t,int pre[],int in[],int n,int low,int high)
{
    if(low>=high || count==n) return;
    int x=retind(in,pre[count++],n);
    t=newnode(in[x]);
    create(t->lchild,pre,in,n,low,x);
    create(t->rchild,pre,in,n,x+1,high);
}
bool isheap(btptr t,int n,int i)
{
    if(t==0 || n==1) return true;
    if(i>=n) return false;
    if(t->lchild!=0 && t->rchild!=0) {
        if((t->data>(t->lchild->data) || t->data>t->rchild->data) || !isheap(t->lchild,n,2*i+1) || !isheap(t->rchild,n,2*i+2))
            return false;
        else return true;
    }
    else if(t->lchild!=0 && t->rchild==0) {
        if(t->data>(t->lchild->data)|| !isheap(t->lchild,n,2*i+1) || !isheap(t->rchild,n,2*i+2))
            return false;
        else return true;
    }
    else if(t->lchild==0 && t->rchild!=0)
		 return false;
}
int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<n; i++)cin>>b[i];
    btptr t;
    create(t,a,b,n,0,n);
    if(isheap(t,n,0)) cout<<"yes";
    else cout<<"no";
    return 0;
}
