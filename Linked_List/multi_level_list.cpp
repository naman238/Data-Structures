#include<iostream>
using namespace std;
struct lnode;
union u {
    char c;
    struct lnode* link;
};
struct lnode
{
    int flag;
    union u u1;
    struct lnode* next;
};
typedef struct lnode* LPTR;
int i=0;
struct lnode* create(string s,int i)
{
    
}
void printlst(LPTR &l) {
    if(l==NULL) {
        return;
    }
    else 
	{
        if(l->flag==0) {
            cout<<l->u1.c<<" ";
            printlst(l->next);
        }
        else if(l->flag==1) {
            printlst(l->u1.link);
            printlst(l->next);
        }
    }
}
int main()
{
    string s;
    cin>>s;
    LPTR l=create(s,1);
    printlst(l);
    cout<<endl;
    return 0;
}
