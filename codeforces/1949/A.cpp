// LUOGU_RID: 160619776
#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int N=405;const db eps=1e-9;
vector<pair<int,int>>id;
struct Solver{
    int n;bool exi[N][N];
    vector<int>ans,tans;
    int f[N];
    void link(int x,int y){exi[x][y]=1;}
    bool dfs(int x){
        rep(i,x+1,n){
            if(f[i]+tans.size()<=ans.size())return 0;
            if(!exi[x][i])continue;
            bool ok=1;
            for(auto j:tans){
                if(!exi[i][j]){ok=0;break;}
            }
            if(ok){
                tans.push_back(i);
                if(dfs(i))return 1;
                tans.pop_back();
            }
        }
        if(tans.size()>ans.size()){ans=tans;return 1;}
        return 0;
    }
    void Run(){
        for(int i=n;i>=1;i--){
            tans.clear();tans.push_back(i);
            dfs(i);
            f[i]=ans.size();
        }
        printf("%d\n",(int)ans.size());
        for(auto i:ans){
            printf("%d %d\n",id[i-1].first,id[i-1].second);
        }
    }
}T;
int n;db r;
db dis(pair<int,int>x,pair<int,int>y){return sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));}
int main(){
    scanf("%d%lf",&n,&r);
    rep(i,1,n){
        rep(j,1,n){
            if(min({i,j,n-i,n-j})>=(int)ceil(r))id.push_back({i,j});
        }
    }
    T.n=id.size();
    for(int i=0;i<id.size();i++){
        for(int j=0;j<id.size();j++){
            if(i!=j&&dis(id[i],id[j])-2*r>-eps)T.link(i+1,j+1);
        }
    }
    T.Run();
    return 0;
}