// LUOGU_RID: 160202203
#include<bits/stdc++.h>
#define LL long long
#define LLL __int128
#define uint unsigned
#define ldb long double
#define uLL unsigned long long
using namespace std;
const int N=1e5+5,INF=1e9;
map<pair<int,int>,int>F;
map<pair<int,int>,pair<int,int>>G;
inline int solveF(int n,int m){
    if(n+m<3)return 0;
    if(F.count({n,m}))return F[{n,m}];
    int ans=INF,sx=-1,sy=-1;
    for(int x=max(0,n/2-3);x<=min(n,n/2+3);++x)
        for(int y=max(0,m/2-3);y<=min(m,m/2+3);++y){
            if(y==m&&n-x<=m)continue;
            if(y==0&&x<=m)continue;
            const int t=max(solveF(x+y,n-x),solveF(n+m-x-y,x))+1;
            if(t<ans)ans=t,sx=x,sy=y;
        }
    return G[{n,m}]={sx,sy},F[{n,m}]=ans;
}
inline void solve(basic_string<int>S,basic_string<int>T){
    if(S.size()+T.size()<3){
        for(const auto&i:(S+T)){
            cout<<"! "<<i<<endl;
            string s;cin>>s;if(s==":)")return;
        }
    }
    else{
        const auto [p,q]=G[{S.size(),T.size()}];
        basic_string<int>A,B,C,D;
        A.assign(S.begin(),S.begin()+p);
        B.assign(S.begin()+p,S.end());
        C.assign(T.begin(),T.begin()+q);
        D.assign(T.begin()+q,T.end());
        cout<<"? "<<p+q;for(const auto&i:(A+C))cout<<" "<<i;cout<<endl;
        string s;cin>>s;
        s=="YES"?solve(A+C,B):solve(B+D,A);
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;cin>>n,solveF(n,0);
    basic_string<int>S;
    S.resize(n);
    iota(S.begin(),S.end(),1);
    solve(S,{});
    return 0;
}
/*
*/