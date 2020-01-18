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
	int elements[100];
	int top;
};
void push (struct stck &st,int x)
{
	if(st.top==st.size-1)
	cout<<"stack is full";
	else {
		st.top++;
		
	st.elements[st.top]=x;}
}
int pop(struct stck &st)
{
	if(st.top==-1)
	{
		cout<<"empty stack";
		return 0;
	}
	else return st.elements[st.top--];
}
int peek(struct stck &st)
{
	return st.elements[st.top];
}
struct queue{
	int size;
	BSTPTR elements[100];
	int front;
	int rear;
};
void enqueue (struct queue &q,BSTPTR x)
{
	if((q.rear+1)%q.size==q.front)
	cout<<"queue is full";
	else {		
	if(q.front==-1) q.front=0;
	q.rear=(q.rear+1)%q.size;
	q.elements[q.rear]=x;
	}
}
BSTPTR dequeue(struct queue &q)
{   BSTPTR t;
	if(q.front==-1)
	{
		cout<<"empty queue";
		return t;
	}
	else {
		t=q.elements[q.front];
		if(q.front==q.rear)
		{
			q.front=-1;
			q.rear=-1;
		}
		else
		q.front =(q.front+1)%q.size;
	return t;
}
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
}int gl=1;
void levelorder(BSTPTR t)
{
	struct stck s;s.top=-1;s.size=100;
	struct stck s1;s1.top=-1;s1.size=100;
	struct queue q;
	q.front=-1;
	q.rear=-1;
	q.size=100;
    enqueue(q,t);
    BSTPTR temp=create(-1);
    enqueue(q,temp);
	
	while(q.front!=-1)
	{   
		while(q.elements[q.front]->data!=-1)
		{
			BSTPTR current=dequeue(q);
			if(gl>0) {
			cout<<current->data<<" ";
			push(s1,current->data);}
			else
			{
			push(s,current->data);
			}
			if(current->lchild!=NULL) enqueue(q,current->lchild);
			if(current->rchild!=NULL) enqueue(q,current->rchild);
		}
		BSTPTR t=dequeue(q);
		if(q.front!=-1)enqueue(q,temp);
		while(s.top!=-1)
		{    push(s1,peek(s));
			cout<<pop(s)<<" ";
		}
		gl=-gl;
		cout<<endl;
	}	
	cout<<endl<<endl;
	while(s1.top!=-1) cout<<pop(s1)<<" ";
	cout<<endl;
	
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
	levelorder(b);
	return 0;
}
