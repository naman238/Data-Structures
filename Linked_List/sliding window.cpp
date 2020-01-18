#include <bits/stdc++.h>
using namespace std;
void findmax(int a[],int n,int k,stack<int> s) {
    int i=0,p=k;
    int j=0;
    for(int i=0; i<=n-k; i++) {
        int j=i;
        for(int p=k; p>=1; p--) {
            if(p==k) {
                s.push(a[j]);
            }
            else if(s.top()<a[j]) {
                s.pop();
                s.push(a[j]);
            }
            j++;
        }
        a[i]=s.top();
    }
}
int main() {
    int n,k;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cin>>k;
    stack<int> s;
    findmax(a,n,k,s);
    for(int i=0; i<=n-k; i++)
        cout<<a[i]<<" ";
    return 0;
}

