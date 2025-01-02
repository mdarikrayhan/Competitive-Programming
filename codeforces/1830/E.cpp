// poly log ?
#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int INF=5e5+5;
int n,m,a[INF],tree[INF],b[INF],pos[INF],posl[INF],posr[INF];
void add(int x,int y) {for (int i=x;i<=5e5;i+=i&-i) tree[i]+=y;}
int query(int x) {int sum=0;for (int i=x;i;i-=i&-i) sum+=tree[i];return sum;}
int query2(int l,int r,int ll,int rr) {
    if (l>r) return 0;
    if (ll>rr) return 0;
    if (pos[l]==pos[r]) {
        int res=0;
        for (int i=l;i<=r;i++) 
            if (a[i]<=rr && a[i]>=ll) res++;
        return res;
    }
    int res=0;
    for (int i=l;i<=posr[pos[l]];i++) if (a[i]<=rr && a[i]>=ll) res++;
    for (int i=posl[pos[r]];i<=r;i++) if (a[i]<=rr && a[i]>=ll) res++;
    for (int i=pos[l]+1;i<pos[r];i++) {
        // cerr<<posl[i]<<" "<<posr[i]<<" "<<ll<<" "<<rr<<" "<<b[pos[l]]<<" qwq?\n";
        if (rr<b[posl[i]]) continue;
        if (ll>b[posr[i]]) continue;
        int L=posl[i],R=posr[i],ans=posl[i]-1;
        while (L<=R) {
            int Mid=(L+R)>>1;
            if (b[Mid]<=rr) L=(ans=Mid)+1;
            else R=Mid-1;
        }
        int ansr=ans;
        L=posl[i],R=posr[i],ans=posl[i]-1;
        while (L<=R) {
            int Mid=(L+R)>>1;
            if (b[Mid]<=ll-1) L=(ans=Mid)+1;
            else R=Mid-1;
        }
        res+=ansr-ans;
    }
    return res;
}
void add(int id) {
    for (int i=posl[id];i<=posr[id];i++) b[i]=a[i];
    sort(b+posl[id],b+1+posr[id]);
}
signed main()
{
    memset(posl,63,sizeof posl);
    ios::sync_with_stdio(false);
    cin>>n>>m;int sum1=0,sum2=0,B=700;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=n;i;i--) {
        add(a[i],1);
        sum2+=query(a[i]-1);
    }
    for (int i=1;i<=n;i++) sum1+=abs(i-a[i]);
    for (int i=1;i<=n;i++) pos[i]=i/B;
    for (int i=1;i<=n;i++) posl[pos[i]]=min(posl[pos[i]],i);
    for (int i=1;i<=n;i++) posr[pos[i]]=max(posr[pos[i]],i);
    for (int i=0;i<=n/B;i++) {
        for (int j=posl[i];j<=posr[i];j++) b[j]=a[j];
        sort(b+posl[i],b+1+posr[i]);
    }
    for (int i=1;i<=m;i++) {
        int x=0,y=0;
        cin>>x>>y; 
        if (x>y) swap(x,y);
        sum1-=abs(x-a[x]);sum1-=abs(y-a[y]);
        sum1+=abs(x-a[y]);sum1+=abs(y-a[x]);
        // cerr<<sum1<<" "<<sum2<<" qwq?\n";
        if (a[x]<a[y]) sum2+=query2(x+1,y-1,min(a[x],a[y]),max(a[x],a[y]))*2+1;
        else sum2-=2*query2(x+1,y-1,min(a[x],a[y]),max(a[x],a[y]))+(a[x]>a[y]);
        swap(a[x],a[y]);
        add(pos[x]);add(pos[y]);
        cout<<abs(sum1-sum2)<<"\n";
    }
    return 0;
}