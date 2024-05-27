// LUOGU_RID: 158690353
#include<bits/stdc++.h>
using namespace std;
int n,k,now=0,a[2000005];
map<int,int>m;
int main(){
	long long ans=0;
	cin>>n>>k;m[0]=1;int hu=(1<<k)-1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		now=now^a[i];
		int ans1=now^hu;
		if(m[now]<m[ans1]){
			ans+=(m[now]++);
		}
		else{
			ans+=(m[ans1]++);now=ans1;
		}
	}
	cout<<1ll*n*(n+1)/2-ans;
	return 0;
}