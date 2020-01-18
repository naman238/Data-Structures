#include <iostream>
using namespace std;
struct btnode {
    btnode * lc;
    int data;
    btnode* rc;
};
typedef btnode* Btptr;
//Btptr T=NULL;



Btptr prein(int pre[],int in[],int l,int h) {
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

void inorder(Btptr T,int a[],int n) {
    static int i=0;
    if(T!=NULL) {
        inorder(T->lc,a,n);
        a[i]=T->data;
        i=i+1;
        inorder(T->rc,a,n);
    }
}
void ino(Btptr T) {

    if(T!=NULL) {
        ino(T->lc);
        cout<<T->data<<" ";
        ino(T->rc);
    }
}


int main() {
    int n;
    cin>>n;
    int pre[n];
    int in[n];
    for(int i=0; i<n; i++) {
        cin>>pre[i];
    }

    for(int i=0; i<n; i++) {
        cin>>in[i];
    }
    int z=0;
    Btptr T=prein(pre,in,z,n-1);
    int a[n];
    inorder(T,a,n);
    int count=0;
    int x,y;
    int i=0,j=0;
    int flag=0;
    for(int i=0; i<n-1; i++) {
        int mn=a[i];
        for(int j=i+1; j<n; j++) {
            if(mn>a[j]) {
                mn=a[j];
                x=j;
                flag=1;
            }
        }

        if(flag==1)
        {
            int temp=a[i];
            a[i]=a[x];
            a[x]=temp;
            count++;
        }
        flag=0;
    }
    cout<<count<<endl;

    return 0;
}

