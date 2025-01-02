// LUOGU_RID: 155016309
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
int vis[1000005],d[1000005];
vector<int> G[1000005];
signed main(){
	//freopen("文件名.in","r",stdin);
    //freopen("文件名.out","w",stdout);
    IOS();
    int n,m;
    cin>>n>>m;
    while(m--){
    	int u,v;
    	cin>>u>>v;
    	d[u]++,d[v]++;
    	G[u].pb(v);
    	G[v].pb(u);
	}
	int n1=0,n2=0;
	for(int i=1;i<=n;i++){
		if(vis[i] || !G[i].size() && i!=1)
			continue;
		queue<int> q;
		q.push(i);
		int ok=0;
		vis[i]=1;
		while(!q.empty()){
			int p=q.front();
			q.pop();
			if(d[p]%2)
                n2++,ok=1;
            for(int j:G[p]){
                if(vis[j])
					continue;
                vis[j]=1;
                q.push(j);
            }
		}
		if(!ok)	
			n1++;
	}
	if(n1==1 && !n2)
		cout<<"0\n";
	else
		cout<<n1+n2/2<<"\n";
	return 0;
}
