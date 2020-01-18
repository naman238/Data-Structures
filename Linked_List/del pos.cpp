#include <bits/stdc++.h>
using namespace std;
struct lnode {
    int flag;
    int data;
    struct lnode * next;
};
typedef struct lnode* LPTR;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct lnode* create(int x) {
    LPTR p;
    p=new(struct lnode);
    p->next=NULL;
    p->data=x;
    p->flag=0;
    return p;
}
void add(LPTR &l,int x,int &p) {
    p++;
    if(l==NULL) {
        l=create(x);
    }
    else {
        LPTR temp=l;
        while(temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=create(x);
    }
}
void printlst(LPTR &l) {
    LPTR t=l;
    if(t==NULL)return ;
    else {
        cout<<t->data<<" ";
        printlst(t->next);
    }
}
void del(LPTR &l) {

    if(l->next==NULL && l->flag==1) {
        l=NULL;
    }
    else 
	{
        LPTR t=l;
        if(t->flag==1) {
            l=l->next;
            return ;
        }
        while(t!=NULL && t->next->flag!=1) {
            t=t->next;
        }
        LPTR p=t->next;
        t->next=p->next;
        delete p;
    }
}
void lis(LPTR &l,queue <int> &q) {
    LPTR t=l;
    if(t==NULL)
        return;
    q.push(t->data);
    lis(t->next,q);
}
void delpos(LPTR &l,queue <int> &q,LPTR &z,LPTR a,int p) {
    static int count=0;
    count++;
    static int c=0;
    if(count>=p) {
        while(c--) {
            del(z);
        }
        return ;
    }
    else if(q.front()>count) {
        delpos(l->next,q,z,a,p);				//move from right to left
    }
    else if(q.front()==count) {
        c++;
        l->flag=1;
        count=0;
        q.pop();
        delpos(a,q,z,a,p);
    }
}
int main() {
    LPTR l=NULL;
    int p=0;
    add(l,1,p);
    add(l,2,p);
    add(l,3,p);
    add(l,5,p);
    add(l,7,p);
    add(l,9,p);
    int count=0;
    queue<int> q;
    lis(l,q);
    delpos(l,q,l,l,p);
    printlst(l);
    return 0;
}
