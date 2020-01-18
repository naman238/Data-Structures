#include <iostream>
using namespace std;
struct pnode{
int co;
int exp;
struct pnode * next;
};
typedef struct pnode* LPTR;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct pnode* create(int x,int y){
LPTR p;
p=new(struct pnode);
p->next=NULL;
p->co=x;
p->exp=y;
return p;
}
void add(LPTR &l,int x,int y){
if(l==NULL){
l=create(x,y);
}
else{
LPTR temp=l;
while(temp->next!=NULL){
temp=temp->next;
}
temp->next=create(x,y);
}
}
LPTR polyadd(LPTR &l,LPTR &l1,LPTR &l2)
{
	if(l==NULL && l1==NULL){
		return NULL;
	}
	else if(l==NULL){
		while(l1!=NULL){
			add(l2,l1->co,l1->exp);
			l1=l1->next;
		}

	}
	else if(l1==NULL){
		while(l!=NULL){
			add(l2,l->co,l->exp);
			l=l->next;
		}
	}
	else{
		while(l!=NULL && l1!=NULL){
			if(l->exp==l1->exp){

			add(l2,(l->co+l1->co),l->exp);
			l1=l1->next;
			l=l->next;
			}
			else if(l->exp>l1->exp){
				add(l2,l->co,l->exp);
				l=l->next;
			}
			else if(l->exp<l1->exp){
				add(l2,l1->co,l1->exp);
				l1=l1->next;
			}
		}
		if(l!=NULL){
			while(l!=NULL){
				add(l2,l->co,l->exp);
				l=l->next;
			}
		}
		else {
			while(l1!=NULL){
				add(l2,l1->co,l1->exp);
				l1=l1->next;
			}
		}
	}  
return l2;
}
void printlst(LPTR &l){
LPTR t=l;
if(t==NULL)return ;
else{
cout<<t->co<<"x"<<t->exp<<" ";
printlst(t->next);
}
}
int main() {
LPTR l=NULL;
int co,exp;
for(int i=1;i<=4;i++)
{
cin>>co>>exp;
add(l,co,exp);
}


LPTR l1=NULL;

for(int i=1;i<=5;i++)
{
cin>>co>>exp;
add(l1,co,exp);
}
LPTR p=NULL;
LPTR res=polyadd(l,l1,p);
while(res!=NULL){
cout<<res->co<<"x^"<<res->exp<<;
if(res->next!=NULL){
cout<<"+";
}
res=res->next;
}
cout<<endl;
return 0;
}

