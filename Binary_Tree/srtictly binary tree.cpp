#include<iostream>
using namespace std;
typedef
struct btnode{
btnode *lchild;
btnode *rchild;
int data;
int x;
}*btptr;
btptr newnode(int z)
{
btptr t=new struct btnode;
t->data=z;
//t->x=xc;
t->lchild=t->rchild=NULL;
}
int retind(int a[],int x,int n)
{
int j;
for(j=0;j<n;j++)
{if(a[j]==x) break;}
return j;}
int count=0;
void create(btptr &t,int pre[],int in[],int n,int low,int high)
{
if(low>=high || count==n) return;
int x=retind(in,pre[count++],n);
t=newnode(in[x]);
create(t->lchild,pre,in,n,low,x);
create(t->rchild,pre,in,n,x+1,high);
}
bool isstrbin(btptr t)
{
	if(t->lchild==0 && t->rchild==0)  return true;
	if(t->lchild==0 || t->rchild==0) return false;
	if(!isstrbin(t->lchild) || !isstrbin(t->rchild)) return false;
	else return true;
}
int main()
{
int n;
cin>>n;int a[n],b[n];
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<n;i++)cin>>b[i];
btptr t;
create(t,a,b,n,0,n);
if(isstrbin(t)) cout<<"yes";
else cout<<"no";
return 0;
}
