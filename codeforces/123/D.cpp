// LUOGU_RID: 159832029
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN=110000;
const int MAXS=256;
int n; char a[MAXN];
int sa[MAXN], rnk[2*MAXN], rnk1[2*MAXN];
int st[MAXS], cnt[MAXN], tmp[MAXN];
int height[MAXN], top;
struct Node
{
    int id, val;
    Node(int i=0, int v=0): id(i), val(v) {}
} sta[MAXN];
int main()
{
//	freopen("CF123D.in", "r", stdin);
//	freopen("CF123D.out", "w", stdout);
    scanf("%s", a+1); n=strlen(a+1);
    memset(st, 0, sizeof st);
    memset(rnk, 0, sizeof rnk);
    for (int i=1; i<=n; i++) st[a[i]]=1;
    for (int i=1; i<MAXS; i++) st[i]+=st[i-1];
    for (int i=1; i<=n; i++) rnk[i]=st[a[i]];
    for (int k=0, p=1; k<n&&p<=n; p<<=1)
    {
        memset(cnt, 0, sizeof cnt);
        for (int i=1; i<=n; i++) cnt[rnk[i+p]]++;
        for (int i=1; i<=n; i++) cnt[i]+=cnt[i-1];
        for (int i=n; i>=1; i--) tmp[cnt[rnk[i+p]]--]=i;
        memset(cnt, 0, sizeof cnt);
        for (int i=1; i<=n; i++) cnt[rnk[i]]++;
        for (int i=1; i<=n; i++) cnt[i]+=cnt[i-1];
        for (int i=n; i>=1; i--) sa[cnt[rnk[tmp[i]]]--]=tmp[i];
        memcpy(rnk1, rnk, sizeof rnk1);
        rnk[sa[1]]=k=1;
        for (int i=2; i<=n; i++)
        {
            if (rnk1[sa[i]]!=rnk1[sa[i-1]]||rnk1[sa[i]+p]!=rnk1[sa[i-1]+p])
                k++;
            rnk[sa[i]]=k;
        }
    }
    height[n+1]=0;
    for (int i=1, k=0; i<=n; i++)
    {
        if (rnk[i]==1)
        {
            height[rnk[i]]=k=0;
            continue;
        }
        if (--k<0) k=0;
        while (a[i+k]==a[sa[rnk[i]-1]+k]) k++;
        height[rnk[i]]=k;
    }
    long long ans=0;
    for (int i=1; i<=n; i++)
    	ans+=n-sa[i]+1-max(height[i], height[i+1]);
    top=0;
    for (int i=1; i<=n+1; i++)
    {
    	int t=i;
        while (top>0&&height[i]<sta[top-1].val)
        {
            int l=i-sta[--top].id+1;
            int k=sta[top].val-max(height[i], top>0?sta[top-1].val:0);
            ans+=1ll*l*(l+1)/2*k;
            t=min(t, sta[top].id);
        }
        if (top==0||height[i]>sta[top-1].val)
            sta[top++]=Node(t, height[i]);
    }
    cout<<ans<<endl;
    return 0;
}