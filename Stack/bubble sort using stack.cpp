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
int main() {
int n;
cin>>n;
struct stck x;
x.top=-1;
x.size=30;
int y;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
push(x,a[0]);
for(int i=1;i<n;i++){
    for(int j=1;j<=n-i;j++)
	{
    	if(a[j]>=peek(x)){
     	   push(x,a[j]);
    	}
    	else {
        	int l=peek(x);
        	pop(x);
        	push(x,a[j]);
        	push(x,l);
    	}
    	if(j==n-i)
		{
        	for(int k=n-i;k>=0;k--){
            	a[k]=peek(x);
            	pop(x);
        	}
        	push(x,a[0]);
    	}
	}
}
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
return 0;
}
