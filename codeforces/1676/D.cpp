#include<iostream>
using namespace std;
int T;
int N,M;
int A[200][200];
main()
{

cin>>T;
for(;T--;)
{
cin>>N>>M;
for(int i=0;i<N;i++)for(int j=0;j<M;j++)cin>>A[i][j];
int ans=0;
for(int i=0;i<N;i++)for(int j=0;j<M;j++)
{
int now=-A[i][j];
for(int k=0;k<N;k++)
{
int d=abs(i-k);
if(j>=d)now+=A[k][j-d];
if(j+d<M)now+=A[k][j+d];
}
ans=max(ans,now);
}
cout<<ans<<"\n";
}
}