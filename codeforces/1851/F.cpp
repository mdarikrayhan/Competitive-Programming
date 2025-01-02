// LUOGU_RID: 160070117
#include<bits/stdc++.h>
#define INF 1e16
#define endl '\n'
#define PI acos(-1)
#define pb push_back
#define int long long
#define mem(x,v) memset(x,v,sizeof x)
using namespace std;
const int maxn = 2e5+5;
inline int read(){
	register int x=0,f=1;register char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

int t,n,m;
struct Array{int x,id;}a[maxn];
bool cmp(Array x,Array y){return x.x<y.x;}

void solve(){
	int maxx=INF,I,J,id;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].x,a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)if((a[i].x^a[i+1].x)<maxx)maxx=a[i].x^a[i+1].x,id=i;
	int x=a[id].x,y=a[id+1].x,ans=0;
	cout<<a[id].id<<' '<<a[id+1].id<<' ';
	for(int i=0;i<m;i++){
		int k1=(x&(1<<i)),k2=(y&(1<<i));
		if(k1==0&&k2==0)ans+=(1<<i);
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(cin>>t;t--;)solve();
	return 0;
}
