// LUOGU_RID: 160017034
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
int root[N],idx;
struct Node
{
    int l,r;
    int cnt,sum;
}tr[N<<5];
int insert(int p,int l,int r,int x)
{
    int q=++idx;
    tr[q]=tr[p];
    if (l==r)
    {
        tr[q].cnt++;
        tr[q].sum+=x;
        return q;
    }
    int mid=l+r>>1;
    if (x<=mid) tr[q].l=insert(tr[p].l,l,mid,x);
    else tr[q].r=insert(tr[p].r,mid+1,r,x);
    tr[q].cnt=tr[tr[q].l].cnt+tr[tr[q].r].cnt;
    tr[q].sum=tr[tr[q].l].sum+tr[tr[q].r].sum;
    return q;
}
int query(int p,int l,int r,int k)
{
    if (l==r) return min(tr[p].cnt,k/l);
    int cnt=tr[tr[p].l].cnt,sum=tr[tr[p].l].sum,mid=l+r>>1;
    if (sum<=k) return cnt+query(tr[p].r,mid+1,r,k-sum);
    else return query(tr[p].l,l,mid,k);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i=1,x;i<=n;i++)
    {
        cin>>x;
        root[i]=insert(root[i-1],1,100,x);
        cout<<i-1-query(root[i-1],1,100,m-x)<<" ";
    }
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    solve();
    return 0;
}