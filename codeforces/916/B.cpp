// LUOGU_RID: 160396702
#include<bits/stdc++.h> 
#define int long long
using namespace std;
signed main(){
	priority_queue<int> a,b;
	int n,k;
	cin>>n>>k;
	for(int i=62;i>=0;i--){
		if(n&(1ll<<i)) a.push(i);
	}
	b=a;
	int tk=k-a.size();
	if(tk<0){
		cout<<"No";
		return 0;
	}
	cout<<"Yes\n";
	for(int i=1;i<=tk;i++){
		int t=a.top();
		a.pop();
		t--;
		a.push(t);
		a.push(t);
	}
	int tmp=a.top();
	while(b.top()>tmp){
		int t=b.top();
		b.pop();
		t--;
		b.push(t);
		b.push(t);
	}
	while(b.size()>1){
		cout<<b.top()<<" ";
		b.pop();
		k--;
	}
	for(int i=1;i<k;i++) cout<<b.top()-i<<" ";
	cout<<b.top()-k+1;
	return 0;
}//不要UKE让我过
//谢谢