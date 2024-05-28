#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fr(m) for(int i=0; i<m; i++)
#define fro(m) for(int i=1; i<m; i++)
#define frj(m) for(int j=0; j<m; j++)
#define frr(n) for(int i=n; i>=0; i--)
#define pb push_back
#define pf push_front
#define orr ||
#define nl '\n'
#define nll cout<<'\n'
#define mod 1000000007
#define inf (1LL<<60)
#define inff (1<<30)-1
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mxn 205

int n, arr[5][mxn], vis[mxn], dep[mxn], val;
ll loop;
vector<int>g[mxn];

bool eval(int j){
    for(int x=1; x<=n; x++){
        int gx=arr[j][x];
        if(arr[j][gx]!=gx) return 0;
    }
    return 1;
}

void dfs(int node, int d){
    dep[node]=d;
    vis[node]=1;
    for(int a : g[node]){
        if(vis[a]==1){
            loop=d-dep[a]+1;
        }
        else if(vis[a]==0) dfs(a,d+1);
    }
    vis[node]=2;
}

void dfs2(int node, int d){
    dep[node]=d;
    vis[node]=1;
    for(int a : g[node]){
        if(vis[a]==1){
            if(a==node && dep[a]>1) val=0;
        }
        else if(vis[a]==0) dfs2(a,d+1);
    }
    vis[node]=2;
}

int main()
{
    fastio;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[1][i];
    }
    ll add=0;
    for(int j=1; j<=n; j++){
        arr[3][j]=arr[1][j];
    }
    while(1){
        for(int i=1; i<=n; i++){
            g[i].clear();
            g[i].pb(arr[3][i]);
        }
        val=1;
        for(int i=1; i<=n; i++){
            dfs2(i,0);
            if(!val) break;
        }
        for(int i=0; i<n+2; i++) vis[i]=0;
        if(val) break;
        add++;
        for(int j=1; j<=n; j++){
            arr[2][j]=arr[3][j];
        }
        for(int j=1; j<=n; j++){
            arr[3][j]=arr[1][arr[2][j]];
        }
    }
    ll ans=500005;
    for(int i=1; i<=2*n; i++){
        //3 latest
        if(eval(3)){
            ans=i; break;
        }
        for(int j=1; j<=n; j++){
            arr[2][j]=arr[3][j];
        }
        for(int j=1; j<=n; j++){
            arr[3][j]=arr[1][arr[2][j]];
        }
    }
    // assert(ans!=500005);
    if(ans==500005){
        // cout<<"here"<<nl;
        // ll l=1;
        __int128 l=1;
        for(int i=0; i<n+2; i++) vis[i]=0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                loop=0;
                dfs(i,0);
                //check g
                if(loop){
                    __int128 g=__gcd(l,(__int128)loop);
                    __int128 tmp=l*loop;
                    tmp/=g;
                    l=tmp;
                }
                // cout<<i<<" "<<loop<<nl;
            }
        }
        ans=l;
    }
    // cout<<1<<nl;
    cout<<ans+add<<nl;
    return 0;
}
		         		 	 						   						