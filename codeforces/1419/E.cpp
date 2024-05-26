#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
const int maxn=1e6+10;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define allin(a , x) for(auto a : x)
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef long long ll;
#define int ll
const int inf=LLONG_MAX;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for (; e; b = modmul(b, b, mod), e /= 2)
        if (e & 1) ans = modmul(ans, b, mod);
    return ans;
}
bool isPrime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
        s = __builtin_ctzll(n-1), d = n >> s;
    for (ull a : A) {   // ^ count trailing zeroes
        ull p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}
ull pollard(ull n) {
    ull x = 0, y = 0, t = 30, prd = 2, i = 1, q;
    auto f = [&](ull x) { return modmul(x, x, n) + i; };
    while (t++ % 40 || __gcd(prd, n) == 1) {
        if (x == y) x = ++i, y = f(x);
        if ((q = modmul(prd, max(x,y) - min(x,y), n))) prd = q;
        x = f(x), y = f(f(y));
    }
    return __gcd(prd, n);
}
vector<ull> factor(ull n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    ull x = pollard(n);
    auto l = factor(x), r = factor(n / x);
    l.insert(l.end(), all(r));
    return l;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 
    #endif
    ios::sync_with_stdio(0);cin.tie(0);

    int T; cin>> T;
    while(T--)
    {
        int n; cin>> n;
        auto vecp = factor(n);
        sort(vecp.begin(), vecp.end());
        vecp.erase(unique(vecp.begin(), vecp.end()), vecp.end());
        if(vecp.size() != 2)
        {
            vector<int> vec;
            for(int p: vecp)
            {
                int sz = vec.size();
                if(sz) vec.pb(p*vec[sz-1]);
                vec.pb(p);
                for(int i=sz-2; i>=0; i--)
                {
                    vec.pb(vec[i]*p);
                }
            }
            // for(int x: vec)
            //     cout<< x<< " ";
            // cout<< "\n";
            int sz = vecp.size();
            // identifica cada divisor por uma mask
            map<int, int> msk; // mask de cada cara
            vector<vector<int>> vmsk(1<<sz); // vetor dos divisores de cada mask
            for(int i=1; i<(1<<sz); i++)
            {
                int prod = 1;
                for(int j=0; j<sz; j++)
                    if(i&(1<<j))
                        prod *= vecp[j];
                msk[prod] = i;
            }
            vector<int> vdiv;
            for(int i=2; i*i<=n; i++)
            {
                if(n%i == 0)
                {
                    vdiv.pb(i);
                    if(i*i < n) vdiv.pb(n/i);
                }
            }
            vdiv.pb(n);
            for(int div: vdiv)
            {
                auto vecpd = factor(div);
                sort(vecpd.begin(), vecpd.end());
                vecpd.erase(unique(vecpd.begin(), vecpd.end()), vecpd.end());
                int prod = 1;
                for(int p: vecpd)
                    prod *= p;
                vmsk[msk[prod]].pb(div);
            }
            for(int prod: vec)
            {
                for(int x: vmsk[msk[prod]])
                    cout<< x<< " ";
            }
            cout<< "\n";
            cout<< "0\n";
            continue;
        }
        // resta o caso em que vecp.size() == 2
        int p = vecp[0], q = vecp[1];
        if(n == p*q)
        {
            cout<< p<< " "<< p*q<< " "<< q<< "\n";
            cout<< "1\n";
            continue;
        }
        int aux = n;
        int ep = 0, eq = 0;
        while(aux%p == 0)
        {
            aux /= p;
            ep++;
        }
        while(aux%q == 0)
        {
            aux /= q;
            eq++;
        }
        // cout<< p<< " "<< q<< " "<< ep<< " "<< eq<< "\n";
        if(ep < eq) swap(p, q), swap(ep, eq);
        set<int> all;
        for(int i=0, potp = 1; i<=ep; i++, potp *= p)
            for(int j=0, potq = 1; j<=eq; j++, potq *= q)
                if(i+j)
                    all.insert(potp * potq);
        int potq = 1;
        int potpq = 1;
        for(int i=1; i<=eq; i++)
        {
            potq *= q, potpq *= p*q;
            cout<< potq<< " "<< potpq<< " ";
            all.erase(potq);
            all.erase(potpq);
        }
        for(int x: all)
            cout<< x<< " ";
        cout<< "\n";
        cout<< "0\n";
    }

    return 0;
}