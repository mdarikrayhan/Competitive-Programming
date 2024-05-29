// LUOGU_RID: 160595475
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,m,k,a[N],f[N];ll s[N];
bool check(int n){
    for(int i=0;i<n;i++)a[i+1]=f[i];
    sort(a+1,a+n+1);ll sum=0;
    for(int i=2,p=1;i<=n;i++){
        sum+=a[i];
        while(sum>=1ll*(i-p)*a[p+1]+1ll*p*k)sum-=a[++p];
        if(sum-1ll*p*k<=s[i-p])return false;
    }
    return true;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&m,&k);
        for(int i=0;i<=m;i++)scanf("%d",f+i);
        s[0]=-1e18;s[2]=2*k;
        for(int i=2;i<=m;i++)s[i+1]=s[i]+k+(s[i]+k)/i;
        int L=0,R=m+1,ans=0;
        while(L<=R){
            int mid=(L+R)>>1;
            if(check(mid))ans=mid,L=mid+1;
            else R=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}