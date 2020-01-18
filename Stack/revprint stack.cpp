#include <bits/stdc++.h>
using namespace std;
void revprint(stack<int> s){
if(s.empty()){
return ;
}
else{
	int p=s.top();
	s.pop();
	revprint(s);
	cout<<p<<" ";
	return;
}
}
int main(){
	stack<int>s;
	s.push(3);
	s.push(7);
	s.push(8);
	s.push(2);
	revprint(s);
	return 0;
}
