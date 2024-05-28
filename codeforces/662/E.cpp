//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <istream>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <string.h>
#include <map>
#include <unordered_map>
#include <sstream>
#define mp(a,b) make_pair(a,b)
#define double long double
#define int long long
#define p1(x) x.first
#define p2(x) x.second
using namespace std;
const int INF=1e9;
int t[5030][4];
int n;
int H[4];
int S[4];
int dp[2][100][100][100];
int SH=0;
int Hk[4];
int sc[4];
int ans=INF;
inline int SC(int loc,int t){
    if(t==0)return t;
    return sc[loc]*(250-abs(t))/250;
}
inline int calc(){
    int Sc=0;
    for(int i=1;i<=3;i++)
        Sc+=SC(i,t[1][i])+Hk[i]*100;
    bool fl=0;
    for(int i=0;i<=Hk[1];i++)
        for(int j=0;j<=Hk[2];j++)
            for(int k=0;k<=Hk[3];k++)
                dp[fl][i][j][k]=0;
    fl=1;
    for(int y=2;y<=n;y++,fl^=1){
        int SS=0;
        for(int i=1;i<=3;i++)
            SS+=SC(i,t[y][i]);
        if(SS<=Sc){fl^=1;continue;}
        for(int i=0;i<=Hk[1];i++)
            for(int j=0;j<=Hk[2];j++)
                for(int k=0;k<=Hk[3];k++)
                    dp[fl][i][j][k]=dp[!fl][i][j][k];
        int i[4];
        for(i[1]=0;i[1]<=1;i[1]++)
            for(i[2]=0;i[2]<=1;i[2]++)
                for(i[3]=0;i[3]<=1;i[3]++){
                    bool p=0;
                    for(int j=1;j<=3;j++)
                        p|=t[y][j]>=0&&i[j];
                    if(p)continue;
                    int Tsc=0;
                    for(int j=1;j<=3;j++)
                        Tsc+=(i[j]^1)*SC(j,t[y][j]);
                    if(Tsc>Sc)continue;
                    for(int k=i[1];k<=Hk[1];k++)
                        for(int p=i[2];p<=Hk[2];p++)
                            for(int q=i[3];q<=Hk[3];q++)
                                dp[fl][k][p][q]=max(dp[fl][k][p][q],dp[!fl][k-i[1]][p-i[2]][q-i[3]]+1);
                }
    }
    int res=1;
    for(int y=2;y<=n;y++){
        int SS=0;
        for(int i=1;i<=3;i++){
            SS+=SC(i,t[y][i]);
            //cout<<sc[i]<<"x"<<i<<"x"<<t[y][i]<<"x"<<SC(i,t[y][i])<<"  ";
        }
        if(SS>Sc)res++;
    }
   // cout<<endl;
   // cout<<res<<endl;
  //  for(int i=1;i<=3;i++)
   //     cout<<sc[i]<<" ";
 //   cout<<endl;
    res-=dp[!fl][Hk[1]][Hk[2]][Hk[3]];
    return res;
}
inline void dfs(int dep){
    if(dep==3){
        ans=min(ans,calc());
        return ;
    }
    for(int i=1;i<=6;i++){
        int liml=(n>>i)+1;
        int limr=(n>>(i-1));
        if(i==6)liml=0;
        if(S[dep+1]<liml||S[dep+1]-H[dep+1]>limr)continue;
        sc[dep+1]=500*i;
        Hk[dep+1]=min(H[dep+1],S[dep+1]-liml);
        dfs(dep+1);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=3;j++){
            cin>>t[i][j];
            if(t[i][j])S[j]++;
            if(t[i][j]<0)H[j]++,SH++;

    }
    if(SH>=90)
        cout<<1;
    else{
        dfs(0);
        cout<<ans;
    }
    return 0;
}
