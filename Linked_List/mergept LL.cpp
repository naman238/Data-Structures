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

LPTR lnk(LPTR &l1,LPTR &l2,int pos){
	int x=1;
	LPTR t1=l1;
	LPTR t2=l2;
	if(l1==NULL)return NULL;
	else if(l2==NULL){
	while(x!=pos){
		t1=t1->next;
		x++;
	}
	}
	else{
		while(x!=pos){
		t1=t1->next;
		x++;
		}
	}
	return t1;
}
void printlst(LPTR &l){
	LPTR t=l;
	if(t==NULL)return ;
	else{
		cout<<t->data<<" ";
		printlst(t->next);
	}
}

int mrgept(LPTR & l1,LPTR &l2,stack<int>s1,stack<int>s2){
	LPTR t1=l1;
	LPTR t2=l2;
	while(t1->next!=NULL){
		s1.push(t1->data);
		t1=t1->next;
	}
	while(t2->next!=NULL){
		s2.push(t2->data);
		t2=t2->next;
	}
	int x;
	while(s1.top()==s2.top()){
		x=s1.top();
		s1.pop();
		s2.pop();
	}
	return x;
}
int main() {
	LPTR l1=NULL;
	int n1;
	cin>>n1;
	int x;
	for(int i=0;i<n1;i++){
	cin>>x;
	add(l1,x);
	}
	printlst(l1);
	LPTR l2=NULL;
	char ch='n';
	int pos;
	while(1){
		cout<<"do you want to link now (y/n): ";
		cin>>ch;
		cout<<endl;
		if(ch=='y'){
			cout<<"enter link pos: ";
			cin>>pos;
			break;
		}
		else{
			cin>>x;
			add(l2,x);
		}
	}
	LPTR t2=l2;
	stack<int> s1,s2;
	while(t2->next!=NULL){
		t2=t2->next;
	}
	t2->next=lnk(l1,l2,pos);
	cout<<"merge pt. is"<<mrgept(l1,l2,s1,s2)<<endl;
	
	return 0;
}
