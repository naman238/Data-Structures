#include <iostream>
using namespace std;
struct btnode {
    btnode * lc;
    int data;
    btnode* rc;
};
typedef btnode* Btptr;
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
bool left,mid,right;
bool srch(Btptr T,int k) {
    if(T!=NULL) {
        if(T->data==k) {
            return true;
        }
        else {
            return (srch(T->lc,k)||srch(T->rc,k));
        }
    }
    else {
        return false;
    }
}
int lcabt(Btptr T,int k1,int k2) {
    if(T!=NULL) 
	{
        if(T->data==k1||T->data==k2) {
            mid=true;
            if(T->data==k1)
            {
                if(srch(T->lc,k2)||srch(T->rc,k2)) {
                    return T->data;
                }
            }
            else {
                if(srch(T->lc,k1)||srch(T->rc,k1)) {
                    return T->data;
                }
            }
        }
        else if((srch(T->lc,k1)&&srch(T->rc,k2)) || (srch(T->lc,k2)&&srch(T->rc,k1)))
        {
            return T->data;
        }
        else if(srch(T->rc,k1)&&srch(T->rc,k2)) {
            return lcabt(T->rc,k1,k2);
        }
        else {
            return lcabt(T->lc,k1,k2);
        }
    }
    else 
		return 0;
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
    int x,y;
    cin>>x>>y;
    int lca=lcabt(T,x,y);
    cout<<lca<<endl;
    return 0;
}
