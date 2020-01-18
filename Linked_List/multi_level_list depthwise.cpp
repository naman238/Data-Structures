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
void printlst(LPTR l){
if(l==NULL)
return;
cout<<l->data<<" ";
if(l->dlink!=NULL)
printlst(l->dlink);
if(l->next!=NULL)
printlst(l->next);
}
int main()
{ LPTR l=NULL;
int x;
cin>>x;
l=create(x);
construct(l);
printlst(l);
cout<<endl;
return 0;

}

