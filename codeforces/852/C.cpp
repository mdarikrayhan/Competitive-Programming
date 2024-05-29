// LUOGU_RID: 157052356
#include<bits/stdc++.h>
using namespace std;
int n,a[50005],ans[50005];
pair<int,int>b[50005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]={a[i]+a[i-1],i-1};
	b[1]={a[1]+a[n],n},sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		ans[b[i].second]=i-1;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}