#include <iostream>
using namespace std;
struct stck{
int size;
char elements[50];
int top;
};
void push(struct stck &x,int c){
    if(x.top==x.size-1)
    cout<<"full";
    else{
        x.top++;
    	x.elements[x.top]=c;}
}
void pop(struct stck &x){
   if(x.top==-1){
       return;
   } 
   else
   x.top--;
}
int peek(struct stck &x){
    if(x.top==-1)
    return -1;
    else
    return x.elements[x.top];
}
int main(){
int n;
cin>>n;
int a[n];
struct stck x;
x.top=-1;
x.size=n;
int p;
for(int i=0;i<n;i++)
{
	cin>>p;
	push(x,p);
}
int b[n];
int i=0;
int j=0;
while(x.top!=-1)
{
	int flag=0;
	int temp=0;
	if(i==0 || peek(x)>a[i-1])
	{
		a[i]=peek(x);
		temp=1;
		pop(x);
	}
	if(temp==0)
		i--;
	while(i>=0 && x.top!=-1 && peek(x)<a[i])
	{
		b[j]=a[i];
		i--;
		j++;
		flag=1;
	}
	i++;
	if(flag==1)
	{
		a[i]=peek(x);
		pop(x);
		i++;
	}
	while(j>0)
	{
		a[i]=b[j-1];
		i++;
		j--;
	}
}
for(int i=0;i<n;i++)
	cout<<a[i];
return 0;
}
