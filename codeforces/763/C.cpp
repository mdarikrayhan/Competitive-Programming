// LUOGU_RID: 158324947
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;

int a[N],b[N];
map<int,bool> mm;

int powM(int a,int b,int mod){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}

void llz(){
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=n;++i)cin>>a[i],mm[a[i]]=true;
	//for(auto v:mm)cout<<v.first<<" "<<v.second<<"\n";
	if(n==m){
		cout<<0<<" "<<1<<"\n";
		return;
	}
	if(n==m-1){
		for(int i=0;i<m;++i){
			if(!mm[i]){
				cout<<(i+1)%m<<" "<<1<<"\n";
				return;
			}
		}
	}
	sort(a+1,a+1+n);
	bool ch=false;
	if(2*n>m){
		ch=true;
		int t=0;
		for(int i=0;i<m;++i){
			if(!mm[i])b[++t]=i;
		}
		mm.clear();
		for(int i=1;i<=t;++i)a[i]=b[i],mm[a[i]]=true;
		n=t;
	}
	int d,s;
	if(n==1){
		s=a[1],d=0;
	}
	else{
		d=a[2]-a[1];
		int cnt=0;
		for(int i=1;i<=n;++i){
			//cout<<(a[i]+d)%m<<"\n";
			if(mm[(a[i]+d)%m])cnt++;
		}
		cnt=n-cnt;
		d=1ll*d*powM(cnt,m-2,m)%m;
		s=-1;
		for(int i=1;i<=n;++i){
			if(!mm[(a[i]-d+m)%m]){
				if(s!=-1){
					cout<<-1<<"\n";
					return;
				}
				s=a[i];
			}
		}
	}
	//cout<<s<<" "<<d<<"\n";
	if(ch)s=(s+n*d%m)%m;
	if(s<0)s+=m;
	cout<<s<<" "<<d<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)llz();
	return 0;
}