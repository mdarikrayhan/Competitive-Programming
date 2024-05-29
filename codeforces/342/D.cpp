#include<bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int mod=1e9+7;

string grid[3];
ll dp[16][10005];
bool vis[16][10005];
int N;

ll solve(int state, int idx){
    if(idx==N)return state==8;
    if(vis[state][idx])return dp[state][idx];
    vis[state][idx]=1;
    ll tot=0;
    bool possib[3]={1,1,1};
    for(int i=0;i<3;++i){
        if(grid[i][idx]!='.' and ((1<<i)&state)){
            dp[state][idx]=0;
            return 0;
        }
        if(grid[i][idx]!='.' or ((1<<i)&state))
            possib[i]=0;
    }
    if(possib[0] and possib[1]){
        int nstate=state&8;
        if(possib[2]){
            if(idx+2<N and grid[2][idx+2]=='O')nstate=8;
            if(idx-1>=0 and grid[2][idx-1]=='O')nstate=8;
            tot=(tot+solve(nstate|4,idx+1))%mod;
        }else{
            if(grid[2][idx]=='O')nstate=8;
            tot=(tot+solve(nstate,idx+1))%mod;
        }
    }
    if(possib[1] and possib[2]){
        int nstate=state&8;
        if(possib[0]){
            if(idx+2<N and grid[0][idx+2]=='O')nstate=8;
            if(idx-1>=0 and grid[0][idx-1]=='O')nstate=8;
            tot=(tot+solve(nstate|1,idx+1))%mod;
        }else{
            if(grid[0][idx]=='O')nstate=8;
            tot=(tot+solve(nstate,idx+1))%mod;
        }
    }
    int nstate=state&8;
    for(int i=0;i<3;++i)
        if(possib[i]){
            nstate|=(1<<i);
            if(idx+2<N and grid[i][idx+2]=='O')nstate|=8;
            if(idx-1>=0 and grid[i][idx-1]=='O')nstate|=8;
        }
    tot=(tot+solve(nstate,idx+1))%mod;
    return dp[state][idx]=tot;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    for(int i=0;i<3;++i)cin>>grid[i];
    cout<<solve(0,0)<<'\n';
}