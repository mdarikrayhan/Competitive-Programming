// LUOGU_RID: 159735415
#include <bits/stdc++.h>
#define i32 int
#define i64 long long
#define i128 __int128
#define u64 unsigned long long
using namespace std;
const i64 mod = 998'244'353;
const i32 maxn = 2e5+100;
const i32 inf = 0x7fffffff;


i32 n,Q;
i64 a[maxn],p[maxn]={inf},sum;

void Main(){
	cin>>n>>Q;
	for(int i=1;i<=n;++i) cin >> a[i],sum+=a[i]-(i-1);
	sort(a+1,a+n+1);
	
	p[1]=a[1]-0;
	for(int i=2;i<=n;++i){
		p[i]=min(p[i-1],a[i]-(i-1));
	}
	
	
	while(Q--){
		int k;cin>>k;
		if(k<n) cout<<min(p[k]+k,a[k+1])<<' ';
		else if((k+n)%2==1){
			i64 MIN=min(p[n-1],a[n]-k);
			i64 s=sum+(n-1)-k-MIN*n;
			cout<<MIN+k-(i64)ceil(max(0.0,((k-n+1)/2-s)*1.0/n))<<' ';
		}else{
			i64 s=sum-p[n]*n;
			cout<<p[n]+k-(i64)ceil(max(0.0,((k-n  )/2-s)*1.0/n))<<' ';
		}
	}
}
main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--){
		Main();
	}
}