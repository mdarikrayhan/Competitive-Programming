#include <stdio.h>
int a[100005],b[100005];int main(){int t;scanf("%d",&t);while(t--){int n;scanf("%d", &n);for(int i=0;i<n;++i){scanf("%d",&a[i]);b[a[i]]=i;}int l=b[0],r=b[0],ans=1;for(int i=1;i<n;++i){if(b[i]<l)l=b[i];if(b[i]>r)r=b[i];while(i+1<n&&l<=b[i+1]&&b[i+1]<=r){ans=1ll*ans*(r-l-i)%1000000007;++i;}}printf("%d\n",ans);}}