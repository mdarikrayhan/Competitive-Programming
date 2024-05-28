#include<bits/stdc++.h>
#define fr first
#define sc second
#define P pair<long long,long long>
#define m_p make_pair
#define pb push_back
#define lowbit(x) (x&(-x))
#define int long long
typedef long long ll;
using namespace std;
int tx[100005],ty[100005],tw[100005],pos[100005],r[100005];
ll w[100005];
vector<int> g[100005];
int cnt;
void dfs(int x){
    if(pos[x]!=-1) return;
    //cout<<x<<endl;
    pos[x]=cnt;
    r[cnt]=x;
    for(int i=0;i<g[x].size();i++){
        int u=g[x][i];
        dfs(u);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,p,q;cin>>n>>m>>p>>q;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v>>tw[i];
        u--;v--;
        tx[i]=u;ty[i]=v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i=0;i<n;i++) pos[i]=-1;
    //cout<<"HO"<<endl;
    for(int i=0;i<n;i++){
        if(pos[i]==-1){
            dfs(i);
            cnt++;
        }
    }
    //cout<<cnt<<endl;
    for(int i=0;i<m;i++){
        int u=tx[i];
        w[pos[u]]+=tw[i];
    }
    if(cnt-p>q||cnt<q){
        cout<<"NO"<<endl;
        return 0;
    }
    int nd=cnt-q;
    vector<P> ans;
    priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
    for(int i=0;i<cnt;i++) {
        pq.push(m_p(w[i],r[i]));
        //cout<<w[i]<<" "<<r[i]<<endl;
    }
    //cout<<cnt<<" "<<pq.size()<<endl;
    while(nd--){
        //cout<<pq.size()<<endl;
        ll w1=pq.top().fr;int x=pq.top().sc;pq.pop();
        ll w2=pq.top().fr;int y=pq.top().sc;pq.pop();
        ans.pb(m_p(x,y));
        ll nw=min(1000000000ll,w1+w2+w1+w2+1);
        pq.push(m_p(nw,x));
    }
    //cout<<cnt<<endl;
    if(m==0&&ans.size()==0&&p-(cnt-q)>0){
        cout<<"NO"<<endl;
        return 0;
    }
    if(m) for(int i=0;i<p-nd;i++) ans.pb(m_p(tx[0],ty[0]));
    if(!m){
        while(ans.size()<p) ans.pb(ans[0]);
    }
    cout<<"YES"<<endl;
    for(int i=0;i<p;i++) cout<<ans[i].fr+1<<" "<<ans[i].sc+1<<endl;
    return 0;
}