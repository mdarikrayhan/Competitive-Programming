// LUOGU_RID: 158873354
#include<bits/stdc++.h>
using namespace std;

#define int long long
namespace IO{
	template<typename T> inline void write(T x){
		if(x<0) putchar('-'),x=-x;
		if(x==0){
			putchar('0'); return ;
		}
		if(x>9) write(x/10);
		putchar(x%10+'0');
		return ;
	}
	template<typename T> inline void read(T &x){
		x=0; int w=1; char ch=getchar();
		while(!isdigit(ch)){
			if(ch=='-') w=-1; ch=getchar();
		}
		while(isdigit(ch))
			x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
		x*=w; return ;
	}
}
using namespace IO;
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),putchar('\n')
#define inf 0x3f3f3f3f
#define mod 1000000007
#define N 500010
int n,k,a[N],b[N],ans;
int v[N];
struct un{
    int x,op;
};
priority_queue<un>as;
bool operator <(const un a,const un b){
    if(a.x==b.x)return a.op<b.op;
    return a.x>b.x;
}
int check(int x){
    while(as.size())as.pop();
    int num=0,cnt=0;
    for(int i=1;i<=n;++i){
        as.push(un{a[i],1});
        if(b[i]+x+as.top().x<0){
            num+=as.top().op;
            cnt+=b[i]+x+as.top().x;
            as.pop();
            as.push(un{-b[i]-x,0});
        }
    }
    if(num<=k)ans=cnt-x*k;
    return num<=k;
}
signed main(){
   // freopen("1.in","r",stdin);
    read(n),read(k);
    for(int i=1;i<=n;++i)read(a[i]);
    for(int i=1;i<=n;++i)read(b[i]);
    int l=-2e10,r=0;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    writeln(ans);
return 0;
}