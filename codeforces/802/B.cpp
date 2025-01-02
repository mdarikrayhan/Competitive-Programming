#include <iostream>
#include <queue>
#define ll long long
#define N 500002
#define inf 2147483647
using namespace std;
ll a[N],last[N],b[N],n,m,ans,k;
bool vis[N];
priority_queue<pair<ll,ll> > q;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>a[i];
    for(int i=1;i<=n;i++){
        b[last[a[i]]]=i;
        last[a[i]]=i;
        b[i]=inf;
    }
    for(int i=1;i<=n;i++){
        while(!q.empty()&&!vis[q.top().second])  q.pop();
        if(vis[a[i]]){
            q.push({b[i],a[i]});
            continue;
        }
        ans++;
        vis[a[i]]=1;
        if(!q.empty()&&k>=m){
            vis[q.top().second]=0;
            q.pop();
        }
        if(k<m)  k++;
        q.push({b[i],a[i]});
    }
    cout<<ans;
    return 0;
}