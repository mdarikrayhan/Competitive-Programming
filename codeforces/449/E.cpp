// LUOGU_RID: 159784540
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
const ll mod = 1000000007;
int ww[maxn], pri[maxn], pn;
ll ip[maxn];
void init()
{
    ip[1] = 1;
    for(int i = 2; i <= 1000000; i++)
    {
        if(!ww[i]) ww[i] = ++pn, pri[pn] = i, ip[i] = i*2-1;
        for(int j = 1; j <= ww[i]; j++)
        {
            int v = pri[j]*i;
            if(v > 1000000) break;
            ww[v] = j;
        }
    }
    for(int i = 1; i <= pn; i++)
    {
        ll nw = 1;
        for(int k = 1; ; k++)
        {
            nw *= pri[i];
            if(nw > 1000000) break;
            ip[nw] = nw+(ll)nw/pri[i]*k*(pri[i]-1);
        }
    }
    for(int i = 1; i <= 1000000; i++)
    {
        if(!ip[i])
        {
            int t = i, lo = ww[t], k = 0, nw = 1;
            while(ww[t] == lo) k++, t /= pri[lo], nw *= pri[lo];
            ip[i] = ip[t]*ip[nw];
        }
    }
}
inline ll sg(ll n) { return ip[n]-n; }
inline ll s1(ll n) { return n*(n+1)/2%mod; }
inline ll s2(ll n) { return n*(n+1)*(n+n+1)/6%mod; }
ll f1(ll n) { return (n-1)*n*n-4*n*s1(n-1)+4*s2(n-1); }
ll f2(ll n) { return (n*s1(n-1)-s2(n-1)-n*(n-1)+sg(n))*2; }
inline ll f(ll n) { return (n*n+f1(n)+f2(n))%mod; }
ll F0[maxn], F1[maxn], F2[maxn];
void solve()
{
    ll n, m;
    cin >> n >> m;
    if(n > m) swap(n, m);
    ll ans = (n+1)*(m+1)%mod*F0[n]-(n+m+2)*F1[n]+F2[n];
    cout << (ans%mod+mod)%mod << endl;
}
int main()
{
    init();
    for(int i = 1; i <= 1000000; i++) F0[i] = f(i), F1[i] = i*F0[i]%mod, F2[i] = i*F1[i]%mod;
    for(int i = 1; i <= 1000000; i++) (F0[i] += F0[i-1]) %= mod, (F1[i] += F1[i-1]) %= mod, (F2[i] += F2[i-1]) %= mod;

    // for(int i = 1; i <= 10; i++) cerr << F0[i] << endl;
    // cerr <<f(4) << endl;
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}