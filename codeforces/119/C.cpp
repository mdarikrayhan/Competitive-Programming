// LUOGU_RID: 160013877
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace fast_IO{
    #define FASTIO
    #define IOSIZE 1000000
    char ibuf[IOSIZE],obuf[IOSIZE];char*p1=ibuf,*p2=ibuf,*p3=obuf;
    #ifdef ONLINE_JUDGE
    #define getchar()((p1==p2)and(p2=(p1=ibuf)+fread(ibuf,1,IOSIZE,stdin),p1==p2)?(EOF):(*p1++))
    #define putchar(x)((p3==obuf+IOSIZE)&&(fwrite(obuf,p3-obuf,1,stdout),p3=obuf),*p3++=x)
    #endif
    #define isdigit(ch)(ch>47&&ch<58)
    #define isspace(ch)(ch<33)
    template<typename T>inline T read(){T s=0;int w=1;char ch;while(ch=getchar(),!isdigit(ch)and(ch!=EOF))if(ch=='-')w=-1;if(ch==EOF)return false;while(isdigit(ch))s=s*10+ch-48,ch=getchar();return s*w;}template<typename T>inline bool read(T&s){s=0;int w=1;char ch;while(ch=getchar(),!isdigit(ch)and(ch!=EOF))if(ch=='-')w=-1;if(ch==EOF)return false;while(isdigit(ch))s=s*10+ch-48,ch=getchar();return s*=w,true;}inline bool read(char&s){while(s=getchar(),isspace(s));return true;}inline bool read(char*s){char ch;while(ch=getchar(),isspace(ch));if(ch==EOF)return false;while(!isspace(ch))*s++=ch,ch=getchar();*s='\000';return true;}template<typename T>inline void print(T x){if(x<0)putchar('-'),x=-x;if(x>9)print(x/10);putchar(x%10+48);}inline void print(char x){putchar(x);}inline void print(char*x){while(*x)putchar(*x++);}inline void print(const char*x){for(int i=0;x[i];i++)putchar(x[i]);}
    #ifdef _GLIBCXX_STRING
    inline bool read(std::string&s){s="";char ch;while(ch=getchar(),isspace(ch));if(ch==EOF)return false;while(!isspace(ch))s+=ch,ch=getchar();return true;}inline void print(std::string x){for(int i=0,n=x.size();i<n;i++)putchar(x[i]);}
    #endif
    template<typename T,typename...T1>inline int read(T&a,T1&...other){return read(a)+read(other...);}template<typename T,typename...T1>inline void print(T a,T1...other){print(a);print(other...);}struct Fast_IO{~Fast_IO(){fwrite(obuf,p3-obuf,1,stdout);}}io;template<typename T>Fast_IO&operator>>(Fast_IO&io,T&b){return read(b),io;}template<typename T>Fast_IO&operator<<(Fast_IO&io,T b){return print(b),io;}
}
#define cin fast_IO::io
#define cout fast_IO::io
#define endl '\n'
//
const int maxn=100+10;
int d,n,val;
struct Subject{
	int l,r,c;
	int id;
	bool operator < (const Subject &it)const{
		return c<it.c;
	}
}s[maxn];
int mx,tmp;
int p;
int f[maxn][maxn][maxn],vis[maxn];
void find(int t,int x,int now){
	if(!t)return ;
	vis[x]=1;
	mx=-1,p=0,tmp=0;
	for(int i=1;i<x;i++){
		if(s[i].c>=s[x].c)continue ;
		int j=now-val-s[i].l;
		if(j>=0&&j<=s[i].r-s[i].l&&f[t-1][i][j]){
			if(f[t-1][i][j]>mx){
				mx=f[t-1][i][j];
				tmp=j+s[i].l;
				p=i;
			}
		}
		if(now%val==0){
			j=now/val-s[i].l;
			if(j>=0&&j<=s[i].r-s[i].l&&f[t-1][i][j]){
				if(f[t-1][i][j]>mx){
					mx=f[t-1][i][j];
					tmp=j+s[i].l;
					p=i;
				}
			}
		}
	}
	find(t-1,p,tmp);
	cout<<s[x].id<<' '<<now<<'\n';
}
signed main(){
	cin>>d>>n>>val;
	for(int i=1;i<=n;i++){
		cin>>s[i].l>>s[i].r>>s[i].c;
		s[i].id=i;
	}
	sort(s+1,s+1+n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=s[i].r-s[i].l;j++){
			f[1][i][j]=s[i].l+j;
		}
	}
	for(int t=2;t<=d;t++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(s[i].c<=s[j].c)continue ;
				for(int k=0;k<=s[j].r-s[j].l;k++){
					if(f[t-1][j][k]==0)continue ;
					int now=1ll*(s[j].l+k)+val-s[i].l;
					if(now>=0&&now<=s[i].r-s[i].l){
						f[t][i][now]=max(f[t][i][now],f[t-1][j][k]+now+s[i].l);
					}
					now=1ll*(s[j].l+k)*val-s[i].l;
					if(now>=0&&now<=s[i].r-s[i].l){
						f[t][i][now]=max(f[t][i][now],f[t-1][j][k]+now+s[i].l);
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=s[i].r-s[i].l;j++){
			if(f[d][i][j]>mx){
				mx=f[d][i][j];
				tmp=j+s[i].l;
				p=i;
			}
		}
	}
	if(!p){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	// cout<<p<<' '<<mx<<'\n';
	find(d,p,tmp);

	return 0;
}