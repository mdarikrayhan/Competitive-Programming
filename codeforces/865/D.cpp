// LUOGU_RID: 160143848
#include<bits/stdc++.h>
using namespace std;
long long ans;
priority_queue<int,vector<int>,greater<int> > q;
int main() {
	int n,p[300010];
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>p[i];
	}
	for(int i=1; i<=n; i++) {
		if(!q.empty()&&q.top()<p[i]) {
			ans+=(p[i]-q.top());
			q.pop();
			q.push(p[i]);
		}
		q.push(p[i]);
	}
	cout<<ans;
	return 0;
}