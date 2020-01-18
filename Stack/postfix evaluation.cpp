#include <bits/stdc++.h>
using namespace std;
struct stck{
int size;
int elements[50];
int top;
};
void push(struct stck &x,int c){
    if(x.top==x.size-1)
    cout<<"full";
    else{
        x.top++;
    x.elements[x.top]=c;
    }
}
void pop(struct stck &x){
   if(x.top==-1){
       return ;
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
int opert(int op1,int op2,char c){
    switch(c){
        case '+':return op2+op1;break;
        case '-':return op2-op1;break;
        case '*':return op2*op1;break;
        case '/':return op2/op1;break;
    }
}
int main() {
    string s;
    cin>>s;
    struct stck x;
    x.top=-1;
    x.size=30;
    int res;
    for(int i=0;i<s.length();i++){
        if(int(s[i]-'0')>=1 && int(s[i]-'0')<=9){
           
            push(x,int(s[i]-'0'));
        }
      
        else if(s[i]=='-' || s[i]=='+' || s[i]=='*'|| s[i]=='/'){
            int op1=peek(x);
            pop(x);
            int op2=peek(x);
            pop(x);
             res=opert(op1,op2,s[i]);
            push(x,res);
        }
    }
    cout<<res<<endl;
   
   
return 0;
}


