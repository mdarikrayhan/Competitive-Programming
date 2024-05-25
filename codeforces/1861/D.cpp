

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 300005
#define pb push_back
#define pp pair<int, int>
#define rsort(a) sort(a.rbegin(), a.rend())
#define ssort(a) sort(a.begin(), a.end())
#define rev(a) reverse(a.begin(), a.end())
#define mp make_pair
#define mod 1000000007
#define ed '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define loop(n) for (i = 0; i < n; i++)
#define loop1(n) for (i = 1; i <= n; i++)
#define unique(s) s.erase(unique(s.begin(), s.end()), s.end());
#define lower(s) transform(aint(s), s.begin(), ::tolower);
#define upper(s) transform(aint(s), s.begin(), ::toupper);
#define ub(x) upper_bound(a, a + n, x) - a // always upper
#define lb(x) lower_bound(a, a + n, x) - a // desire one or upper
#define yn(k) cout << (k ? "YES" : "NO") << endl;
#define SetBit(x, k) (x |= (1int << k))
#define ClearBit(x, k) (x &= ~(1int << k))
#define CheckBit(x, k) ((x >> k) & 1)
#define check                \
    for (i = 0; i < n; i++)  \
        cout << a[i] << " "; \
    cout << endl;
#define fast ios_base::sync_with_stdio(false), cin.tie(NUint)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define REP(x, n) for (int x = 0; x < n; x++)
#define ordered_set tree<int, nuint_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
// int prime[1000000];

// seive:
// for (int i = 4; i <= n + 1; i += 2)
//     prime[i] = 1;
// for (int i = 3; i <= n + 1; i += 2)
// {
//     if (prime[i])
//         continue;
//     for (int j = 3 * i; j <= n + 1; j += 2 * i)
//         prime[j] = 1;
// }

// nCr
// Just caint FactMod() in main function
// int Fact[N];
// void FactMod()
//{
//     Fact[0]=1;
//     for(int i=1;i<N;i++)
//     {
//         Fact[i]=((Fact[i-1]*i)%mod);
//     }
// }
//
// int PowerMod(int a, int n)
//{
//     if(n==0) return 1;
//     int x=PowerMod(a,n/2);
//     if(n%2==0) return (x*x)%mod;
//     return ((x*x)%mod*a)%mod;
// }
//
// int InverseMod(int a)
//{
//     return PowerMod(a,mod-2);
// }
//
// int nCr(int n,int r)
//{
//     if(r==0) return 1;
//     if(r>n) return 0;
//     return(Fact[n] * InverseMod((Fact[r]*Fact[n-r]) % mod)) %mod;
// }
//
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j = 0, k, r, l = 0, dif = 0, x = 0, day = 0, up, bad = 0, b, c, h, m, y;
        cin >> n;
        int a[n + 2];
        for (i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int pre[n + 1], po[n + 1];
        pre[1] = 0, po[n] = 0;
        for (i = 2; i <= n; i++)
        {
            if ((a[i] >= a[i - 1]))
                pre[i] = pre[i - 1] + 1;
            else
                pre[i] = pre[i - 1];
        }
        l = 1 + pre[n];
        x = 0;
        for (i = n; i > 0; i--)
        {
            if (i < n && a[i] >= a[i + 1])
                x++;
            if (i == 1)
            {
                l = min(l, x);
            }
            else
                l = min(l, x + 1 + pre[i - 1]);
        }

        cout << l << endl;
    }
}
