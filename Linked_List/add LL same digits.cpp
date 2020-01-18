#include <iostream>
#include <stack>
using namespace std;
struct pnode {
    int data;
    struct pnode * next;
};

typedef struct pnode* LPTR;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct pnode* create(int x) {
    LPTR p;
    p=new(struct pnode);
    p->next=NULL;
    p->data=x;
    return p;
}
void add(LPTR &l,int x) {
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
void addfront(LPTR &l,int x) {

    if(l==NULL) {
        l=create(x);
        return;
    }
    else {
        LPTR t=create(x);
        t->next=l;
        l=t;
    }


}
LPTR add1(LPTR &l,LPTR &l1,stack<LPTR> s1,stack<LPTR> s2) 
{
    LPTR temp1=l;
    LPTR temp2=l1;
    LPTR res=NULL;
    while(temp1!=NULL) {
        s1.push(temp1);
        s2.push(temp2);
        temp1=temp1->next;
        temp2=temp2->next;
    }
    int carry=0;
    LPTR x,y;
    int a;
    while(s1.size()!=1) {
        x=s1.top();
        y=s2.top();
        a=x->data+y->data+carry;
        if(a<10) {
            addfront(res,a);
        }
        else {
            carry=(a%100)/10;
            addfront(res,a%10);
        }
        s1.pop();
        s2.pop();
    }
    x=s1.top();
    y=s2.top();
    a=x->data+y->data+carry;
    if(a<10) {
        addfront(res,a);
        return res;
    }
    else {
        carry=(a%100)/10;
        addfront(res,a%10);
        addfront(res,carry);
    }

    return res;
}
void printlst(LPTR &l) {
    LPTR t=l;
    if(t==NULL)return ;
    else {
        cout<<t->data<<" ";
        printlst(t->next);
    }
}

int main() {
    LPTR l=NULL;
    add(l,5);
    add(l,4);
    add(l,6);
    LPTR l1=NULL;
    add(l1,8);
    add(l1,4);
    add(l1,2);

    stack<LPTR>s1;
    stack<LPTR>s2;
    LPTR l3=add1(l,l1,s1,s2);
    printlst(l3);
    return 0;
}
