#include<iostream>
#include<vector>
using namespace std;
struct hfnode;
struct s {
	hfnode* lchild;
	hfnode* rchild;
};
union u{
	char ch;
	struct s s1;
};
typedef
struct hfnode{
	int flag;
	union u u1;
	int freq;
}* hfptr;
hfptr create(int x,int y)
{
	hfptr tt=new struct hfnode;
	tt->flag=1;
	tt->freq=x+y;
	tt->u1.s1.lchild=tt->u1.s1.rchild=0;
	return tt;
}
int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
void per_down(vector <hfptr> &h,int size)
{
	h[0]=h[h.size()-1];
	int j=0;
	int x=2*j+1;
	int z=h[0]->freq;
	hfptr tt=create(1000,1000);
	if(x<size && x+1>=size) h.push_back(tt);
	while((x<size || x+1<size) && z>min(h[x]->freq,h[x+1]->freq))
	{
		int a=(h[x]->freq<h[x+1]->freq)?x:x+1;
		swap(h[j],h[a]);
	    j=a;
	    if(x<size && x+1>=size) h.resize(size);
		x=2*j+1;
	}
}
void per_up(vector<hfptr> &h,int n,hfptr k)
{
	
	h.push_back(k);
		int x=(n-1)/2;
		int j=n;
		while(x>=0 && h[x]->freq>k->freq)
		{
			swap(h[x],h[j]);
			j=x;
			x=(x-1)/2;
		}
}
void hfc( vector<hfptr>a,vector<hfptr> &h){
	for(int i=0;i<a.size();i++)
	{
		per_up(h,i,a[i]);
	}
	while(h.size()!=1)
	{
		hfptr left=h[0];
		int y=h.size();
		per_down(h,y-1);	
		h.resize(y-1);
		hfptr right=h[0];
	    y=h.size();
		per_down(h,y-1);	
		h.resize(y-1);
		hfptr temp=create(left->freq,right->freq);
		temp->u1.s1.lchild=left;
		temp->u1.s1.rchild=right;
		per_up(h,h.size()-1,temp);
	}
}
hfptr head;
void decod(hfptr t,string str,int &i)
{
	if(i==str.length()) return;
	while(t->flag!=0 && i<str.length())
	{
		if(str[i++]=='0')
		t=t->u1.s1.lchild;
		else t=t->u1.s1.rchild;
	}
	cout<<t->u1.ch;
	decod(head,str,i);
}

void encod(hfptr t,string c,string s,int &j)
{
 	if(j>=s.length())
	{
		return;
	}
	else if(t->flag==0 && t->u1.ch==s[j]) {
		cout<<c;
		t=head;
		j=j+1;
		c="";
		encod(head,c,s,j);
		return;
	}
	 if(t->flag!=0)
	encod(t->u1.s1.lchild,c+"0",s,j);
	if(t->flag!=0)
	encod(t->u1.s1.rchild,c+"1",s,j);
}
int main()
{
	int n;cin>>n;
    vector<hfptr> a;
	vector<hfptr> h;
	for(int i=0;i<n;i++)
	{
		hfptr t=new struct hfnode;
		t->flag=0;
		char c;cin>>c;
		t->u1.ch=c;
		int f;cin>>f;
		t->freq=f;
		a.push_back(t);
	}
	hfc(a,h);
	string str;cin>>str;
	head=h[0];
	int i=0;
	decod(h[0],str,i);
	string c="";
	string ss;cin>>ss;int z=0;
	head=h[0];
	encod(h[0],c,ss,z);
	return 0;
}
