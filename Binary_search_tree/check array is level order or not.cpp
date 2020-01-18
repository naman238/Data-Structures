#include <bits/stdc++.h>
using namespace std;
struct qnode {
    int min;
    int max;
    int data;
};
typedef qnode* qptr;
queue<qptr> q;
void cr(int a[],int n) {
    int i=0;
    if(q.empty()) {
        qptr t=new qnode;
        t->data=a[i];
        t->max=1000;
        t->min=0;
        q.push(t);
        i++;
    }
    while(i<n && !q.empty()) {
        if(q.front()->data>a[i] && a[i]>=q.front()->min) {
            qptr t=new qnode;
            t->data=a[i];
            t->max=q.front()->data-1;
            t->min=q.front()->min;
            q.push(t);
            i++;
        }
        if(q.front()->data<a[i] && a[i]<=q.front()->max) {
            qptr t=new qnode;
            t->data=a[i];
            t->max=q.front()->max;
            t->min=q.front()->data+1;
            q.push(t);
            i++;
        }
        q.pop();
    }
    if(i==n) {
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cr(a,n);
	return 0;
}
