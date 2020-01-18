#include <iostream>
using namespace std;
struct btnode {
    btnode * lc;
    char data;
    btnode* rc;
};
typedef btnode* Btptr;
Btptr prein(char pre[],char in[],int l,int h) {
    static int i=0;
    if(l>h)
        return NULL;
    Btptr T=new btnode;
    T->data=pre[i++];
    T->lc=T->rc=NULL;
    if(l==h) {
        return T;
    }
    int j=0;
    while(j<=h && in[j]!=T->data) {
        j++;
    }

    T->lc=prein(pre,in,l,j-1);
    T->rc=prein(pre,in,j+1,h);
    return T;
}
string p="";
void convert(Btptr T) {
    if(T!=NULL) {
        p+=T->data;
        if(T->lc==NULL) {
            p+="()";
        }
        else if(T->lc!=NULL) {
            p+='(';
            convert(T->lc);
            p+=')';
        }
        if(T->rc!=NULL) {
            p+='(';
            convert(T->rc);
            p+=')';
        }
    }
}
int main() {
    int n;
    cin>>n;
    char pre[n];
    char in[n];
    for(int i=0; i<n; i++) {
        cin>>pre[i];
    }
    for(int i=0; i<n; i++) {
        cin>>in[i];
    }
    int y=0;
    Btptr T=prein(pre,in,y,n-1);
    convert(T);
    cout<<p<<endl;
    return 0;
}
