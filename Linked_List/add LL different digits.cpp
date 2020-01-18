#include <iostream>
using namespace std;
struct lnode {
    int data;
    struct lnode*next;
};
typedef struct lnode* LPTR;
LPTR create(int x) {
    LPTR t=new struct lnode;
    t->data=x;
    t->next=NULL;
    return t;
}
void add(LPTR &l,intx,stack<int> &s) {
    LPTR t=l;
    if(l==NULL) {
        l=create(x);
        s.push(l->data);
        return ;
    }
    else {
        while(t->next!=NULL)
            t=t->next;
        t->next=create(x);
        s.push(t->next->data);
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
        return;
    }
}
void addLL(stack<int>s1,stack<int>s2,LPTR &l3) {
    int carry=0;
    int a;
    while(!s1.empty()&&!s2.empty()) {
        a=s1.top()+s2.top()+carry;
        if(a<10) {
            addfront(l3,a);
        }
        else {
            carry=(a)/10;
            addfront(a%10);
        }
        s1.pop();
        s2.pop();
    }
    while(!s1.empty()) {
        a=s1.top()+carry;
        if(a<10) {
            addfront(l3,a);
        }
        else {
            carry=(a)/10;
            addfront(a%10);
        }
        s1.pop();
    }
}

int main() {
    LPTR l1=NULL,l2=NULL;
    stack <int>s1,s2;
    add(l1,7,s1);
    add(l1,5,s1);
    add(l1,9,s1);
    add(l1,4,s1);
    add(l1,6,s1);
    add(l2,8,s2);
    add(l2,4,s2);
    LPTR l3=NULL;
    addLL(s1,s2,l3);
    printlst(l3);
    return 0;
}
