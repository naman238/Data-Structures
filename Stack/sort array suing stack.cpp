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
    else
	{
        x.top++;
    
    x.elements[x.top]=c;
	}
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
    cin>>y;
    push(x,y);
    a[i]=y;
}
a[0]=peek(x);
pop(x);
int flag=0;
for(int i=1;i<n;i++){
    	if(x.top==-1 || a[i]>=peek(x)){
        	push(x,a[i]);
    	}
    	while(x.top==-1 && a[i]<peek(x))
    	{
    		int z=peek(x);
			push(q,z);
			pop(x);	
		}
		if(flag==1)
		{
			push(x,a[i]);
			while(q.top==-1)
			{
				push(x,peek(q));
				pop(q);	
			}	
		}	
}

for(int i=0;i<n;i++){
    cout<<peek(x)<<" ";
    pop(x);
}
return 0;
}
