#include<iostream>
using namespace std;
struct lnode {
  int data;
  struct lnode * dlink;
  struct lnode * next;
};
typedef struct lnode * LPTR;
struct lnode * create(int i) {
  LPTR t = new struct lnode;
  t -> data = i;
  t -> dlink = NULL;
  t -> next = NULL;
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
void flat(LPTR &l,LPTR t)
{
	if(l==NULL)
		return;
	if(l->next!=NULL)
	{	
		t=l->next;
		cout<<t->data;
	}
	if(l->dlink==NULL)
	{
		l->dlink=t;
		t=NULL;
	} 
	flat(l->dlink,t);
}
void printlst(LPTR l){
  if (l == NULL)
    return;
    cout << l -> data << " ";
    printlst(l->dlink);
  
}
int main() {
  LPTR l = NULL;
   int x;
  cin>>x;
  l=create(x);
  construct(l);
  flat(l,NULL);
  printlst(l);
  cout << endl;
  return 0;
}
