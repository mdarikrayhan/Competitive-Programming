// LUOGU_RID: 159820455
#include<bits/stdc++.h>
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
	#define N 100005
	#define SQ 605
	#define INF 0x3f3f3f3f
	#define pii pair<int,int>
	#define pb push_back
	#define MP make_pair
	#define fi first
	#define se second
	#define cpy(a,b) memcpy(a,b,sizeof a)
	#define clr(a) memset(a,0,sizeof a)
	#define DEBUG cout<<"You are right,but you are wrong"<<'\n'
	#define END cout<<"You are right,but you are right now"<<'\n'
	const int limit=600,m=100000;
	int n,quecnt,QAQ,A[N],B[N],a[N],b[N],qa[SQ],acnt,qb[SQ],bcnt,mpa[N],mpb[N],fu[N],furina,tonga[N],tongb[N],cnt[SQ][SQ],smo[N<<1];
	struct que{int opt,x;bl y;};vector<int> va[SQ],vb[SQ];vector<que> q;bl visa[N],visb[N],visp[N];
	il vd solve(){
		cpy(A,a),cpy(B,b),clr(visa),clr(visb),clr(visp),clr(smo),clr(cnt),acnt=bcnt=furina=0;
		for(vector<que>::iterator it=q.begin();it!=q.end();++it){
			int opt=it->opt,x=it->x;bl y=it->y;if(opt==3) continue;
			if(!visp[x]) fu[++furina]=x;visp[x]=1;
			if(opt==1){
				int val=a[x]-(y^1);
				if(!visa[val]) qa[++acnt]=val;visa[val]=1;
				if(y) ++a[x];else --a[x];
			}else{
				int val=b[x]-(y^1);
				if(!visb[val]) qb[++bcnt]=val;visb[val]=1;
				if(y) ++b[x];else --b[x];
			}
		}
		sort(qa+1,qa+1+acnt),sort(qb+1,qb+1+bcnt);
		for(int i=1;i<=acnt;i++) mpa[qa[i]]=i,va[i].clear();
		for(int i=1;i<=bcnt;i++) mpb[qb[i]]=i,vb[i].clear();
		cpy(a,A),cpy(b,B);
		for(int i=1;i<=n;i++){
			if(visp[i]) continue;
			if(visa[a[i]]) va[mpa[a[i]]].pb(b[i]);
			else if(visb[b[i]]) vb[mpb[b[i]]].pb(a[i]);
			else ++smo[tonga[a[i]+1]+tongb[b[i]+1]+1];
		}
		for(int i=1;i<=m*2+5;i++) smo[i]+=smo[i-1];
		for(int i=1;i<=acnt;i++) sort(va[i].begin(),va[i].end(),greater<int>());
		for(int i=1;i<=bcnt;i++) sort(vb[i].begin(),vb[i].end(),greater<int>());
		for(vector<que>::iterator it=q.begin();it!=q.end();++it){
			int opt=it->opt,x=it->x;bl y=it->y;
			if(opt==1){
				if(y) ++tonga[++a[x]];
				else --tonga[a[x]--];
			}else if(opt==2){
				if(y) ++tongb[++b[x]];
				else --tongb[b[x]--];
			}else{
				int val=tonga[a[x]+1]+tongb[b[x]+1]+1,res=smo[val-1];
				for(int i=1;i<=furina;i++) res+=tonga[a[fu[i]]+1]+tongb[b[fu[i]]+1]+1<val;
				for(int i=1;i<=acnt;i++){
					if(va[i].empty()) continue;
					int l=0,r=va[i].size()-1,mid,check=val-tonga[qa[i]+1]-1;
					while(l<=r){
						if(tongb[va[i][mid=l+r>>1]+1]>=check) r=mid-1;
						else l=mid+1;
					}
					res+=r+1;
				}
				for(int i=1;i<=bcnt;i++){
					if(vb[i].empty()) continue;
					int l=0,r=vb[i].size()-1,mid,check=val-tongb[qb[i]+1]-1;
					while(l<=r){
						if(tonga[vb[i][mid=l+r>>1]+1]>=check) r=mid-1;
						else l=mid+1;
					}
					res+=r+1;
				}
				cout<<res+1<<'\n';
			}
		}
	}
	signed main(){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i],++tonga[a[i]];
		for(int i=1;i<=n;i++) cin>>b[i],++tongb[b[i]];
		for(int i=m;i;i--) tonga[i]+=tonga[i+1],tongb[i]+=tongb[i+1];
		for(cin>>QAQ;QAQ--;){
			int opt,x;char y;cin>>opt>>x;++quecnt;
			if(opt==3) q.pb((que){opt,x,0});
			else cin>>y,q.pb((que){opt,x,y=='+'});
			if(quecnt==limit) solve(),vector<que>().swap(q),quecnt=0;
		}
		if(quecnt) solve();
		return 0;
	}
}
signed main(){
	TYX_YNXK::main();
	return 0;
}