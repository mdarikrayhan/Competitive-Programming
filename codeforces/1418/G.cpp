// LUOGU_RID: 159856580
#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int maxn=5e5+5;
int n,a[maxn],num[maxn],cnt[maxn],ans;
ull v[maxn],pre[maxn];
map<int,int> mp;
signed main()
{
    mt19937_64 rnd(time(0));
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        v[i]=rnd();
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        pre[i]=pre[i-1];
        pre[i]-=cnt[a[i]]*v[a[i]];
        cnt[a[i]]++;
        cnt[a[i]]%=3;
        pre[i]+=cnt[a[i]]*v[a[i]];
	//将所有数出现的次数都模3再算哈希值，如果pre[l-1]==pre[r]代表[l,r]这段区间所有数出现的次数是3的倍数 
    }
    int l=1,r=0;
    while(r<=n)
    {
        while(num[a[r]]>3)//将每一个数出现的次数控制在3个之内 
        {
            num[a[l]]--;
            mp[pre[l-1]]--;
            l++;
        }
        ans+=mp[pre[r]];
        mp[pre[r]]++;
        r++;
        num[a[r]]++;
    }
    printf("%lld",ans);
    return 0;
}