#include<bits/stdc++.h>
using namespace std;
void perup(int h[],int& n,int k) {
    int j=n;
    h[n++]=k;

    while(h[j]<h[(j-1)/2]) {
        int temp=h[(j-1)/2];
        h[(j-1)/2]=h[j];
        h[j]=temp;
        j=(j-1)/2;
    }

}
int main() {

    int h[56];
    int x;
    char ch;
    cout<<"wnat to add more(y/n) ";
    cin>>ch;
    int i=0;
    while(ch=='y')
    {
        cin>>x;
        perup(h,i,x);
        cout<<"wnat to add more(y/n) ";
        cin>>ch;
    }
    for(int j=0; j<i; j++) {
        cout<<h[j]<<" ";
    }
    cout<<endl;
    return 0;
}
