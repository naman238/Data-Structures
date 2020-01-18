#include <bits/stdc++.h>
using namespace std;
struct lnode {
    int data;
    int count;
    struct lnode* next[5];
};
typedef struct lnode* LPTR;
LPTR create(LPTR &l,int n) {
    n--;
    if(n==0)
        return NULL;
    else {
        int c,x;
        cout<<"enter element :";
        cin>>x;
        cout<<endl;
        cout<<"enter no. of pointers";
        cin>>c;
        if(l!=NULL) {
            l->data=x;
            l->count=c;
        }
        else {
            l=new struct lnode;
            l->data=x;
            l->count=c;
        }
        if(c==0) {
            for(int i=0; i<5; i++)
                l->next[i]=NULL;
            return l;
        }
        for(int j=0; j<l->count; j++) {
            create(l->next[j],n);
        }
    }
}
void print(vector<int> a) {
    for(int i=0; i<a.size(); i++)
        cout<<a[i]<<" ";
}
void printlst(LPTR l,vector<int> a){
    if(l->count==0) {
    	a.push_back(l->data);
		print(a);    
        return ;
    }
    else {
        a.push_back(l->data);
        for(int i=0; i<l->count; i++) 
		{
            printlst(l->next[i],a);
        }
    }
}
typedef struct lnode* LPTR;
int main() {
    int n;
    cout<<"enter total no. of elements: ";
    cin>>n;
    cout<<endl;
    vector<int>a;
    LPTR l=new struct lnode;
    l->data=-1;
    l->count=1;
    for(int i=0; i<5; i++) {
        l->next[i]=NULL;
    }
    LPTR p=create(l,n+1);
    LPTR temp=l;
    printlst(temp,a);
    return 0;
}
