#include<bits/stdc++.h>
#define maxn 2900001
#define int long long
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();return x*f;}
void write(int x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');return;}
using namespace std;
int T,b,n;
void solve(){
	int res=1;
	scanf("%lld%lld",&b,&n);
	for(int i=1;i<n;i++){
		res=res*b%n;
		if(!res) return printf("1 %lld\n",i),void();
		if(res==1) return printf("2 %lld\n",i),void();
		if(res==n-1) return printf("3 %lld\n",i),void();
	}
	puts("0");
}
signed main(){
	scanf("%lld",&T);
	while(T--) solve();
	return 0;
}