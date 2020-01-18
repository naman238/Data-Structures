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
int b[6];
struct stck x;
x.top=-1;
x.size=30;
for(int i=0;i<6;i++)
    cin>>b[i];
int j=0;
for(int i=1;i<=7 && j<6;i++)
{
    if(b[j]!=peek(x) || x.top==-1){
        if(i<=6){
        cout<<"push"<<" ";
        push(x,i);
        }
    }
    else{
        cout<<"pop"<<" ";
        pop(x);
        j++;
        i--;
    }
}
cout<<endl;
if(x.top==-1){
    cout<<"YES";
}
else{
    cout<<"NO";
}
return 0;
}

