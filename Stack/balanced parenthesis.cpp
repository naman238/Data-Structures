#include <iostream>
using namespace std;
struct stck{
	int size;
	char elements[50];
	int top;
};
void push(struct stck x,char c){
    if(x.top==x.size-1)
    cout<<"full";
    else
    x.elements[++x.top]=c;
}
void pop(struct stck x){
   if(x.top==-1){
       return;
   } 
   else
   x.top--;
}
char peek(struct stck x){
    if(x.top!=-1)
    return x.elements[x.top];
}
bool ispair(char a,char b){
    if((a=='(' && b==')')||(a=='[' && b==']')||(a=='{' && b=='}')){
        return true;
    }
    return false;
}
int main() {
    string s;
    cin>>s;
    struct stck x;
    x.top=-1;
    x.size=30;
    int flag=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='[' || s[i]=='{' || s[i]=='('){
            push(x,s[i]);
        }
        else if(s[i]==']' || s[i]=='}' || s[i]==')'){
            if(x.top==-1){
                flag=1;
                break;
            }
            else if(ispair(peek(x),s[i])){
                pop(x);
            }
            else {
                flag=1;
                break;
            }
        }
    }
    if(flag==1){
        cout<<"YES";
    }
    else cout<<"NO";
	return 0;
}
