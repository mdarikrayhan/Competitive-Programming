// LUOGU_RID: 158448834
#include<bits/stdc++.h>
#define int long long
#define lll long long
using namespace std;
const int N=2e5+10;

array<int,3> rec[N];
map<int,bool> mm1,mm2;
int b[N];

int lcm(int x,int y){return x/__gcd(x,y)*y;}

void llz(){
	int n;
	cin>>n;
	int k1=0,k2=0;
	for(int i=1;i<=n;++i){
		cin>>rec[i][0]>>rec[i][1]>>rec[i][2];
		if(!mm1[rec[i][0]])k1++;
		mm1[rec[i][0]]=true;
		if(!mm2[rec[i][1]])k2++;
		mm2[rec[i][1]]=true;
	}
	if(k1*k2!=n){
		cout<<0<<"\n";
		return;
	}
	sort(rec+1,rec+1+n,[&](const array<int,3>& x,const array<int,3>& y){
		if(x[0]==y[0])return x[1]<y[1];
		return x[0]<y[0];
	});
	int lca=1;
	for(int i=2;i<=k2;++i){
		int t=rec[1][2];
		t/=__gcd(rec[i][2],rec[1][2]);
		lca=lcm(lca,t);
		for(int j=2;j<=k1;++j){
			int id=(j-1)*k2+i;
			int s=(j-1)*k2+1;
			if((lll)rec[i][2]*rec[s][2]!=(lll)rec[id][2]*rec[1][2]){
				cout<<0<<"\n";
				return;
			}
		}
	}
	sort(rec+1,rec+1+n,[&](const array<int,3>& x,const array<int,3>& y){
		if(x[1]==y[1])return x[0]<y[0];
		return x[1]<y[1];
	});
	int lcb=1;
	for(int i=2;i<=k1;++i){
		int t=rec[1][2];
		t/=__gcd(rec[i][2],rec[1][2]);
		lcb=lcm(lcb,t);
		for(int j=2;j<=k2;++j){
			int id=(j-1)*k1+i;
			int s=(j-1)*k1+1;
			if((lll)rec[i][2]*rec[s][2]!=(lll)rec[id][2]*rec[1][2]){
				cout<<0<<"\n";
				return;
			}
		}
	}
	int t=rec[1][2];
	int ans=0;
	for(int d=1;d*d<=t;++d){
		if(t%d==0){
			int a=d,b=t/d;
			if(a%lca==0&&b%lcb==0)ans++;
			if(d*d!=t){
				a=t/d,b=d;
				if(a%lca==0&&b%lcb==0)ans++;
			}
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)llz();
	return 0;
}