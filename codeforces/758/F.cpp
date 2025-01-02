// LUOGU_RID: 158410664
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;

inline int gcd(int a, int b){
    register int az=__builtin_ctz(a),bz=__builtin_ctz(b),z=az>bz?bz:az,diff;
    b>>=bz;
    while(a)
    {
        a>>=az;
        diff=b-a;
        az=__builtin_ctz(diff);
        if(a<b)b=a;
        a=diff<0?-diff:diff;
    }
    return b<<z;
}

int powM(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a;
		a=1ll*a*a;
		b>>=1;
	}
	return ans;
}

void llz(){
	int n,L,R;
	cin>>n>>L>>R;
	if(n==1){cout<<R-L+1<<"\n";return;}
	if(n==2){cout<<(R-L+1)*(R-L)<<"\n";return;}
	int lim=pow(R,(long double)1/(n-1))+1;
	if(n-1>=40)lim=1;
	int ans=0;
	for(int y=1;y<=lim;++y){
		for(int x=y+1;x<=lim;++x){
			if(gcd(x,y)!=1)continue;
			int yn=powM(y,n-1),xn=powM(x,n-1);
			int l=(L+yn-1)/yn,r=R/xn;
			ans+=max(0ll,r-l+1);
		}
	}
	cout<<ans*2<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)llz();
	return 0;
}