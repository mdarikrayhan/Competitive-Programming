// LUOGU_RID: 157058882
#include<bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
uint a[135],b[135];
uint C(int n,int m){
    for(int i=1;i<=m;i++) a[i]=n-i+1,b[i]=i;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=m;j++){
        uint g=__gcd(a[i],b[j]);
        a[i]/=g,b[j]/=g;
    }
    uint ans=1;
    for(int i=1;i<=m;i++) ans*=a[i];
    return ans;
}
uint ans[2000005],pw[2000005];
uint cc[135];
int main(){
    int n,p,q;cin>>n>>p>>q;
    uint res=0;p=min(p,n-1);
    for(int i=0;i<=p;i++) cc[i]=C(n,i);//cout<<i<<' '<<cc[i]<<'\n';
    for(int i=1;i<=q;i++){
        pw[i]=1;
        for(int j=0;j<=p;j++) pw[i]*=i,ans[i]+=pw[i]*cc[j];
        res^=ans[i];
        // cout<<ans[i]<<'\n';
    }
    cout<<res<<'\n';
}