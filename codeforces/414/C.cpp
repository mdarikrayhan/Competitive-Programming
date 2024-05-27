#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int a[N],q[N];
int cnt[30][2];
void merge(int l,int r,int x){
    if(l>=r) return ;
    int mid=l+r>>1;
    merge(l,mid,x-1);merge(mid+1,r,x-1);
    int i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(a[i]<a[j]) cnt[x][1]+=r-j+1,i++;
        else j++;
    }
    i=l,j=mid+1;
    int s=0;
    while(i<=mid&&j<=r){
        if(a[i]>a[j]) cnt[x][0]+=mid-i+1,q[s++]=a[j++];
        else q[s++]=a[i++];
    }
    while(i<=mid) q[s++]=a[i++];
    while(j<=r) q[s++]=a[j++];
    for(int i=l;i<=r;i++)
    a[i]=q[i-l];
}
void solve()
{
    cin>>n;
    for(int i=1;i<=(1<<n);i++)
    cin>>a[i];
    merge(1,1<<n,n);
    cin>>m;
    while(m--){
        int x;cin>>x;
        int res=0;
        for(int i=1;i<=x;i++)
        {
            swap(cnt[i][0],cnt[i][1]);
        }
        for(int i=1;i<=n;i++)res+=cnt[i][0];
        cout<<res<<"\n";
    }
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;

   // cin>>t;
    while(t--) solve();
    return 0;
}