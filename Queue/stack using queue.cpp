#include<iostream>
using namespace std;
struct queue{
	int size;
	int elements[100];
	int front;
	int rear;
};
void enqueue (struct queue &q,int x)
{
	if((q.rear+1)%q.size==q.front)
	cout<<"queue is full";
	else {		
	if(q.front==-1) q.front=0;
	q.rear=(q.rear+1)%q.size;
	q.elements[q.rear]=x;
	}
}
int dequeue(struct queue &q)
{   int t;
	if(q.front==-1)
	{
		cout<<"empty queue";
		return -1;
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
void push(struct queue &q,int x)
{
	enqueue(q,x);
}
int pop(struct queue &q)
{
	struct queue q2;
	q2.front=-1;
	q2.rear=-1;
	q2.size=q.size;
	while(q.front!=q.rear)
	{
		enqueue(q2,dequeue(q));
	}
	int x= dequeue(q);
	while(q2.front!=-1)
	{
		enqueue(q,dequeue(q2));
	}
	return x;
}
int main()
{
	struct queue q1;
	q1.front=-1;
	q1.rear=-1;
	int n;
	cin>>n;
	q1.size=n;
	
	for(int i=0;i<n;i++)
	{  int x;
	    cin>>x;
		push(q1,x);
	}
	for(int i=0;i<n;i++)
	cout<<pop(q1)<<" ";
}
