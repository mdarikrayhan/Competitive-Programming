#include<bits/stdc++.h>
#define fo(i,l,r)for(i=l;i<=r;i++)
int i,j,k,n,t,b,T,a[100010],f[100010];main(){scanf("%d%d%d%d",&T,&n,&b,&t);while(T--){fo(i,1,n)scanf("%d",&a[i]);memset(f,0,sizeof(f));t=std::min(t,std::min(n,b));fo(i,1,t)fo(j,1,n){f[a[j]]=f[a[j]-1]+1;fo(k,a[j]+1,b){if(f[k]>=f[a[j]])break;f[k]=f[a[j]];}}printf("%d\n",f[b]);}}