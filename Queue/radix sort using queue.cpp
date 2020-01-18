#include <bits/stdc++.h>
using namespace std;
struct que{
	int size;
	int elements[50];
	int f;
	int r;
};
void enque(struct que &q,int x){
	if((q.r+1)%q.size==q.f){
		cout<<"full";
	}
	else{
		if(q.f==-1){
			q.f=0;
		}
		q.r=(q.r+1)%q.size;
		q.elements[q.r]=x;
	}	
}
int dque(struct que &q){
	if(q.f==-1){
		cout<<"empty";
		return -1;
	}
	else{
		int t=q.elements[q.f];
		if(q.r==q.f){
			q.f=-1;
			q.r=-1;
		}
		else{
		
		
		q.f=(q.f+1)%q.size;}
		return t;	
	}
}
void func(struct que q[],int a[],int n){
	int i=0;
	for(int y=0;y<n;){
		
		while(q[i].f!=-1){
			
			a[y]=dque(q[i]);
			
			//c[y]=z/pow(10,1);
			y++;
		}
		i++;
	}
}
int main() {
	struct que q[10];
	for(int i=0;i<10;i++){
	q[i].f=-1;
	q[i].r=-1;
	q[i].size=100;
	}
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	cin>>a[i];
	}	
int max=a[0];
for(int i=1;i<n;i++){
	if(max<a[i]){
		max=a[i];
	}
}
int d=0;
while(max>0){
	d++;
	max=max/10;
}
for(int j=1;j<=d;j++){
	for(int i=0;i<n;i++){
	    int z=pow(10,j);
	    int y=a[i]%z;
		int x=y/pow(10,j-1);
		enque(q[x],a[i]);
	}
	func(q,a,n);
}
for(int i=0;i<n;i++){
	cout<<a[i]<<" ";
}
	return 0;
}
