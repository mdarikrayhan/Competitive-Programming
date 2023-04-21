#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,Inf=1e18;
int n,k,l[N],r[N];
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int res=0;
		for(int i=1;i<=n;++i)cin>>l[i];
		for(int i=1;i<=n;++i)cin>>r[i],res+=r[i]-l[i]+1;
		if(res<k){cout<<"-1\n";continue;}
		if(!k){cout<<"0\n";continue;}
		int s=0,cnt=0,ans=Inf;
		priority_queue<int,vector<int>,greater<int>>q;
		for(int i=1;i<=n;++i){
			s+=r[i]-l[i]+1,++cnt,q.push(r[i]-l[i]+1);
			if(s>=k){
				while(s-q.top()>=k)ans=min(ans,r[i]-(s-k)+cnt*2),--cnt,s-=q.top(),q.pop();
				ans=min(ans,r[i]-(s-k)+cnt*2);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}