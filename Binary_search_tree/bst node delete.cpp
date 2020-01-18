#include<iostream>
using namespace std;

typedef
struct bstnode
{
	struct bstnode* lchild;
	int data;
	struct bstnode* rchild;
} *BSTPTR;
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
	else{
		if(t->data>k)
		{
			insert(t->lchild,k);
		}
		else insert(t->rchild,k);
	}
}
BSTPTR use;
BSTPTR search(BSTPTR b,int x)
{
	if(b->data==x){
		return b;
	}
	else if(b->data>x){
		use =b;
		b=search(b->lchild,x);
	}
	else if(b->data<x){
		use=b;
		b=search(b->rchild,x);
	}
}
void preorder(BSTPTR t)
{
	if(t==NULL) return;
	cout<<t->data<<" ";
	preorder(t->lchild);
	preorder(t->rchild);
}
int min(BSTPTR t)
{
	if(t->lchild==NULL)
	{
		return t->data;
	}
	return min(t->lchild);
}
int max(BSTPTR t)
{
	if(t->rchild==NULL)
	{
		return t->data;
	}
	return max(t->rchild);
}
void del(BSTPTR &bt,int k)
{
	BSTPTR t=search(bt,k);
	if(t->lchild==0 && t->rchild==0)
	{
		if(use->lchild->data==t->data)
		use->lchild=0;
		else
			use->rchild=0;
		delete t;
		return;
	}
	else if(t->lchild==0 && t->rchild!=0)
	{
		if(use->lchild->data==t->data)
		use->lchild=t->rchild;
		else
			use->rchild=t->rchild;
		delete t;
	}
	else if(t->lchild!=0 && t->rchild==0)
	{
		if(use->lchild->data==t->data)
		{
		use->lchild=t->lchild;}
		else{
			use->rchild=t->lchild;
		}
		delete t;
	}
	else{
		int x=min(t->rchild);
		del(t,x);
		t->data=x;
	}
}
int main()
{
	BSTPTR b=NULL;
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		insert(b,a[i]);
	}
	cout<<"Enter key to delete";int y;cin>>y;
	del(b,y);
	preorder(b);
	return 0;
}
