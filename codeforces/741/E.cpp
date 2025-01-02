// LUOGU_RID: 159689317
#include<bits/stdc++.h>
//#define int long long
using namespace std;
namespace fast_IO {//Take action! Using this Fast_io to read in or putout type "char*" will begin from point 1!
#define IOSIZE 100000
int precision=3,POW[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};char ibuf[IOSIZE],obuf[IOSIZE],*p1=ibuf,*p2=ibuf,*p3=obuf;
#ifdef ONLINE_JUDGE
#define getchar() ((p1==p2)and(p2=(p1=ibuf)+fread(ibuf,1,IOSIZE,stdin),p1==p2)?(EOF):(*p1++))
#define putchar(x) ((p3==obuf+IOSIZE)&&(fwrite(obuf,p3-obuf,1,stdout),p3=obuf),*p3++=x)
#define isdigit(ch) (ch>47&&ch<58)
#define isspace(ch) (ch<33)
#endif
template<typename T>inline T read(){T s=0;int w=1;char ch;while(ch=getchar(),!isdigit(ch)&&(ch!=EOF))if(ch==45)w=-1;if(ch==EOF)return 0;while(isdigit(ch))s=s*10+ch-48,ch=getchar();return s*w;}template<typename T>inline bool read(T&s){s=0;int w=1;char ch;while(ch=getchar(),!isdigit(ch)&&(ch!=EOF))if(ch==45)w=-1;if(ch==EOF)return 0;while(isdigit(ch))s=s*10+ch-48,ch=getchar();return s*=w,1;}inline bool read(char&s){while(s=getchar(),isspace(s));return 1;}inline bool read(char*s){char ch;++s;while(ch=getchar(),isspace(ch));if(ch==EOF)return 0;while(!isspace(ch))*s++=ch,ch=getchar();*s='\000';return 1;}template<typename T>inline void print(T x){if(x<0)putchar(45),x=-x;if(x>9)print(x/10);putchar(x%10+48);}inline void print(char x){putchar(x);}inline void print(char*x){++x;while(*x)putchar(*x++);}inline void print(const char*x){for(int i=0;x[i];i++)putchar(x[i]);}inline bool read(std::string&s){s="";char ch;while(ch=getchar(),isspace(ch));if(ch==EOF)return 0;while(!isspace(ch))s+=ch,ch=getchar();return 1;}inline void print(std::string x){for(int i=0,n=x.size();i<n;i++)putchar(x[i]);}inline bool read(bool&b){char ch;while(ch=getchar(),isspace(ch));b=ch^48;return 1;}inline void print(bool b){putchar(b+48);}inline bool read(double&x){int a=0,b=0;char ch=getchar();bool f=0;while(ch<48||ch>57){if(ch==45)f=1;ch=getchar();}while(47<ch&&ch<58){a=(a<<1)+(a<<3)+(ch^48);ch=getchar();}if(ch!=46){x=f?-a:a;return 1;}ch=getchar();while(47<ch&&ch<58){b=(b<<1)+(b<<3)+(ch^48),ch=getchar();}x=b;while(x>1)x/=10;x=f?-a-x:a+x;return 1;}inline void print(double x){if(x<0){putchar(45),x=-x;}x=round((long double)x*POW[precision])/POW[precision],print((long long)x),putchar(46),x-=(long long)(x);for(int i=1;i<=precision;i++)x*=10,putchar(x+48),x-=(int)x;}template<typename T,typename...T1>inline int read(T& a,T1&...other){return read(a)+read(other...);}template<typename T,typename...T1>inline void print(T a,T1...other){print(a),print(other...);}struct Fast_IO{~Fast_IO(){fwrite(obuf,p3-obuf,1,stdout);}}io;template<typename T>Fast_IO& operator>>(Fast_IO&io,T&b){return read(b),io;}template<typename T>Fast_IO& operator<<(Fast_IO&io,T b){return print(b),io;}
#define cout io
#define cin io
#define endl '\n'
}using namespace fast_IO;
namespace TYX_YNXK{
	#define il inline
	#define bl bool
	#define ll long long
	#define vd void
	#define N 200005
	#define INF 0x3f3f3f3f
	#define pii pair<int,int>
	#define pb push_back
	#define MP make_pair
	#define fi first
	#define se second
	#define DEBUG cout<<"You are right,but you are wrong"<<'\n'
	#define END cout<<"You are right,but you are right now"<<'\n'
	const int limit=120;
	int n,m,b,qwq,furina[N],fu[N],ans[N];char S[N],T[N],ch[N];
	namespace SA{
		int V,sa[N],rk[N],id[N],key[N],cnt[N],pre[N],height[N],st[N][21];
		#define idx(c) (c-'a'+1)
		#define cmp(x,y,w) pre[x]==pre[y]&&pre[x+w]==pre[y+w]
		#define clr(a) memset(a,0,sizeof a)
		il vd init(){
			V=30;
//			clr(sa),clr(rk),clr(id),clr(key),clr(cnt),clr(pre),clr(height),clr(st);
			for(int i=1;i<=b;i++) ++cnt[rk[i]=idx(ch[i])];
			for(int i=1;i<V;i++) cnt[i+1]+=cnt[i];
			for(int i=b;i;i--) sa[cnt[rk[i]]--]=i;
			for(int w=1,p=0;;w<<=1,V=p,p=0){
				for(int i=b;i>b-w;i--) id[++p]=i;
				for(int i=1;i<=b;i++) if(sa[i]>w) id[++p]=sa[i]-w;
				for(int i=1;i<=V;i++) cnt[i]=0;
				for(int i=1;i<=b;i++) ++cnt[key[i]=rk[id[i]]];
				for(int i=1;i<V;i++) cnt[i+1]+=cnt[i];
				for(int i=b;i;i--) sa[cnt[key[i]]--]=id[i];
				memcpy(pre+1,rk+1,b*sizeof(int)),p=0;
				for(int i=1;i<=b;i++) rk[sa[i]]=cmp(sa[i],sa[i-1],w)?p:++p;
				if(p==b) break;
			}
			for(int i=1,k=0;i<=b;i++){
				if(k) --k;
				while(ch[i+k]==ch[sa[rk[i]-1]+k]) ++k;
				height[rk[i]]=k;
			}
			for(int i=1;i<=b;i++) st[i][0]=height[i];
			for(int j=1;(1<<j)<=b;j++){
				for(int i=1;i+(1<<j)-1<=b;i++){
					st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
				}
			}
		} 
		il int RMQ(int l,int r){
			int d=__lg(r-l+1);
			return min(st[l][d],st[r-(1<<d)+1][d]);
		}
		il int lcp(int x,int y){
			x=rk[x],y=rk[y];
			if(x>y) swap(x,y);
			return RMQ(x+1,y);
		}
		il int op(int x,int y,int l){
			if(lcp(x,y)>=l) return 0;
			return rk[x]<rk[y]?-1:1;
		}
		il bl Cmp(int x,int y){
			int flag=x>y,tmp;if(flag) swap(x,y);
			if(x+m<=y){
				if(tmp=op(n+1,x+1,m)) return (tmp<0)^flag;
				if(tmp=op(x+1,x+m+1,y-x-m)) return (tmp<0)^flag;
				if(tmp=op(y-m+1,n+1,m)) return (tmp<0)^flag;
			}
			if(tmp=op(n+1,x+1,y-x)) return (tmp<0)^flag;
			if(tmp=op(n+y-x+1,n+1,x+m-y)) return (tmp<0)^flag;
			if(tmp=op(x+1,m+n+x-y+1,y-x)) return (tmp<0)^flag;
			return flag^1;
		}
	}
	int st[N][21];
	il int RMQ(int l,int r){
		if(l>r) return INF;
		int d=__lg(r-l+1);
		return min(st[l][d],st[r-(1<<d)+1][d]);
	}
	struct que{int l,r,k,x,y,id;bl operator<(const que&b)const{return k<b.k;}}q[N];
	signed main(){
		cin>>S>>T>>qwq;n=strlen(S+1),m=strlen(T+1),b=n+m;
		for(int i=1;i<=n;i++) ch[i]=S[i];
		for(int i=1;i<=m;i++) ch[i+n]=T[i];
		SA::init();
		for(int i=0;i<=n;i++) furina[i]=i;
		sort(furina,furina+n+1,SA::Cmp);
		for(int i=0;i<=n;i++) fu[furina[i]]=i;
		for(int i=1;i<=qwq;i++) cin>>q[i].l>>q[i].r>>q[i].k>>q[i].x>>q[i].y,q[i].id=i,ans[i]=INF;
		sort(q+1,q+1+qwq);
		for(int i=1,l=1;i<=limit&&l<=qwq;i++){
			if(i!=q[l].k) continue;
			int r=l;
			while(r<qwq&&q[r+1].k==i) ++r;
			for(int k=0;k<i;k++){
				int tmp=(n+1)/i+(k<=n%i);
				for(int u=1;u<=tmp;u++) st[u][0]=fu[(u-1)*i+k];
				for(int v=1;(1<<v)<=tmp;v++){
					for(int u=1;u+(1<<v)-1<=tmp;u++){
						st[u][v]=min(st[u][v-1],st[u+(1<<v-1)][v-1]);
					}
				}
				for(int u=l;u<=r;u++){
					if(q[u].x<=k&&k<=q[u].y) ans[q[u].id]=min(ans[q[u].id],RMQ((q[u].l-k+i-1)/i+1,(q[u].r-k+i)/i));
				}
			}
			l=r+1;
		}
		for(int i=1;i<=n+1;i++) st[i][0]=fu[i-1];
		for(int j=1;(1<<j)<=n+1;j++){
			for(int i=1;i+(1<<j)-1<=n+1;i++){
				st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
			}
		}
		for(int i=1;i<=qwq;i++){
			if(q[i].k<=limit) continue;
			for(int j=0;j*q[i].k<=n;j++) ans[q[i].id]=min(ans[q[i].id],RMQ(max(j*q[i].k+q[i].x,q[i].l)+1,min(j*q[i].k+q[i].y,q[i].r)+1));
		}
		for(int i=1;i<=qwq;i++) cout<<((ans[i]!=INF)?(furina[ans[i]]):(-1))<<' ';
		return 0;
	}
}
signed main(){
	TYX_YNXK::main();
	return 0;
}