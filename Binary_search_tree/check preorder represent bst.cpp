#include<iostream>
#include<stack>
using namespace std;
struct mdm{
	int min;
	int data;
	int max;
};
int main()
{
	int n;cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	mdm temp;
	temp.min=0;
	temp.data=a[0];
	temp.max=1000;
	stack <mdm> s;
	s.push(temp);
	for(int i=1;i<n;i++)
	{
		temp.data=a[i];
		if(a[i]<s.top().data)
		{
			temp.min=s.top().min;
			temp.max=s.top().data-1;
			if(temp.data<temp.min || temp.data>temp.max)
			{
				cout<<"Not bst";
				return 0;
			}
			s.push(temp);
		}
		else{
			mdm t;
			while(!s.empty() && s.top().max<a[i])
			{
				t=s.top();
				s.pop();
			}
			if(!s.empty())
			{
				t=s.top();s.pop();
			}
			temp.max=t.max;
			temp.min=t.data+1;
			if(temp.data<temp.min || temp.data>temp.max)
			{
				cout<<"Not bst";
				return 0;
			}
			s.push(temp);
		}
	}
	cout<<"Its preorder of bst";
	return 0;
}
