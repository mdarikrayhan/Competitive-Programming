// LUOGU_RID: 160532168
//File uses UTF-8 encoding.
//By: Luogu@tzl_Dedicatus545(UID:308854) Yuanshen@tzl_Dedicatus(UID:273152640)
//Ayaka bless me!
#pragma GCC optimize(3)
#pragma GCC target("tune=native")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,x,y,z) for(int i=(x);i<=(y);i+=(z))
#define per(i,x,y,z) for(int i=(x);i>=(y);i-=(z))
#define pb push_back
#define pii pair<int,int>
#define i128 __int128
#define _1 first
#define _2 second
#define ld long double
#define cint const int
#define pcnt __builtin_popcountll
#define vint vector<int>
#define vpii vector<pair<int,int> >
using namespace std;

const int inf=(sizeof(int)==4?0x3f3f3f3f:0x3f3f3f3f3f3f3f3f);
const int mod=998244353;
const long double EPS=1e-7;
const int maxn=2.02e6;
int gcd(int a,int b){
	unsigned az=__builtin_ctz(a),bz=__builtin_ctz(b);unsigned z=min(az,bz);b>>=bz;
	while(a){	a>>=az;int d=a-b;az=__builtin_ctz(d),b=min(a,b),a=(d<0?-d:d);}
	return b<<z;
}
int read()
{
	int ch = getchar(), t = 1, n = 0;
	while (ch < '0' || ch > '9') { if (ch == '-') t = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { n = n * 10 + ch - '0', ch = getchar(); }
	return n * t;
}void chkmin(int &x,int y){	x=min(x,y);}void chkmax(int &x,int y){	x=max(x,y);}
bool Mbe;
pii operator+(const pii &x,const pii &y){return {x._1+y._1,x._2+y._2};}
pii operator%(const pii &x,const int &y){return {x._1%y,x._2%y};};
pii operator*(const pii &x,const int &y){return {x._1*y,x._2*y};};
void inc(int &x,int y){	x=(x+y>mod?x+y-mod:x+y);}
void dec(int &x,int y){	x=(x-y<0?x-y+mod:x-y);}
int mul(vint vec){int ans=1;for(auto x:vec)	ans*=x,ans%=mod;return ans;}

int sa[maxn],rk[maxn],buc[maxn],id[maxn],tmp[maxn];
int ht[maxn];
void build(const string &s,int n){
	int ma='z'-'a'+1;
	rep(i,1,n,1)	buc[rk[i]=(s[i]-'a'+1)]++;
	rep(i,1,ma,1)	buc[i]+=buc[i-1];
	per(i,n,1,1)	sa[buc[rk[i]]--]=i;
	for(int w=1;;w<<=1){
		int p=0;
		rep(i,n-w+1,n,1)	id[++p]=i;
		rep(i,1,n,1)	if(sa[i]>w)	id[++p]=sa[i]-w;
		memset(buc,0,sizeof(int)*(ma+5));
		memcpy(tmp,rk,sizeof(int)*(n+1));
		rep(i,1,n,1)	buc[rk[i]]++;
		rep(i,1,ma,1)	buc[i]+=buc[i-1];
		per(i,n,1,1)	sa[buc[rk[id[i]]]--]=id[i];
		p=0;
		rep(i,1,n,1)	rk[sa[i]]=(tmp[sa[i-1]]==tmp[sa[i]] && tmp[sa[i-1]+w]==tmp[sa[i]+w]?p:++p);
		ma=p;
		if(p==n)	break ;
	}
	int k=0;
	rep(i,1,n,1){
		if(k)	k--;
		while(i+k<=n && sa[rk[i]-1]+k<=n && s[i+k]==s[sa[rk[i]-1]+k])	k++;
		ht[rk[i]]=k;
	}
}

int lma[maxn],rma[maxn];
int st[maxn][19];
int x[maxn],y[maxn];
int lg2[maxn];
bool ha[maxn];
int w[maxn],c[maxn]; 
set<int> s;int n;
bool Med;
int qmin(int tx,int ty){	return min(st[tx][lg2[ty-tx+1]],st[ty-(1<<lg2[ty-tx+1])+1][lg2[ty-tx+1]]);}

ll dolt(int wsy){
	sort(w+1,w+1+wsy);wsy--;
	if(!wsy)	return 0;
	rep(i,1,wsy,1){
		if(w[i]==w[i+1])	c[i]=n-sa[w[i]]+1;
		else				c[i]=qmin(w[i]+1,w[i+1]);
	}
	int cc=0,sm=1;	stack<int> S;
	rep(i,1,wsy,1){
		while(!S.empty() && c[S.top()]>c[i])	S.pop();
		if(S.empty())	lma[i]=0;
		else			lma[i]=S.top();
		S.push(i);
	}
	while(!S.empty())	S.pop();
	per(i,wsy,1,1){
		while(!S.empty() && c[S.top()]>=c[i])	S.pop();
		if(S.empty())	rma[i]=wsy+1;
		else			rma[i]=S.top();
		S.push(i);
	}
	ll ans=0;
	rep(i,1,wsy,1){
		ans+=1ll*c[i]*(i-lma[i])*(rma[i]-i);
	}
	while(!S.empty())	S.pop();
	return ans;
}
signed main()
{ios::sync_with_stdio(0);cin.tie(0);//cerr<<fixed<<setprecision(3)<<(&Mbe-&Med)/1048576.0<<"MiB"<<endl;
#ifdef TZL_MEOW
// freopen(R"(input.in)","r",stdin);
// freopen(R"(my.out)","w",stdout);
#endif
	int q;cin>>n>>q;
	rep(i,1,n,1)	lg2[i]=log2(i);
	string str;cin>>str;str="|"+str;
	build(str,n);
	rep(i,1,n,1)	st[i][0]=ht[i];
	// rep(i,1,n,1)	cerr<<ht[i]<<" ";cerr<<endl;
	rep(i,1,18,1)	rep(j,1,n-(1<<i)+1,1)	st[j][i]=min(st[j][i-1],st[j+(1<<(i-1) )][i-1]);
	while(q--){
		int a,b;cin>>a>>b;ll ans=0;s.clear();
		rep(i,1,a,1)	cin>>x[i],x[i]=rk[x[i]];
		rep(i,1,b,1)	cin>>y[i],y[i]=rk[y[i]];
		rep(i,1,a,1)	w[i]=x[i];
		ans-=dolt(a);
		rep(i,1,b,1)	w[i]=y[i];
		ans-=dolt(b);
		rep(i,1,b,1)	w[i]=y[i];
		rep(i,1,a,1)	w[b+i]=x[i];
		ans+=dolt(a+b);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
10 1
bdaaueecfa
3 4
5 8 10
3 5 6 9
*/