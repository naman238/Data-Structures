#include<iostream>
#include<vector>
using namespace std;
struct st{
	int value;
	int row;
};
struct lnode
{
	int data;
	struct lnode* next;
};
typedef struct lnode* LPTR;
struct lnode* create(int x)
{
	LPTR t;
	t=new(struct lnode);
	t->data=x;
	t->next=NULL;
	return t;
}
void addend(LPTR &l,int x)
{
	LPTR t;
	if(l==NULL)
	{
		l=create(x);
	}
	else
	{
		LPTR temp=l;
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=create(x);
	}
}int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
void per_down(vector <struct st> &h,int z,int rw,int size)
{
	h[0].value=z;
	h[0].row=rw;
	int j=0;
	int x=2*j+1;
	struct st t;t.value=1000;t.row=1;
	if(x<size && x+1>=size) h.push_back(t);
	while((x<size || x+1<size) && z>min(h[x].value,h[x+1].value))
	{
		int a=(h[x].value<h[x+1].value)?x:x+1;
		swap(h[j],h[a]);
	    j=a;
	    if(x<size && x+1>=size) h.resize(size);
		x=2*j+1;
	}
}
void per_up(vector<struct st> &h,int n,int k)
{
	struct st temp;temp.value=k;temp.row=n;
	h.push_back(temp);
		int x=(n-1)/2;
		int j=n;
		while(x>=0 && h[x].value>k)
		{
			swap(h[x],h[j]);
			j=x;
			x=(x-1)/2;
		}
}
void merge(LPTR p[],int n,vector<struct st> &v,vector<struct st> &h,int sum)
{
	for(int i=0;i<n;i++)
	{
		per_up(h,i,p[i]->data);
	}
	p[h[0].row]=p[h[0].row]->next;
	v.push_back(h[0]);
	while(v.size()<sum)
	{
		if(p[h[0].row]!=0)
		{
		per_down(h,p[h[0].row]->data,h[0].row,h.size());
		p[h[0].row]=p[h[0].row]->next;
		}
		else{
			int y=h.size();
		per_down(h,h[y-1].value,h[y-1].row,y-1);	
		h.resize(y-1);
		p[h[0].row]=p[h[0].row]->next;
		}
		v.push_back(h[0]);
	}
}
int main()
{
	int n;
	cin>>n;
	LPTR p[n];
	for(int j=0;j<n;j++)
	p[j]=0;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
	    int n1;cin>>n1;
		sum+=n1;
		for(int j=0;j<n1;j++)
		{
			int x;cin>>x;addend(p[i-1],x);
		}
	}
	vector<struct st> v;
	vector<struct st> h;
	merge(p,n,v,h,sum);
	for(int i=0;i<v.size();i++)
	cout<<v[i].value<<" ";
	return 0;
}
