#include<bits/stdc++.h>
using namespace std;const int N=5e3+7;
char s[N],t[N];int n,m,i,j,p,ans,T_T;short f[N][N];
int main(){
for(scanf("%d",&T_T);T_T--;){
for(scanf("%d%d%s%s",&m,&n,s,t),i=m-1;i>=0;--i)for(j=n-1;j>=0;--j)if(s[i]==t[j])f[i][j]=f[i+1][j+1]+1;
for(ans=m-f[0][0],i=p=0;i<m;++i){
if(p<n&&t[p]==s[i])p++;for(j=-1;j<p;++j)ans=min(ans,m-f[i+1][j+1]+i-j+1);
}printf("%d\n",p<n?-1:ans);
for(i=0;i<m;++i)for(j=0;j<n;++j)f[i][j]=0;
}
}