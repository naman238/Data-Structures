#include <bits/stdc++.h>
using namespace std;
struct stck{
int size;
char elements[50];
int top;
};
void push(struct stck &x,char c){
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
char peek(struct stck &x){
    if(x.top==-1)
    return -1;
    else
    return x.elements[x.top];
}
int prcdnce(struct stck x,char c){
	if(c=='^')
		return 3;
    else if(c=='*'|| c=='/')
    	return 2;
    else if(c=='-'|| c=='+')
    	return 1;
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
            cout<<s[i];
        }
       else if(s[i]=='-' || s[i]=='+' || s[i]=='*'|| s[i]=='/'||s[i]=='('||s[i]==')'){
        if(s[i]=='(' || x.top==-1){
              push(x,s[i]);
        }
        else if(s[i]==')'){
            while(peek(x)!='('){
                char c=peek(x);
                pop(x);
                cout<<c;
            }
            pop(x);
        }
        else{
            while((prcdnce(x,s[i])<=prcdnce(x,peek(x))) && x.top!=-1){
           char c=peek(x);
           pop(x);
           cout<<c;
        }
        push(x,s[i]);
        }
    }
    }
    while(x.top!=-1){
        cout<<peek(x);
        pop(x);
    }
    cout<<endl;
return 0;
}

