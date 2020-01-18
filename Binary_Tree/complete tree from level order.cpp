#include<iostream>
using namespace std;
struct btnode{
	int data;
	btnode* lchild;
	btnode* rchild;
};
typedef btnode*btptr;
btptr create(int x)
{
	btptr t=new btnode;
	t->data=x;
	t->lchild=0;
	t->rchild=0;
}
void construct(btptr &t,int a[],int n,int i)
{
	if(i>=n) return;
	t=create(a[i]);
	construct(t->lchild,a,n,2*i+1);
	construct(t->rchild,a,n,2*i+2);
	i++;
}
void preorder(btptr t)
{
	if(t==0) return;
	cout<<t->data<<" ";
	preorder(t->lchild);
	preorder(t->rchild);
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	btptr t=0;int z=0;
	construct(t,a,n,0);
	preorder(t);
}
