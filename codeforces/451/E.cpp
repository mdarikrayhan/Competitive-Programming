// LUOGU_RID: 160247900
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

const int N=20,mod=1e9+7;
int a[N],n,m;

int qmi(int a,int b,int p){
	a%=p;
	int res=1;
	while(b){
		if(b&1){
			res=res*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return res;
}

int C(int a,int b){
	if(a<b){
		return 0;
	}
	int up=1,down=1;
	for(int i=a;i>a-b;--i){
		up=i%mod*up%mod;
	}
	for(int i=1;i<=b;++i){
		down=i%mod*down%mod;
	}
	return up*qmi(down,mod-2,mod);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	int res=0;
	for(int i=0;i<1<<n;++i){
		int sign=1,x=m+n-1,y=n-1;
		for(int j=0;j<n;++j){
			if(i>>j&1){
				sign*=-1;
				x-=a[j]+1;
			}
		}
		res=(res+C(x,y)*sign)%mod;
	}
	cout<<(res+mod)%mod;
	return 0;
}