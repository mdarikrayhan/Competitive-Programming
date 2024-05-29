// LUOGU_RID: 157371079
#include<bits/stdc++.h>
#define int long long
#define lll __int128
using namespace std;
const int N=210;
const int MOD=1e9+7;

int powM(int a,int b=MOD-2,int mod=MOD){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}

struct CP{
	int x,y;
	CP(int _x=0,int _y=0){x=_x,y=_y;}
	CP operator+(const CP& o){
		return CP((x+o.x)%MOD,(y+o.y)%MOD);
	}
	CP operator+(const int& o){
		return CP((x+o)%MOD,y);
	}
	CP operator-(const CP& o){
		return CP(((x-o.x)%MOD+MOD)%MOD,((y-o.y)%MOD+MOD)%MOD);
	}
	CP operator-(const int& o){
		return CP(((x-o)%MOD+MOD)%MOD,y);
	}
	CP operator*(const CP& o){
		return CP((1ll*x*o.x%MOD+5ll*y%MOD*o.y%MOD)%MOD,(1ll*x*o.y%MOD+1ll*y*o.x%MOD)%MOD);
	}
	CP operator*(const int& o){
		return CP(1ll*x*o%MOD,1ll*y*o%MOD);
	}

 	CP operator/(const CP& o){
 		CP res((1ll*x*o.x%MOD-5ll*y%MOD*o.y%MOD+MOD)%MOD,(-1ll*x*o.y%MOD+1ll*y*o.x%MOD+MOD)%MOD);
 		int t=powM((o.x*o.x%MOD-5ll*o.y%MOD*o.y%MOD+MOD)%MOD);
 		res.x=1ll*res.x*t%MOD,res.y=1ll*res.y*t%MOD;
 		return res;
 	}
 	CP pow(int b){
 		CP ans=CP(1,0);
 		CP a=(*this);
 		while(b){
 			if(b&1)ans=ans*a;
 			a=a*a;
 			b>>=1;
 		}
 		return ans;
 	}
};

int C[N][N],strl[N][N],fac[N],invfac[N];

void ini(){
	C[0][0]=1;
	for(int i=1;i<N;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	strl[0][0]=1;
	for(int i=1;i<N;++i){
		for(int j=1;j<=i;++j)strl[i][j]=(strl[i-1][j-1]-1ll*(i-1)*strl[i-1][j]%MOD+MOD)%MOD;
	}
	fac[0]=1;
	for(int i=1;i<N;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	invfac[N-1]=powM(fac[N-1]);
	for(int i=N-2;i>=0;--i)invfac[i]=1ll*invfac[i+1]*(i+1)%MOD;
}

void llz(){
	int k,l,r;
	cin>>k>>l>>r;
	l+=2,r+=2;
	CP ans=0;
	CP c(0,powM(5));
	CP d(0,MOD-c.y);
	CP a(powM(2),powM(2));
	CP b(a.x,MOD-a.y);
	for(int i=1;i<=k;++i){
		CP res;
		for(int j=0;j<=i;++j){
			CP q=a.pow(j)*b.pow(i-j);
			CP t;
			if(q.x==1&&q.y==0)t=CP((r-l+1)%MOD,0);
			else t=(q.pow(r+1)-q.pow(l))/(q-1);
			t=d.pow(i-j)*t;
			t=c.pow(j)*t;
			t=t*C[i][j];
			res=(res+t);
		}
		res=res*strl[k][i];
		ans=(ans+res);
	}
	ans=ans*invfac[k];
	if(ans.x<0)ans.x+=MOD;
	cout<<ans.x<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ini();
	int T=1;
	while(T--)llz();
	return 0;
}