//Dedicated to my love,ivaziva
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dbg(x) cerr<<#x<<": "<<x<<endl;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double

const ll inf=(ll)1e18+5;
const int mod=1e9+7;
const int K=501;
const int L=32;
const int N=1e5+2;

ll readint()
{
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;
int a[N];
map<int,int> r,cnt;
int main()
{
    n=readint();k=readint();
    for(int i=0;i<n;i++) a[i]=readint();
    int x=k;
    for(int i=2;i*i<=k;i++)
    {
        int cnt=0;
        while(x%i==0)
        {
            x/=i;
            cnt++;
        }
        if(cnt) r[i]=cnt;
    }
    if(x!=1) r[x]=1;
    ll ans=0,br=0;
    for(int lb=0,rb=0;rb<n;rb++)
    {
        int p=a[rb];
        for(auto it:r)
        {
            while(p%it.fi==0)
            {
                if(it.se==++cnt[it.fi])
                {
                    br++;
                }
                p/=it.fi;
            }
        }
        while(br==r.size()&&lb<=rb)
        {
            ans+=n-rb;
            for(auto it:r)
            {
                while(a[lb]%it.fi==0)
                {
                    if(it.se==cnt[it.fi]--)
                    {
                        br--;
                    }
                    a[lb]/=it.fi;
                }
            }
            lb++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
