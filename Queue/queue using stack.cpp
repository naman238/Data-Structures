#include <bits/stdc++.h>
using namespace std;
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
void enqueue(struct stck &s,int x)
{
	push(s,x);
}
int dequeue(struct stck &s)
{
	struct stck st;
	
	st.size=s.size;
	st.top=-1;
	while(s.top!=0)
	{
		push(st,pop(s));
	}
	int x=pop(s);
	while(st.top!=-1)
	{
		push(s,pop(st));
	}
	return x;
}
int main() {
	struct stck st;
	int n;
	cin>>n;
	st.size=n;
	st.top=-1;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		enqueue(st,x);
	}
	for(int i=0;i<n;i++)
	{
		cout<<dequeue(st)<<" ";
	}
}
