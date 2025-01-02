// LUOGU_RID: 155314949
#include <bits/stdc++.h>
#define IOS() ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define fir first
#define se second
#define pb(x) push_back(x)
#define pii pair<int,int>
#define all(a) (a).begin(),(a).end()
#define mp(a,b) make_pair(a,b)
using namespace std;
int lowbit(int x){
	return x&-x;
}
inline int rd(){
    int f=0;int x=0;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
    if(f)x=-x;
    return x;
}
bool cmp(int x,int y){
	return x>y;
}
int a[55][55],mn[55],mx[55],dp[55][55];
signed main(){
	//freopen("文件名.in","r",stdin);
    //freopen("文件名.out","w",stdout);
    IOS();
    int n,m;
    cin>>n>>m;
    memset(a,1,sizeof(a));
    for(int i=1;i<=m;i++){
    	int u,v,w;
    	cin>>u>>v>>w;
    	a[u][v]=a[v][u]=w;
	}
	int l1,r1,l2,r2;
	cin>>l1>>r1>>l2>>r2;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	for(int i=1;i<=n;i++){
		mn[i]=1e9,mx[i]=-1e9;
		for(int j=1;j<=n;j++)
			if(i!=j){
				a[i][j]=a[i][j]*100+i;
				mn[i]=min(mn[i],a[i][j]);
				mx[i]=max(mx[i],a[i][j]);
			}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(i==j || mn[i]>=mx[j])
				continue;
			int t[55];
			memset(t,0,sizeof(t));
			for(int k=1;k<=n;k++)
				for(int l=1;l<=n;l++)
					if(l!=k && a[k][l]>mn[i] && a[k][l]<mx[j]){
						t[k]=1;
						break;
					}
			t[i]=t[j]=0;
			memset(dp,0,sizeof(dp));
			dp[0][0]=1;
			for(int k=1;k<=n;k++){
				for(int g=r1;g>=0;g--)
					for(int s=r2;s>=0;s--)
						if(dp[g][s]){
							if((mn[k]<mn[i] || k==i) && k!=j)
								dp[g+1][s]+=dp[g][s];
							if(t[k])
								dp[g][s+1]+=dp[g][s];
							if((mx[k]<=mx[j] || k==i) && k!=j)
								dp[g][s]=0;
						}
			}
			for(int k=l1;k<=r1;k++)
				for(int l=l2;l<=r2;l++)
					ans+=dp[k][l];
		}
	cout<<ans<<"\n";
	return 0;
}
