#include<bits/stdc++.h>
using namespace std;
struct lnode
{
int data;
struct lnode* dlink;
struct lnode* next;
};
typedef struct lnode* LPTR;
struct lnode* create(int x)
{ 
	LPTR t=new struct lnode;
	t->data=x;
	t->dlink=NULL;
	t->next=NULL;
	return t;
}

void construct(LPTR& l)
{
	cout<<l->data<<" ";
	cout<<"dlink element";
	int x;
	cin>>x;
	if(x!=0)
	{
		l->dlink=create(x);
		construct(l->dlink);
	}
	cout<<l->data<<" next element";
	cin>>x;
	if(x!=0)
	{
		l->next=create(x);
		construct(l->next);
	}
}

void printlst(LPTR l,queue<LPTR> &q,LPTR c) 
{
	if(l==NULL)
		return;
    if(l->dlink!=NULL) {
        q.push(l->dlink);
    }
    if(l->next==NULL) {
        cout<<l->data<<" ";
        if(q.size()==1)
            return ;
        LPTR temp=q.front();
        q.pop();
        if(temp->data==-1) {
            q.push(c);
            cout<<endl;
            temp=q.front();
            q.pop();
        }
        printlst(temp,q,c);
    }
    else {
        cout<<l->data<<" ";
        printlst(l->next,q,c);
    }
}
int main()
{ 	
	LPTR l=NULL;
	int x;
	cin>>x;
	l=create(x);
	construct(l);
    queue<LPTR> q;
    LPTR c=new lnode;
    c->next=NULL;
    c->data=-1;
    q.push(c);
    printlst(l,q,c);
    //printlst(l);
    cout<<endl;
    return 0;
}
