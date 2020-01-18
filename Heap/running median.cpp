#include<bits/stdc++.h>
using namespace std;
void mnperup(int h[],int& n,int k) {
    int j=n;
    h[n++]=k;

    while(h[j]<h[(j-1)/2]) {
        int temp=h[(j-1)/2];
        h[(j-1)/2]=h[j];
        h[j]=temp;
        j=(j-1)/2;
    }

}
int mn(int y,int a,int b) {
    if(a<b) {
        return (2*y+1);
    }
    else {
        return (2*y+2);
    }
}
void mnperdown(int h[],int &n) {
    int j=0;
    if(n<2) {
        return ;
    }
    else if(n==2) {
        if(h[0]>h[1]) {
            swap(h[0],h[1]);
        }
    }
    else {
        int x=mn(j,h[2*j+1],h[2*j+2]);
        while(2*j+1<n && h[j] > h[x] ) {
            x=mn(j,h[2*j+1],h[2*j+2]);

            swap(h[j],h[x]);
            j=x;
            if(2*j+1>=n)
                break;
            x=mn(j,h[2*j+1],h[2*j+2]);
        }
    }
}

void mxperup(int h[],int& n,int k) {
    int j=n;
    h[n++]=k;

    while(h[j]>h[(j-1)/2]) {
        int temp=h[(j-1)/2];
        h[(j-1)/2]=h[j];
        h[j]=temp;
        j=(j-1)/2;
    }

}
int mx(int y,int a,int b) {
    if(a>b) {
        return (2*y+1);
    }
    else {
        return (2*y+2);
    }
}
void mxperdown(int h[],int &n) {
    int j=0;
    if(n<2) {
        return ;
    }
    else if(n==2) {
        if(h[0]<h[1]) {
            swap(h[0],h[1]);
        }
    }
    else {
        int x=mx(j,h[2*j+1],h[2*j+2]);
        while(2*j+1<n && h[j] < h[x] ) {
            x=mx(j,h[2*j+1],h[2*j+2]);
            swap(h[j],h[x]);
            j=x;
            if(2*j+1>=n)
                break;
            x=mx(j,h[2*j+1],h[2*j+2]);
        }
    }
}

float median=0;
void findmedian(int h1[],int &n1,int h2[],int &n2,int x) {
    if(n1==0 && n2==0) {
        mxperup(h1,n1,x);
        median=x;
    }
    else if(x<=median) {
        if(n1==n2) {
            mxperup(h1,n1,x);
            median=h1[0];
        }
        else if(n1>n2) {
            int y=h1[0];
            h1[0]=x;
            mxperdown(h1,n1);
            mnperup(h2,n2,y);
            median=(h1[0]+h2[0])/2;
        }
    }
    else {
        if(n1==n2) {
            mnperup(h2,n2,x);
            median=h2[0];
        }
        else if(n1<n2) {
            int y=h2[0];
            h2[0]=x;
            mnperdown(h2,n2);
            mxperup(h1,n1,y);
            median=(h1[0]+h2[0])/2;
        }
    }
    cout<<median<<endl;
}

int main() {
    int h1[56];
    int h2[56];
    int x;
    char ch;
    cout<<"wnat to add more(y/n) ";
    cin>>ch;
    int i=0,j=0;
    while(ch=='y')
    {
        cin>>x;
        findmedian(h1,i,h2,j,x);
        cout<<"wnat to add more(y/n) ";
        cin>>ch;
    }
    cout<<endl;
    return 0;
}
