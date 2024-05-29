// LUOGU_RID: 157805943
//#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;  

#define int long long
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
#define lowbit(x) ((x)&(-x))

#define lc(p) ((p)<<1)
#define rc(p) ((p)<<1|1)

#define sqr(x) ((x)*(x))

// #define mod 1000000007
// #define mod 998244353
#define eps 1e-8

#define debug cout<<__LINE__<<" "<<__FUNCTION__<<"\n";
#define spa putchar(' ')
#define ero putchar('\n')

constexpr int N=5010,inf=1e18;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
inline void write(int x){
	if(!x)putchar('0');
	if(x<0)x=-x,putchar('-');
	int cnt=0,a[30];
	while(x)a[++cnt]=x%10,x/=10;
	while(cnt--)putchar(a[cnt+1]+'0');
}

int a[N][N];
int deg[N];
int tmp[N];

char s[N];

void solve(int x,int y){
	deg[x]-=a[x][y];
	a[x][y]^=1;
	deg[x]+=a[x][y];
}

int n;

bool check(){
	copy(deg+1,deg+n+1,tmp+1);
	sort(tmp+1,tmp+n+1);
	int res=0;
	for(int i=1;i<n;i++){
		res+=tmp[i];
		if(res==i*(i-1)/2){
			return 0;
		}
	}
	return 1;
}

int ans1;
int ans2;

void solve1(){
	ans1=n+1;
	for(int i=0;i<(1<<n);i++){
		int tot=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1){
				tot++;
				for(int k=1;k<=n;k++){
					solve(j,k);
					solve(k,j);
				}
			}
		}
		if(tot<=ans1&&check()){
			if(tot==ans1){
				ans2++;
			}
			if(tot<ans1){
				ans1=tot;
				ans2=1;
			}
		}	
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1){
				for(int k=1;k<=n;k++){
					solve(j,k);
					solve(k,j);
				}
			}
		}
	}
	for(int i=1;i<=ans1;i++){
		ans2*=i;
	}
}

void solve2(){
	ans1=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			solve(j,i);
			solve(i,j);
		}
		if(check()){
			ans2++;
		}
		for(int j=1;j<=n;j++){
			solve(j,i);
			solve(i,j);
		}
	}
}

signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=n;j++){
			a[i][j]=s[j]-'0';
			deg[i]+=a[i][j];
		}
	}
	if(check()){
		write(0),spa,write(1);
		return 0;
	}
	if(n<=6){
		solve1();
	}
	else{
		solve2();
	}
	if(ans1>n){
		write(-1);
		return 0;
	}
	write(ans1),spa,write(ans2);
	return 0;
}