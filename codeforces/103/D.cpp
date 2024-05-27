// LUOGU_RID: 158873576
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long ;
using ld=long double;
const int N=3e5+10;
const int mod=1e9+7;
i64 s[N];
int a[N];
struct ll{
	int l,k,num;
};
ll b[N];
i64 ans[N];
void solve(){
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i].l>>b[i].k;
		b[i].num=i;
	}
	sort(b+1,b+1+m,[&](ll a,ll b){
		return a.k<b.k;
	});
	int u=sqrt(n)+1;
	int now=0;
	for(int i=1;i<=m;i++){
		if(b[i].k>u){
			i64 res=0;
			for(int j=b[i].l;j<=n;j+=b[i].k) res+=a[j];
			ans[b[i].num]=res;
		}else{
			if(now!=b[i].k){
				for(int j=n;j>=1;j--){
					s[j]=a[j];
					if(j+b[i].k<=n) s[j]+=s[j+b[i].k];
				}
			}
			ans[b[i].num]=s[b[i].l];
		}
		
		now=b[i].k;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	//	cin>>t;
	while(t--) solve();
	return 0;
}