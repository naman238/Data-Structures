#include <iostream>
using namespace std;
struct pnode{
int data;
struct pnode * next;
};
typedef struct pnode* LPTR;
LPTR head=NULL;
struct pnode* create(int x){
	LPTR p;
	p=new(struct pnode);
	p->next=NULL;
	p->data=x;
	return p;
}
void add(LPTR &l,int x,int &p){
	p++;
if(l==NULL){
	l=create(x);
	head=l;
}
else{
	LPTR temp=l;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=create(x);
	}
}
int mid(LPTR& l)
{
	LPTR fast=l;
	LPTR slow=l;
	int count=1;
	if(l==NULL)
		return 0;
while(fast->next!=NULL && fast->next->next!=NULL){
	fast=fast->next->next;
	slow=slow->next;
	count++;
}
return count;
}
void spiral(LPTR l,int count,LPTR z){
LPTR t=l;
static LPTR t1=z;
static int c=count;
if(t->next==NULL){
	LPTR t2=t1->next;
	t->next=t2;
	t1->next=t;
	t1=t2;
	c--;
	return;
}
spiral(t->next,count,z);
if(c>0){
	LPTR t2=t1->next;
	t->next=t2;
	t1->next=t;
	t1=t2;c--;
}
else if(c==0){
	t->next=NULL;c--;
}
}
void printlst(LPTR l){
	LPTR t=l;
	if(t==NULL)return ;
	else{
		cout<<t->data<<" ";
		printlst(t->next);
	}
}
int main(){
	LPTR l=NULL;
	int p=0;
	add(l,1,p);
	add(l,3,p);
	add(l,5,p);
	add(l,7,p);
	add(l,6,p);
	add(l,4,p);
	add(l,2,p);
	printlst(l);
	cout<<endl;
	int c=mid(l);
	spiral(l,p-c,l);
	printlst(l);
	cout<<endl;
	return 0;
}
