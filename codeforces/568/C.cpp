// LUOGU_RID: 159907573
#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
void get(char&c){c=getchar();while(!isalpha(c))c=getchar();}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define orz write(-1),exit(0)
const int N=2e3+100;
int n,m,l;bool e[N][N];
//C = 0 V = 1
int bel[30],diff[30],same[30],lst[2];
char str[N];
int ans[N];
bool lim=1;//跟下界贴贴
int must[N];
bool chk(int pos,int now){
	ans[pos]=now;
	//在pos加了now
	//首先看看有没有矛盾
	if(e[pos+bel[now]*n][pos+(bel[now]^1)*n])return 0;
	for(int i=1;i<pos;i++)if(e[pos+bel[now]*n][i+(bel[ans[i]]^1)*n])return 0;
	for(int i=pos+1;i<=n;i++)if(e[pos+bel[now]*n][i]&&e[pos+bel[now]*n][i+n])return 0;
	//然后矛盾是没有了
	//但是还有字典序的限制
	//我们直接构造后面字典序最大即可
	memset(must,0xff,sizeof must);
	for(int i=1;i<=pos;i++)for(int j=pos+1;j<=n;j++)for(int k=0;k<2;k++)
		if(e[i+bel[ans[i]]*n][j+k*n])must[j]=k;
	for(int i=pos+1;i<=n;i++){
		int choice=must[i];
		if(choice==-1)choice=bel[l-1];
		if(e[i+choice*n][i+(choice^1)*n])choice^=1;
		ans[i]=lst[choice];
		for(int j=i+1;j<=n;j++)for(int k=0;k<2;k++)
			if(e[i+choice*n][j+k*n])must[j]=k;
	}
	for(int i=1;i<=n;i++)
		if(ans[i]>str[i]-'a')return 1;
		else if(ans[i]<str[i]-'a')return 0;
	return 1;
}
signed main(){
	//freopen("1.in","r",stdin);
	scanf("%s",str);l=strlen(str);
	for(int i=0;i<l;i++)bel[i]=(str[i]=='V');
	for(int i=0;i<l;i++)lst[bel[i]]=i;
	memset(same,0xff,sizeof same);
	memset(diff,0xff,sizeof diff);
	for(int i=0;i<l;i++)for(int j=i+1;j<l;j++)if(bel[j]!=bel[i]){diff[i]=j;break;}
	for(int i=0;i<l;i++)for(int j=i+1;j<l;j++)if(bel[j]==bel[i]){same[i]=j;break;}
	read(n,m);
	for(int SJYAK=1;SJYAK<=m;SJYAK++){
		int x,y;char a,b;
		read(x);get(a);read(y);get(b);
		a=(a=='V');b=(b=='V');
		// x a -> y b   y !b -> x !a
		e[x+a*n][y+b*n]=e[y+(b^1)*n][x+(a^1)*n]=1;
	}
	scanf("%s",str+1);
	for(int k=1;k<=2*n;k++)for(int i=1;i<=2*n;i++)for(int j=1;j<=2*n;j++)e[i][j]|=(e[i][k]&e[k][j]);
	for(int i=1;i<=n;i++){
		if(lim){
			//优先选str[i]-'a'
			vector<int>arr={str[i]-'a',same[str[i]-'a'],diff[str[i]-'a']};
			sort(arr.begin(),arr.end());
			for(auto x:arr)if(~x)
				if(chk(i,x)){
					ans[i]=x;
					lim&=(x==str[i]-'a');
					goto wyhaknoi;
				}
			orz;
			wyhaknoi:;
		}else{
			if(chk(i,0))ans[i]=0;
			else if(~diff[0]&&chk(i,diff[0]))ans[i]=diff[0];
			else orz;
		}
	}
	for(int i=1;i<=n;i++)pc(ans[i]+'a');
}