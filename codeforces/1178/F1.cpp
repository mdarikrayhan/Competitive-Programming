#include<bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int>
#define pb push_back
#define fi first
#define se second
#define rd read()
#define Debug(x) (cerr<<x<<endl)

template<int mod>
struct modint
{
	int x;
	modint(int t=0):x( (t%mod+mod)%mod){}
	modint inv() { return (*this)^(mod-2); }
	modint operator +=(modint y) { x=(x+y.x)%mod; return *this; }
	modint operator -=(modint y) { x=(x-y.x+mod)%mod; return *this; }
	modint operator *=(modint y) { x=1ll*x*y.x%mod; return *this;}
	modint operator /=(modint y) { (*this)*=y.inv(); return *this; }
	modint operator ^=(int b)
	{
		modint a=*this;
		(*this)=1;
		while (b) {
			if (b&1) (*this)*=a;
			a*=a,b>>=1;
		}
		return *this;
	}
	friend modint operator +(modint x,modint y) { return x+=y; }
	friend modint operator -(modint x,modint y) { return x-=y; }
	friend modint operator *(modint x,modint y) { return x*=y; }
	friend modint operator /(modint x,modint y) { return x/=y; }
	friend modint operator ^(modint x,int y) { return x^=y; }
	friend istream &operator >>(istream &is,modint &x) { int t; is>>t,x=t; return is; }
	friend ostream &operator <<(ostream &os,modint x) { return os<<x.x; }
};

inline int read(){
	int num=0,sign=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){sign=-1;}ch=getchar();}
	while(isdigit(ch)) num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return num*sign;
}	

const int N=510;

const int mod=998244353;

int n,m,c[N],f[N][N];

void Main(){
	n=rd,m=rd;
	for(int i=1;i<=n;i++)
		c[i]=rd;
	for(int i=1;i<=n+1;i++)
		f[i][i]=f[i][i-1]=1;
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			int s1=0,s2=0,p=0;
			for(int i=l;i<=r;i++)
				if(!p||c[p]>c[i])
					p=i;
//			s1=f[l][p-1];
//			s2=f[p+1][r];
			for(int i=l;i<=p;i++)
				s1=(s1+f[l][i-1]*f[i][p-1]%mod)%mod;
			for(int i=p;i<=r;i++)
				s2=(s2+f[p+1][i]*f[i+1][r]%mod)%mod;
			f[l][r]=s1*s2%mod;
		}
	}
	cout<<f[1][n]<<endl;
}

signed main(){
	int T=1;//rd;
	while(T--) Main();
}

/**
 *　　┏┓　　　┏┓+ +
 *　┏┛┻━━━┛┻┓ + +
 *　┃　　　　　　　┃
 *　┃　　　━　　　┃ ++ + + +
 *  ████━████+
 *  ◥██◤　◥██◤ +
 *　┃　　　┻　　　┃
 *　┃　　　　　　　┃ + +
 *　┗━┓　　　┏━┛
 *　　　┃　　　┃ + + + +Code is far away from 　
 *　　　┃　　　┃ + bug with the animal protecting
 *　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
 *　　　┃ 　　　　　　 ┣┓
 *　　  ┃ 　　　　　 　┏┛
 *　    ┗┓┓┏━┳┓┏┛ + + + +
 *　　　　┃┫┫　┃┫┫
 *　　　　┗┻┛　┗┻┛+ + + +
 */
	 	 	   						 		 		 	 			 	 	