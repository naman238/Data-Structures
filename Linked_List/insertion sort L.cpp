#include <iostream>

using namespace std;
struct pnode {
  int data;
  struct pnode * next;
};
typedef struct pnode * LPTR;
LPTR head=NULL;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct pnode * create(int x) {
  LPTR p;
  p = new(struct pnode);
  p -> next = NULL;
  p -> data = x;
  return p;
}
void add(LPTR & l, int x) {
  if (l == NULL) {
    l = create(x);
  } else {
    LPTR temp = l;
    while (temp -> next != NULL) {
      temp = temp -> next;
    }
    temp -> next = create(x);
  }
}
void sorted_insert(LPTR& l,int x)
{
	if(l==NULL || l->data>x)
	{
		LPTR t=create(x);
		t->next=l;
		l=t;
	}
	else
	{
		LPTR t=l,pre=NULL;
		while(t!=NULL && t->data<=x)
		{	pre=t;
			t=t->next;
		}
		LPTR p=create(x);
		pre->next=p;
		p->next=t;
	}
}
void inssort(LPTR &l)
{
	LPTR t=l;
	while(t!=NULL)
	{
		LPTR nxt=t->next;
		sorted_insert(head,t->data);
		t=nxt;
	}
}
int main()
{
	LPTR l=NULL;
	int n;
	cin>>n;
	while(n--)
	{	
		int x;
		cin>>x;
		add(l,x);
	}
	inssort(l);
	
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	return 0;
}
