#include <iostream>
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
void delpos(LPTR &l,int x){
	LPTR t=l;
	if(l->data==x){
   	l=l->next;
   	delete t;
   	return;
	}
	while(t->next->data!=x){
		t=t->next;
	}
	LPTR z=t->next;
	t->next=z->next;
	delete z;
}
void removedupli(LPTR &l){
	if(l==NULL || l->next==NULL){
	return;
	}
	LPTR t=l;
	LPTR t1=l->next;
	while(t->next!=NULL)
	{
	while(t1!=NULL)
	{

		if(t->data==t1->data){
			LPTR p=t->next;
			delpos(l,t->data);
			t=p;	
			t1=t->next;
			break;
		}
		else{
		t1=t1->next;
		}	
	}
		if(t->next==NULL){
   			break;
		}
		else if(t1==NULL)
		{
			t=t->next;
			t1=t->next;
		}
	}
}
void printlst(LPTR &l){
LPTR t=l;
if(t==NULL)return ;
else{
cout<<t->data<<" ";
printlst(t->next);
}
}
int main() {
LPTR l=NULL;
int x;
for(int i=1;i<=4;i++)
{
cin>>x;
add(l,x);
}

removedupli(l);
printlst(l);
cout<<endl;
return 0;
}
