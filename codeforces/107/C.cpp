#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,y,m;
int adj[20];
int prof_pos[20],pos[20];
int dp[1<<16];
int cnt(){
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int mask=0;mask<(1<<n)-1;mask++){
        int curr=__builtin_popcount(mask);
        for(int i=0;i<n;i++){
            if((mask>>i)&1) continue;
            if(prof_pos[curr]==-1 || prof_pos[curr]==i){
                if((mask|adj[i])>mask)  continue;
                dp[mask|(1<<i)]+=dp[mask];
            }
        }
    }
    return dp[(1<<n)-1];
}
void solve(){
    cin >> n >> y >> m;
    y=y-2000;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[b]|=(1<<a);
    }
    memset(prof_pos,-1,sizeof(prof_pos));
    int ways=cnt();
    // cerr<<ways<<endl;
    if(ways<y){
        cout<<"The times have changed\n";
        return;
    }
    for(int i=0;i<n;i++){
        for(int curr=0;curr<n;curr++){
            if(prof_pos[curr]==-1){
                prof_pos[curr]=i;
                pos[i]=curr+1;
                int curr_ways=cnt();
                if(curr_ways>=y){
                    break;
                }
                y-=curr_ways;
                prof_pos[curr]=-1;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<pos[i]<<" ";
    }
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}