#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=1e6+5;
typedef pair<char,int> PII;
const int mod=1e9+7;
const int inf=1e9;
void solve(){  
    int n;cin>>n;
    vector<int>g[n+1];
    for(int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int>sz(n+1,0);
    vector<int>maxsub(n+1,0);
    vector<int>inner1(n+1,0);
    vector<int>inner2(n+1,0);
    vector<int>choose(n+1,0);
    function<void(int,int)>dfs1=[&](int x,int fa){
        sz[x]=1;
        for(auto v:g[x]){
            if(v!=fa){
                dfs1(v,x);
                sz[x]+=sz[v];
                if(sz[maxsub[x]]<sz[v]){
                    maxsub[x]=v;
                }
                int innersz=sz[v]<=n/2?sz[v]:inner1[v];
                if(inner1[x]<innersz){
                    choose[x]=v;
                    inner2[x]=inner1[x];
                    inner1[x]=innersz;
                }else if(inner2[x]<innersz){
                    inner2[x]=innersz;
                }
            }
        }
    };
    dfs1(1,-1);
    vector<int>outer(n+1,0);
    function<void(int ,int )>dfs2=[&](int x,int fa){
        for(auto v:g[x]){
            if(v!=fa){
                if(n-sz[v]<=n/2){
                    outer[v]=n-sz[v];
                }else if(choose[x]!=v){
                    outer[v]=max(outer[x],inner1[x]);
                }else {
                    outer[v]=max(outer[x],inner2[x]);
                }
                dfs2(v,x);
            }
        }
    };
    dfs2(1,-1);
    auto check=[&](int x){
        if(sz[maxsub[x]]>n/2){
            return sz[maxsub[x]]-inner1[x]<=n/2;
        }
        if(n-sz[x]>n/2){
            return n-sz[x]-outer[x]<=n/2;
        }
        return true; 
    };
    for(int i=1;i<=n;i++){
        if(check(i))cout<<1<<" ";
        else cout<<0<<" ";
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)solve();
    return 0^0;
} 