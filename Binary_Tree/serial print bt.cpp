#include <iostream>
using namespace std;
struct btnode {
    btnode * lc;
    char data;
    btnode* rc;
};
typedef btnode* Btptr;
Btptr insert(Btptr &T,string s,int k,int &i) {
    if(i==k-1 || s[i]=='.') {
        return NULL;
    }
    else {
        T=new struct btnode;
        T->data=s[i];
        T->lc=insert(T->lc,s,k,++i);
        T->rc=insert(T->rc,s,k,++i);
        return T;
    }

}
void serial(Btptr T) {
    if(T==NULL) {
        cout<<".";
        return ;
    }
    else {
        cout<<T->data;

        serial(T->lc);
        serial(T->rc);
    }
}


int main() {
    int x;
    string s;
    cin>>s;
    int i=0;
    Btptr T;
    int k=s.length();
    T=insert(T,s,k,i);
    serial(T);

    return 0;
}
