#include<iostream>
using namespace std;
int min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
void per_up(int h[],int n,int a[])
{
	for(int i=0;i<n;i++)
	{
		h[i]=a[i];
		int x=(i-1)/2;
		int j=i;
		while(x>=0 && h[x]<a[i])
		{
			swap(h[x],h[j]);
			j=x;
			x=(x-1)/2;
		}
	}
}
void per_down(int h[],int n,int a[],int i)
{
	while(n>=0)
	{
	h[0]=h[n-1];
	int k=h[n-1];
	n--;
	int j=0;
	int x=2*j+1;
	int z=1000;
	if(x<n && x+1>=n)
		h[n]=z;
	while((x<n || x+1<n) && k>min(h[x],h[x+1]))
	{
		int a=(h[x]<h[x+1])?x:x+1;
		swap(h[j],h[a]);
		j=a;
		x=2*j+1;
	}
	a[i++]=h[0];
   }	
}
int main()
{
	int n;cin>>n;
	int h[n+1];
	for(int i=0;i<n;i++) cin>>h[i];
	int a[n];
	h[n]=h[0];
	per_down(h,n+1,a,0);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
return 0;
}
