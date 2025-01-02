#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define F first
#define S second
#define ima INT_MAX
#define imi INT_MIN
#define pb push_back
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define life ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define MAXN 200005
#define MOD 1000000007
#define lb lower_bound
#define ub upper_bound

using namespace std;


ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool isPrime(ll num)
{
    if (num < 2)
        return false;

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

ll POW(ll p, ll n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
    {
        ll res = POW(p, n / 2);
        return res * res;
    }
    else
    {
        ll res = POW(p, n / 2);
        return res * res * p;
    }
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a,b) ;
}


int main() {
    life
    int t = 1;
    // cin >> t;
    while(t--){

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = v[0] ,energy = 0;

    for (int i = 0; i < n -1 ; i++) {
        energy += v[i] - v[i + 1];
        if (energy < 0) {
            ans += abs(energy);
            energy = 0;
        }
    }

    cout << ans << endl;
    }
    return 0;
}
