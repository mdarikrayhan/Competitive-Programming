// LUOGU_RID: 160028536
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

#define rep(i,l,r) for(int i(l);i<=(r);++i)
#define per(i,r,l) for(int i(r);i>=(l);--i)
#define eb emplace_back
#define File(filename) freopen(filename ".in","r",stdin),freopen(filename ".out","w",stdout)
#define Exit(p) fprintf(stderr,"[exit]: at breakpoint %d\n",p),exit(0);

#ifdef EXODUS
	#define Debug(...) fprintf(stderr,__VA_ARGS__)
#else
	#define Debug(...) 0
#endif

//=========================================================================================================
// Something about IO

template<typename T>
void read(T &x){
	x=0;T flg=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')flg=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x*=flg;
}
template<typename T>
void seq_read(T bg,T ed){for(auto i=bg;i!=ed;++i)read(*i);}
template<typename T,typename... Args>
void read(T &x,Args &...args){read(x),read(args...);}

//=========================================================================================================
//Some useful function

template<typename T>
void cmax(T& x,T y){x=max(x,y);}
template<typename T,typename... Args>
void cmax(T& x,T y,Args ...args){cmax(x,y);cmax(x,args...);}
template<typename T>
void cmin(T& x,T y){x=min(x,y);}
template<typename T,typename... Args>
void cmin(T& x,T y,Args ...args){cmin(x,y);cmin(x,args...);}
template<typename T,typename U>
void seq_assign(T bg,T ed,U val){for(auto i=bg;i!=ed;++i)(*i)=val;}
template<typename T,class F,class=enable_if_t<is_invocable_v<F>>>
void seq_assign(T bg,T ed,F func){for(auto i=bg;i!=ed;++i)(*i)=func(i);}
template<typename T>
void seq_copy(T dstbg,T dsted,T srcbg,T srced){for(auto i=dstbg,j=srcbg;i!=dsted&&j!=srced;++i,++j)(*i)=(*j);}

//=========================================================================================================
// Define the global variables here.

bool membg=0;

constexpr int N=2e5+7;
int n,m,a[N],b[N];
int px,py;

ll sum[N];
int pos[N];

bool memed=0;

//=========================================================================================================
// Code here.

bool check(int x){
	for(int i=1,j=m;i<=n;++i){
		while(j&&a[i]+b[j]>x)
			--j;
		sum[i]=sum[i-1]+j;
		pos[i]=j;
	}
	pair<ll,int>res={0ll,0};
	for(int i=m,j=0,ptr=n;i>=1;i--){
		while(ptr&&pos[ptr]<m-i)
			ptr--;
		pair<ll,int>cnt=make_pair(sum[ptr]+(sum[n]-sum[j])-(ll)(m-i)*ptr-(ll)i*(n-j),py<=i||px<=ptr);
		res=max(res,cnt);
		while(j<n&&pos[j+1]==i)
			j++;
	}
	return !!res.second;
}

void solve(){
	read(n,m);
	int sx=1,sy=1;
	for(int i=1;i<=n;i++)read(a[i]),sx+=a[i]<a[1];
	for(int i=1;i<=m;i++)read(b[i]),sy+=b[i]<b[1];
	int l=1,r=a[1]+b[1],ans=a[1]+b[1],A=a[1],B=b[1];
	sort(a+1,a+n+1),sort(b+1,b+m+1);
	px=find(a+1,a+n+1,A)-a,py=find(b+1,b+m+1,B)-b;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return;
}


//=========================================================================================================

int main(){
	Debug("%.3lfMB\n",fabs(&memed-&membg)/1024.0/1024.0);
	int timbg=clock();
	int T=1;
	while(T--)solve();
	int timed=clock();
	Debug("%.3lfs\n",1.0*(timed-timbg)/CLOCKS_PER_SEC);
	fflush(stdout);
	return 0;
}