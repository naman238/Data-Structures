#include <iostream>
#include <stack>
using namespace std;
struct pnode{
int data;
struct pnode * next;
};

typedef struct pnode* LPTR;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct pnode* create(int x){
	LPTR p;
	p=new(struct pnode);
	p->next=NULL;
	p->data=x;
	return p;
}
void add(LPTR &l,int x){
if(l==NULL){
	l=create(x);
}
else{
	LPTR temp=l;
while(temp->next!=NULL){
	temp=temp->next;
}
	temp->next=create(x);
}
}
void addfront(LPTR &l,int x){
	LPTR t=new struct pnode;
	t->data=x;
	t->next=l;
	l=t;
}
void add1(LPTR &l,stack<LPTR> s)
{
	LPTR temp=l;
	while(temp!=NULL){
		s.push(temp);
		temp=temp->next;
	}
	int carry=1;
	LPTR x;
	while(s.size()!=1){
		x=s.top();
	if(x->data+carry<10){
		x->data=x->data+carry;
	}
	else{
		carry=((x->data+carry))/10;
		x->data=(x->data+carry)%10;
	}
		s.pop();
	}
		x=s.top();
	if(x->data+carry<10){
		x->data=x->data+carry;
		return;
	}
	else{
		carry=((x->data+carry))/10;
		x->data=(x->data+carry)%10;
		addfront(l,carry);
	}
	s.pop();
}
void printlst(LPTR &l){
	LPTR t=l;
	if(t==NULL)return ;
else{
	cout<<t->data<<" ";
	printlst(t->next);
}
}

int main(){
	LPTR l=NULL;
	add(l,9);
	add(l,9);
	add(l,9);
	stack <LPTR> s;
	add1(l,s);
	printlst(l);
	return 0;
}

