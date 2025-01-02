#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int b[500010];
int n,m;
void slove()
{
    cin>>n>>m;
    for(int i=0;i<=n+m+5;i++){
        a[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        a[b[i]]+=m+1;
    }
    for(int i=0;i<m;i++){
        int c,d;
        cin>>c>>d;
        c--;
        int k=b[c];
        b[c]=d;
        a[k]-=m-i;
        a[d]+=m-i;
    }
    int ans=0;
    for(int i=0;i<=n+m;i++){
        if(a[i]){
            int k=a[i]*(m);
            k-=(a[i]*(a[i]-1))/2;
            ans+=k;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        slove();
    }
    return 0;
}