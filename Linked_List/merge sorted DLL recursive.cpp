#include<iostream>
using namespace std;
struct dlnode
{
	int data;
	struct dlnode* right;
	struct dlnode* left;
};
typedef struct dlnode* DPTR;
struct dlnode* create(int x)
{
	DPTR t;
	t=new(struct dlnode);
	t->data=x;
	t->right=NULL;
	t->left=NULL;
	return t;
}
void addend(DPTR &l,int x)
{
	DPTR t;
	if(l==NULL)
	{
		l=create(x);
	}
	else
	{
		DPTR temp=l;
		while(temp->right!=NULL)
		temp=temp->right;
		DPTR t1=NULL;
		t1=create(x);
		temp->right=t1;
		t1->left=temp;
	}
}
DPTR head=NULL;
void addbef(DPTR &l,int x,int y)
{
	if(l->data==x )
	{
		DPTR t1=create(y);
		t1->right=l;
		t1->left=NULL;
		l=t1;
		return;
	}
	DPTR temp=l;
	while(temp->data!=x)
	temp=temp->right;
	DPTR temp2=create(y);
	temp2->right=temp;
	temp->left->right=temp2;
	temp2->left=temp->left;
	temp->left=temp2;
	
}
void addaft(DPTR &l,int x,int y)
{
	
	DPTR temp1=l;
	while(temp1->data!=x)
	temp1=temp1->right;
	DPTR temp2=create(y);
	temp2->right=temp1->right;
	temp1->right=temp2;
	//temp2->right->left=temp2;
	temp2->left=temp1;
}
void sort(DPTR &l1,DPTR &l2)
{ 
	if(l1==NULL) return;
	
if(l1->data>l2->data){
		if(l2->right==NULL){
			l2->right=l1;
			return;
		}
		sort(l1,l2->right);
	}
	else
	{
		DPTR temp=l1->right;
		addbef(head,l2->data,l1->data);
		l1=temp;
		sort(l1,l2);
	}
	
}
void printlist(DPTR l)
{
	while(l!=NULL)
	{
		cout<<l->data<<" ";
		l=l->right;
	}
}
int main()
{
	DPTR l1=NULL,l2=NULL;
	
	int n;cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		addend(l1,x);
	}
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		addend(l2,x);
	}
	head=l2;
	sort(l1,l2);

	printlist(head);
}
