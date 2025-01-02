#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll pow10[11];
    pow10[0]=1;
    for (ll i=1; i<11; ++i) {
        pow10[i]=pow10[i-1]*10;
    }
    int t; cin >> t;
    while (t--) {
        ll A, B, C, k; cin >> A >> B >> C >> k;
        ll st=1;
        ll resa=-1;
        ll resb;
        for (ll a=pow10[A-1]; a<pow10[A]; ++a) {
            ll lo=pow10[B-1], hi=pow10[B]-1;
            while (lo<hi) {
                ll mi=(lo+hi)/2;
                if (a+mi>=pow10[C-1]) {
                    hi=mi;
                } else {
                    lo=mi+1;
                }
            }
            ll flo=lo;
            lo=pow10[B-1];
            hi=pow10[B]-1;
            while (lo<hi) {
                ll mi=(lo+hi+1)/2;
                if (a+mi<pow10[C]) {
                    lo=mi;
                } else {
                    hi=mi-1;
                }
            }
            ll fhi=lo;
            if (flo<=fhi && pow10[C-1]<=a+flo && a+flo<pow10[C] && pow10[C-1]<=a+fhi && a+fhi<pow10[C]) {
                ll ct=fhi-flo+1;
                if (st<=k && k<st+ct) {
                    resa=a;
                    resb=flo+(k-st);
                    break;
                }
                st+=ct;
            }
        }
        if (resa==-1) {
            cout << "-1\n";
        } else {
            cout << resa << " + " << resb << " = " << resa+resb << '\n';
        }
    }
    return 0;
}
