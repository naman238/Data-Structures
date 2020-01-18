#include <bits/stdc++.h>
using namespace std;
union u {
    int opd;
    char opt;
};
struct etnode {
    int flag;
    union u data;
    etnode* lc;
    etnode* rc;
};
typedef etnode* etptr;
etptr create(etptr &T,string s) {
    stack <etptr> st;
    int i=0,x,o,j,z;
    while(i<s.length()) {
        if(s[i]-'0'>=0 && s[i]-'0'<=9) {
            etptr l=new etnode;
            l->flag=0;
            o=0;
            z=i;
            while(s[z]!=',')
            {
            	o+=o*10+(s[z]-'0');
            	z++;
			}
            l->data.opd=o;
            l->lc=l->rc=NULL;
            st.push(l);
            i=z;
            if(s[i]==',') {
                i++;
            }
        }
        else if(s[i]=='+'|| s[i]=='-' || s[i]=='*' || s[i]=='/'){
            etptr l=new etnode;
            l->flag=1;
            l->data.opt=s[i];
            l->rc=st.top();
            st.pop();
            l->lc=st.top();
            st.pop();
            st.push(l);
            if(i==s.length()-1) {
                T=l;
            }
            i++;
            if(s[i]==',') {
                i++;
            }
        }
    }
    return T;
}
int eval(etptr T) {
    if(T->flag==0) {
        return T->data.opd;
    }
    else {
        switch(T->data.opt) {
        case '+':
            return eval(T->lc)+eval(T->rc);
            break;
        case '-':
            return eval(T->lc)-eval(T->rc);
            break;
        case '/':
            return eval(T->lc)/eval(T->rc);
            break;
        case '*':
            return eval(T->lc)*eval(T->rc);
            break;
        }
    }
}
void inorder(etptr T,queue <etptr> &q) {
    if(T!=NULL) {
        inorder(T->rc,q);
        q.push(T);
        inorder(T->lc,q);
    }
}
int solve(int y,char z,int w) {
    int res;
    switch (z) {
    case '+':
        res=w+y;
        break;
    case '-':
        res=w-y;
        break;
    case '/':
        res=w/y;
        break;
    case '*':
        res=w*y;
        break;
    }
    return res;
}
int main() {
    etptr T=NULL;
    string s;
    cin>>s;	//postfix exp.
    T=create(T,s);
    queue <etptr> q;
    inorder(T,q);
    while(q.size()!=3) {
        while(q.front()!=T)
		 {
            q.push(q.front());
            q.pop();
        }
        q.push(q.front());
        q.pop();
        int y=q.front()->data.opd;
        q.pop();
        char z=q.front()->data.opt;
        q.pop();
        int w=q.front()->data.opd;
        q.pop();
        int res=solve(y,z,w);
        etptr l=new etnode;
        l->flag=0;
        l->data.opd=res;
        l->lc=l->rc=NULL;
        q.push(l);
    }
    int y=q.front()->data.opd;
    q.pop();
    char z=q.front()->data.opt;
    q.pop();
    int w=q.front()->data.opd;
    q.pop();
    int res=solve(y,z,w);
    cout<<res<<endl;
    return 0;
}
