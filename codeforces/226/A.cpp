#include <bits/stdc++.h>
typedef long long ll;
#define ina(a,n) for(ll i=0;i<n;i++) in>>a[i];
#define in std::cin
#define out std::cout
ll power(int num, int deg,ll m) {
    if (!deg)
        return 1;
 
    if (deg % 2) {
        return (power(num, deg - 1,m) * num) % m;     
    }
    else {
        ll sqrt_res = power(num, deg / 2,m);
        return (sqrt_res * sqrt_res) % m;
    }
}
int main()
{
    ll n,m;
    in>>n>>m;
    ll a=power(3,n,m);
    if(a<=0) a+=m;
    out<<a-1;
    return 0;
}