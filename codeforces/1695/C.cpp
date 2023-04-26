#include<bits/stdc++.h>
using namespace std;
int N,M,A[1001];
bitset< 2001 >Dp[1001];
int main(void)
{
register int Case;cin>>Case;while(Case--)
{
register int i,j;cin>>N>>M;
for(j=0;j<M;j++)Dp[j].reset();
Dp[0][1000]=1;
for(i=0;i<N;i++)for(j=0;j<M;j++)
{
cin>>A[j];
if(A[j]==1)Dp[j]<<=1;
else Dp[j]>>=1;
if(j+1<M)Dp[j+1]|=Dp[j];
}
if(Dp[M-1][1000]==1)puts("Yes");
else puts("No");
}
return 0;
}