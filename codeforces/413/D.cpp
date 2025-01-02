#include <bits/stdc++.h>
using namespace std;
int n,k,a[2001],dp[2001][4001][2];
int f(int i, int j, int b){
    if (i==n)
        return b;
    if (dp[i][j][b]!=-1)
        return dp[i][j][b];
    dp[i][j][b]=0;
    if (a[i]<4)
        dp[i][j][b]+=f(i+1,j+1,b|(j+1>=(1<<(k-1))));
    if (a[i]%4==0)
        dp[i][j][b]+=f(i+1,(j&1?2:j+2),b|((j&1?2:j+2)>=(1<<(k-1))));
    dp[i][j][b]%=1000000007;
    return dp[i][j][b];
}
int main(){
    cin >> n >> k;
    for (int i=0;i<n;i++)
        cin >> a[i];
    memset(dp,-1,sizeof(dp));
    cout << f(0,0,0);
}