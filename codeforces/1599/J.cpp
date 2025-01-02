// LUOGU_RID: 157628297
#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<algorithm>
#include<map>
#include<unordered_map>

#include<bitset>
#include<set>

#include<deque>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<complex>
#include<ctime>
#include<vector>

#define fi first
#define se second
#define pb push_back
#define mk std::make_pair
#define pii std::pair<int,int>
#define db double
#define ll long long
#define ull unsigned long long
#define _ putchar('\n');
#define __ putchar(' ');
#define DBG printf("DBG! line:%d func:%s\n",__LINE__,__FUNCTION__);
#define CLOSE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define p1(x) printf("%d\n",x)
#define p2(x,y) printf("%d %d\n",x,y)
#define p3(x,y,z) printf("%d %d %d\n",x,y,z)
#define p4(x,y,z,i) printf("%d %d %d %d\n",x,y,z,i)
#define p5(x,y,z,i,j) printf("%d %d %d %d %d\n",x,y,z,i,j)
#define pf(x) printf("%f\n",x)
#define pa(a,n) {for(int i=(1),K=(n);i<=(K);i++)printf("%d ",a[i]);puts("");}
#define paa(a,n,m) {for(int i=(0),nn=(n),mm=(m);i<=(nn);i++){for(int j=(0);j<=(mm);j++)printf("%d ",a[i][j]);puts("");}}
#define pc(a) {for(int i=(1),K=(strlen(a+1));i<=(K);i++)printf("%c",a[i]);puts("");}
#define ft for(int i=(h[u]),v=(to[i]);(i);i=(nxt[i]),v=(to[i]))
#define min(i,j) (std::min((i),(j)))
#define cmin(i,j) ((i)=(min((i),(j))))
#define max(i,j) (std::max((i),(j)))
#define cmax(i,j) ((i)=(max((i),(j))))
#define swap(x,y) (std::swap(x,y))
#define f(i,j,k) for(int i=(j),K=(k);i<=(K);i++)
#define F(i,j,k,l) for(int i=(j);k;l)
#define uf(i,j,k) for(int i=(k),J=(j);i>=(J);i--)
#define mem(t,v) memset((t),v,sizeof(t))
#define rand(i,j) ((rnd()%((j)-(i)+1))+(i))

#define md (1000000007)
#define eps (1e-8)
#define inf (0x3f3f3f3f)

int rea(char *s){int tot=1;char ch = getchar();while(!(('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z')||isdigit(ch)))
ch=getchar();while(('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z')||isdigit(ch)){s[tot++]=ch;ch=getchar();}return tot-1;}
void re(int &x){x=0;char ch=getchar();int f=1;while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}while(isdigit(ch))
{x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}x*=f;}void __wr(ll x){if(x<0){putchar('-');x=-x;}if(x>9){__wr(x / 10);}putchar(x%10+'0');}
void wr(ll x,char p){__wr(x);putchar(p);}
ll qpow(ll a,ll k) {ll s=1;for(;k;k>>=1,a=a*a%md)if(k&1)s=(ll)s*a%md;return s;}
using namespace std;
const int N = 1e5+10,M=2e5+10;
int n,m,a[N],ans[N],sz,b[N],c;

unordered_map<int,ll>mp;
ll ansa,ansb;
void dfs(int x,int cnt,ll S,int s){
    if(x==sz+1){
        if(mp.count(s)) ansa=mp[s],ansb=S;
        else mp[s]=S;
        return ;
    }
    f(i,cnt+1,m){
        dfs(x+1,i,S|(1ll<<(i-1)),s+a[i]);
        if(ansa||ansb) return;
    }
}
int main(){
	re(n);
	f(i,1,n)re(a[i]),m+=(a[i]%2==0);
	sort(a+1,a+1+n);
	if(m){
		int x,y,z,s,t;x=y=z=0;
		if(m<=2){
			f(i,1,n){
				if(a[i]&1){
					if(y)z=i;
					else y=i;
				}
				else x=i;
			}
			if(!z){
				puts("NO");
				return 0;
			}
		}
		else{
			f(i,1,n){
				if(a[i]&1)continue;
				if(!x)x=i;
				else if(y)z=i;
				else y=i;
			}
		}
		s=a[x]+a[y]+a[z];t=s/2-a[x];
		puts("YES");
		f(i,1,n){
			if(i==x||i==y||i==z)wr(s/2-a[i],' ');
			else wr(a[i]-t,' ');
		}
		return 0;
	}
	m=min(n,27),sz=m/2;
    dfs(1,0,0,0);
    if(ansa||ansb){
        ll y=ansa&ansb;int h=0;
        ansa^=y,ansb^=y;c=ansa|ansb;
        f(i,1,m) if(ansa&(1ll<<(i-1))) b[++h]=a[i];
        f(i,1,m) if(ansb&(1ll<<(i-1))) b[++h]=a[i];
        puts("YES");
        f(i,1,m) if(!(c&(1<<(i-1)))) wr(a[i],' ');
        f(i,m+1,n) wr(a[i],' ');
        for(int i=1,j=h/2+1,x=0,y=0;j<=h;i++,j++){
            if(i==1) x=0,y=b[j]-x;
            else x=b[i]-y,y=b[j]-x;
            wr(x,' ');wr(y,' ');
        }
    }
    else puts("NO");
	
	return 0;
}
