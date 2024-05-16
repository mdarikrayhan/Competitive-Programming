#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
const int MAX = 2e9 + 23;
ll inf = 1e18 + 23;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    vector<ll> a(n);
    if(n == 1 or n == 2){
        cout << "No\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        a[i] = (i+1);
    }
    vector<ll> p(n);
    p[0] = a[0];
    for(int i = 1; i < n; i++){
        p[i] = a[i] + p[i-1];
    }
    ll first = 0;
    for(int i = 0; i < n; i++){
        if(__gcd(p[i], (p[n-1] - p[i])) != 1){
            first = i;
            break;
        }
    }
    cout << "Yes\n" << first+1 << " ";
    for(int i = 1; i <= first+1; i++){
        cout << i << " ";
    }
    cout << "\n" << n-first-1 << " ";
    for(int i = first + 2; i <= n; i++){
        cout << i << " ";
    }
    return 0;
}
 				  	 	 					 	  				 				