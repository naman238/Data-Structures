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
void preorder(BSTPTR t,int a[],int &i)
{
	if(t==NULL) return;
	t->data=a[i++];
	preorder(t->lchild,a,i);
	preorder(t->rchild,a,i);
}
void inorder(BSTPTR t,int a[],int &i)
{
	if(t==NULL) return;
	inorder(t->lchild,a,i);
	a[i++]=t->data;
	inorder(t->rchild,a,i);
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
	int c[n];
	int i=0;
	inorder(b,c,i);
	i=0;
	preorder(b,c,i);
	return 0;
}
