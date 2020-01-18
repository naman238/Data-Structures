#include <bits/stdc++.h>
using namespace std;
struct btnode {
    btnode*lc;
    int data;
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
void inorder(btptr T,vector<int> &v) {
    if(T!=NULL) {
        inorder(T->lc,v);
        v.push_back(T->data);

        inorder(T->rc,v);
    }
}

void convert(btptr &T,vector<int>v,int &i) {
    if(T!=NULL) {
        convert(T->lc,v,i);
        T->data=v[i++];
        convert(T->rc,v,i);
    }
}

void print_bst(btptr T) {
    if(T!=NULL) {
        print_bst(T->lc);
        cout<<T->data<<" ";
        print_bst(T->rc);
    }
}
int main() {
    int x;
    string s;
    cin>>s;
    int i=0;
    btptr T;
    int k=s.length();
    T=insert(T,s,k,i);
    vector<int> v;
    inorder(T,v);
    sort(v.begin(),v.end());
    int j=0;
    convert(T,v,j);
    print_bst(T);
    return 0;
}
