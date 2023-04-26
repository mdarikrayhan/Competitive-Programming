#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2e5+4;
const int N1 = 5e2+4;

struct Sqrt{
ll n,k,ans;
ll a1[N],a2[N]; // a1 = 0,1 		a2 = x
ll a3[N1],a4[N1],a5[N1],a6[N1]; // [a3 = #a1 = 1] [a4 = x] [a5 = sum] [a6 = sum^2]

void build(int _n,int _k){ n = _n, k = _k;

}

void up(int l,int r,ll val){ int id = (l-1)/k;
a1[l-1] += val, a3[id] += val, a5[id] += val*a2[l-1], a6[id] += val*a2[l-1]*a2[l-1];
for (int i=l/k,il,ir; i<=r/k && l<=r; i++){ il = i*k, ir = min(n-1, il+k-1);
if (l <= il && ir <= r) a4[i] += val;
else{ a5[i] = a6[i] = 0;
for (int j=max(l, il); j<=min(r, ir); j++) a2[j] += val;
for (int j=il; j<=ir; j++) if (a1[j])
a5[i] += a2[j], a6[i] += a2[j]*a2[j];
}
}
ans = 0;
for (int i=0; i<=(n-1)/k; i++)
ans += a6[i] + (2*a4[i]-1)*a5[i] + (a4[i]*a4[i]-a4[i])*a3[i];
cout << ans/2 << "\n";
}

} d1;

int n,q,d;

void go(){
cin >> q >> d; n = 2e5; d1.build(n, 450);

for (int x; q; q--){ cin >> x; x--;
d1.up(x+1, min(n-1, x+d), d1.a1[x] ? -1 : 1);
}
}

int main(){
// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int t=1;
// cin >> t;
for (int i=0; i<t; i++) go();

return 0;
}