/*********************** In the Name of ALLAH ************************/
#include<bits/stdc++.h>
#define fl(n) for(ll i = 0; i < n;i++)
#define flj(n) for(ll j = 0; j < n;j++)
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl "\n"
using namespace std;
#define MOD 1000000007

//My Debugger
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p )
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v )
{
    os << "{";
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v )
{
    os << "[";
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v )
{
    os << "[";
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v )
{
    os << "[";
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

void faltu ()
{
    cerr << endl;
}

template <typename T>
void faltu( T a[], int n )
{
    for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
    cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest)
{
    cerr << arg << ' ';
    faltu(rest...);
}
//End

// Modular arithmetic
inline void normal(ll &a)
{
    a %= MOD;
    (a < 0) && (a += MOD);
}
inline ll modMul(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a*b)%MOD;
}
inline ll modAdd(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a+b)%MOD;
}
inline ll modSub(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
}
inline ll modPow(ll b, ll p)
{
    ll r = 1;
    while(p)
    {
        if(p&1) r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1;
    }
    return r;
}
inline ll modInverse(ll a)
{
    return modPow(a, MOD-2);
}
inline ll modDiv(ll a, ll b)
{
    return modMul(a, modInverse(b));
}
// End

int main()
{
    optimize();
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        ll cnt1 = 0,ans1 = 0,maxi = 0,mini  = 0,flag = 0;
        ll ans2 = 0,flag2 = 0,flag3 = 0;
        ll l = -1,r = -1;

        string s,str;
        cin >> n;// 71345
        if(n % 25 == 0) cout << 0 << endl;
        else
        {
            s = to_string(n);
            for(ll i = s.size()-1; i >= 0; i--)
            {
                if(flag == 0)
                {
                    if(s[i] == '0')
                    {
                        flag = 1;
                        r = i;
                    }
                }
                else
                {
                    if(s[i] == '5' || s[i] == '0')
                    {
                        l = i;
                        break;
                    }
                }
            }
//            dbg(l);
//            dbg(r);
            if(r != -1 && l != -1)
            {
                ans1 = r-l-1 + (s.size()-1-r);
                flag2 = 1;
            }
//            dbg(ans1);
            r = -1,l = -1;
            flag = 0;
            for(ll i = s.size()-1; i >= 0; i--)
            {
                if(flag == 0)
                {
                    if(s[i] == '5')
                    {
                        flag = 1;
                        r = i;
                    }
                }
                else
                {
                    if(s[i] == '2' || s[i] == '7')
                    {
                        flag = 0;
                        l = i;
                        break;
                    }
                }
            }
//            dbg(l);
//            dbg(r);
            if(r != -1 && l != -1)
            {
                ans2 = r-l-1 + (s.size()-1-r);
                flag3 = 1;
            }
//            dbg(ans2);
            if(flag2 && flag3)
            {
                cout << min(ans1,ans2) << endl;
            }
            else
            {
                if(flag2) cout << ans1 << endl;
                else cout << ans2 << endl;
            }


        }
    }
}




