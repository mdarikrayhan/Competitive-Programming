#include<bits/stdc++.h>
using namespace std;
#define int long long
int  a[1202020],b[1202020];

int fa[200202];
int dp[202020][2];
bool cmp(pair<int,int>a,pair<int,int>b){
    return a.first-a.second>b.first-b.second;
}
vector<int>g[202020];
int sz[202020];
int d[10];
int n,k;
int ma=0;
void dfs(int x,int p){
    int i;
    if(x==n){
        set<pair<int,int>>s;
        for(i=0;i<k;i++){
            int x=d[a[i]],y=d[b[i]];
            if(x>y)swap(x,y);
            s.insert(make_pair(x,y));
        }
        ma=max(ma,(int)s.size());
        return;
    }
    for(i=1;i<=6;i++){
        d[x+1]=i;
        dfs(x+1,i);
    }

}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=1;
    //cin>>_;
    int i,j;
    string s;
    int c=0;
    while(_--){
        int i;
        int l,r,y;
        cin>>n>>k;
        for(i=0;i<k;i++){
            cin>>a[i]>>b[i];
        }
        dfs(0,0);
        cout<<ma;
        

    }
    
}

/*
5 3
2 1
0 2
0 0
0 0

4 2
1 1
2 2
4 8
2 4

*/