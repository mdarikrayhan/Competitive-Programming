// LUOGU_RID: 160025334
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
int a[N];
void op(int i,int j,int x){
	a[i]-=i*x,a[j]+=i*x;cout<<i<<' '<<j<<' '<<x<<'\n';
}
signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;cin>>T;
	while(T--){
		int n,s=0;cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],s+=a[i];
		if(s%n!=0){cout<<-1<<'\n';continue;}
		s/=n;
		cout<<3*(n-1)<<'\n';
		for(int i=2;i<=n;++i){
			op(1,i,(i-a[i]%i)%i);
			op(i,1,a[i]/i);
		}
		for(int i=2;i<=n;++i)op(1,i,s);
	}
	return 0;
}