#include <bits/stdc++.h>
using namespace std;
struct btnode {
    btnode*lc;
    int data;
    int hd;
    btnode*rc;
};
typedef btnode* btptr;

btptr insert(btptr & T,string s,int k,int&i) {
    if(i==k-1 || s[i]=='.') {
        return NULL;
    }
    else {
        T=new btnode;
        T->data=s[i]-'0';
        T->lc=insert(T->lc,s,k,++i);
        T->rc=insert(T->rc,s,k,++i);
        return T;
    }
}
int mn=1;
void hdcal(btptr &T,int h) {
    if(T!=NULL) {
        T->hd=h;

        hdcal(T->lc,h-1);
        hdcal(T->rc,h+1);
    }
}
int mx=-1;
vector<btptr> v;
vector<btptr>::iterator it;
void print_botview(btptr T) {
    if(T!=NULL) {

        if(T->hd<mn)
        {
            mn=T->hd;
        }
        else if(T->hd>mx)
        {
            mx=T->hd;
        }
        v.push_back(T);
        print_botview(T->lc);
        print_botview(T->rc);
    }
}
int m=0;
void leftview(btptr T,int level) {
    if(T==NULL) {
        return ;
    }
    else if(level>m) {
        for(int i=0; i<v.size(); i++) {
            if(v[i]==T)
            {
                it=v.begin()+i-1;
                v.erase(it);
                break;
            }
        }
        m=level;
    }
    leftview(T->lc,level+1);
    leftview(T->rc,level+1);

}
void rightview(btptr T,int level) {
    if(T==NULL) {
        return ;
    }
    else if(level>m) {
        for(int i=0; i<v.size(); i++) {
            if(v[i]==T)
            {
                it=v.begin()+i-1;
                v.erase(it);
                break;

            }
        }
        m=level;
    }
    rightview(T->rc,level+1);
    rightview(T->lc,level+1);
}
int main() {
    int x=0;
    string s;
    cin>>s;
    int i=0;
    btptr T;
    int k=s.length();
    T=insert(T,s,k,i);
    hdcal(T,x);
    int flag=0;
    print_botview(T);
    int y=1;

    leftview(T,y);
    rightview(T,y);
    int sum=0;

    vector<btptr>::iterator it;
    for(int j=mn; j<=mx; j++) {
        int count=0;
        for(int i=0; i<v.size(); i++) {
            if(v[i]->hd==j)
            {   count++;
            }
        }
        if(count==1 || j>0)
        {   for(int i=0; i<v.size(); i++) {
                if(v[i]->hd==j) {
                    it=v.begin()+i;
                    v.erase(it);
                    break;
                }
            }
        }
        else {
            for(int i=v.size()-1; i>=0; i--) {
                if(v[i]->hd==j) {
                    it=v.begin()+i;
                    v.erase(it);
                    break;
                }
            }
        }
    }

    for(int i=0; i<v.size(); i++) {
        cout<<v[i]->data<<" ";
    }

    return 0;
}
