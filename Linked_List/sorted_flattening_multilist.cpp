#include<iostream>
using namespace std;
struct lnode
{
    int data;
    struct lnode* dlink;
    struct lnode* next;
};
typedef struct lnode* LPTR;
struct lnode* create(int a[],int i)
{   LPTR t=new struct lnode;
    t->data=a[i];
    t->dlink=NULL;
    t->next=NULL;
    return t;
}
void adwn(LPTR &temp,int a[],int i) {
    LPTR t=temp;
    cin>>a[i];
    if(t==NULL) {
        temp=create(a,i);
    }
    else {

        while(t->dlink!=NULL) {
            t=t->dlink;
        }
        t->dlink=create(a,i);
    }
}
void adrt(LPTR &temp,int a[],int i) {
    cin>>a[i];
    LPTR t=temp;
    if(t==NULL)
    {
        temp=create(a,i);
    }
    else {

        while(t->next!=NULL) {
            t=t->next;
        }
        t->next=create(a,i);
    }
}
void printlst(LPTR l) {
    if(l==NULL)
        return;
    else {
        cout<<l->data<<" ";
        printlst(l->next);
    }
}
int main()
{   LPTR l=NULL;
    int n;
    cin>>n;
    int a[n];
    cin>>a[0];
    l=create(a,0);
    LPTR temp=l;
    int i=1;
    int p;
    while(i<n) {
        cout<<"press 0 to add down and 1 to add right ";
        cin>>p;
        if(p==0) {
            adwn(temp,a,i);
        }
        else {
            adrt(temp->next,a,i);
            temp=temp->next;
        }
        i++;
    }
    LPTR p1=l;
    LPTR q=p1;
    LPTR prev=NULL;
    while(p1!=NULL) {
        while(q->dlink!=NULL) {
            LPTR t=p1;
            while(t!=NULL && t->data<=q->dlink->data)
            {
                prev=t;
                t=t->next;
            }
            prev->next=q->dlink;
            q->dlink->next=t;
            q=q->dlink;
        }
        q=p1->next;
        p1=p1->next;
    }
    printlst(l);
    cout<<endl;
    return 0;
}
