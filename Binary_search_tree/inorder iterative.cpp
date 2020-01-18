#include<iostream>
using namespace std;
typedef
struct bstnode
{
	struct bstnode* lchild;
	int data;
	struct bstnode* rchild;
} *BSTPTR;
struct stck{
	int size;
	BSTPTR elements[100];
	int top;
};
void push (struct stck &st,BSTPTR x)
{
	if(st.top==st.size-1)
	cout<<"stack is full";
	else {
		st.top++;
		
	st.elements[st.top]=x;}
}
BSTPTR pop(struct stck &st)
{
	if(st.top==-1)
	{
		cout<<"empty stack";
		return 0;
	}
	else return st.elements[st.top--];
}
BSTPTR peek(struct stck &st)
{
	return st.elements[st.top];
}
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
void inorder(BSTPTR b)
{
	struct stck s;
	s.top=-1;s.size=100;
	while(b!=NULL)
	{
	
		while(b->lchild!=NULL)
		{
			push(s,b);
			b=b->lchild;
		}
		push(s,b);
	
		while(s.top!=-1 && peek(s)->rchild==NULL )
        {  
    		cout<<peek(s)->data<<" ";    
			b=pop(s);
		}
	
		if(s.top!=-1)
		{
			cout<<peek(s)->data<<" ";
		    b=pop(s)->rchild;}
		else return;  		
	}
	
	return;
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
	inorder(b);
	return 0;
}
