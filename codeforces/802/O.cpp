// LUOGU_RID: 160525640
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
const int N=5e5+5;
int n,k;
int a[N],b[N];
int b0;
int cnt;
int check(int mid){
	b0=0;
	cnt=0;
	priority_queue<pii> q;//a 
	for(int i=1;i<=n;i++) a[i]-=mid,b[i]-=mid;
	for(int i=1;i<=n;i++){
	 	q.push({-a[i],1});
	 	if(b[i]-q.top().first<=0){
	 		cnt+=q.top().second;
	 		b0+=b[i]-q.top().first;
	 		q.pop();
	 		q.push({b[i],0});
		}
	}
	for(int i=1;i<=n;i++) a[i]+=mid,b[i]+=mid;
//	cout<<mid<<" "<<cnt<<' '<<b0<<'\n';
	return cnt;
}
void search(){
	int low=0,high=2e9;
	int k0;
	while(low<=high){
		int mid=(low+high)>>1;
		if(check(mid)>=k){
			k0=mid;
			high=mid-1;
		}
		else low=mid+1;
	}
	check(k0);
	cout<<2*k0*k+b0;
}
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	search();
	return 0;
}