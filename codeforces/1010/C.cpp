#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define xout cout << " "
#define xln cout << "\n"
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pb push_back
#define F first
#define S second
#define ld long double
#define oo 1e10
#define all(A) A.begin(), A.end()

const int M = 998244353;
ll powll(ll a,ll b,ll c=0){// a^b
    ll res=1;
    while(b>0){
        if(b&1){
            res*=a;
            if(c)res%=c;
        }
        b>>=1;
        a*=a;
        if(c)a%=c;
    }
    return res;
}

const ll N = 100000;
ll n, m, k, g, g1, g2,x;
bool f[100000];
int main()
{
    cin>>n>>k;
    g=0;
    while(n--){
        cin>>m;
        g=__gcd(g,m);
    }
    for(int i=0;!f[i];i=(i+g)%k){
        f[i]=1;
    }
    m=0;
    for(int i=0;i<k;i++)if(f[i])m++;
    cout<<m;
    for(int i=0;i<k;i++)
    if(f[i])xout<<i;xln;
}