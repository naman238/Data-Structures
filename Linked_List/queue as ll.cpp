#include <iostream>
using namespace std;
struct pnode{
int data;
struct pnode * next;
};
struct pnode * front;
struct pnode * rear;
typedef struct pnode* LPTR;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct pnode* create(int x){
LPTR p;
p=new(struct pnode);
p->next=NULL;
p->data=x;
return p;
}
void enqueue(LPTR &l,int x){
	if(l==NULL){
		l=create(x);
		front=l;
		rear=l;
	}
	else{
		LPTR temp=create(x);
		rear->next=temp;
		rear=temp;
	}
}
int dqueue(LPTR &l){
	LPTR t=l;
	if(l==NULL)return -1;
	else if(l->next==NULL){
		delete l;
		front =rear=NULL;
	}
	else{
		l=l->next;
		front=l;
		delete t;
	}
	return t->data;
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
enqueue(l,x);
}
dqueue(l);
//removedupli(l);
printlst(l);
cout<<endl;
dqueue(l);
printlst(l);
cout<<endl;
return 0;
}
