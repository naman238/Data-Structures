#include <iostream>
using namespace std;
struct btnode {
    btnode * lc;
    char data;
    btnode* rc;
};
typedef btnode* Btptr;
void inorder(Btptr T) {
    if(T!=NULL) {
        inorder(T->lc);
        cout<<T->data<<" ";
        inorder(T->rc);
    }
}
Btptr postin(char post[],char in[],int l,int h) {
    static int i=h;
    if(l>h)
        return NULL;
    Btptr T=new btnode;
    T->data=post[i--];
    T->lc=T->rc=NULL;
    if(l==h) {
        return T;
    }
    int j=0;
    while(j<=h && in[j]!=T->data) {
        j++;
    }
    T->rc=postin(post,in,j+1,h);
    T->lc=postin(post,in,l,j-1);
    return T;
}
int main() {
    int n;
    cin>>n;
    char post[n];
    char in[n];
    for(int i=0; i<n; i++) {
        cin>>post[i];
    }

    for(int i=0; i<n; i++) {
        cin>>in[i];
    }
    int y=0;
    Btptr T=postin(post,in,y,n-1);
    cout<<"inorder: ";
    inorder(T);
    cout<<endl;
    return 0;
}
