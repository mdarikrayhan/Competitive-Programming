#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<ld> vd;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define forn(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b,c) for(int i=a;i<b;i+=c)
#define SORT(v) sort((v).begin(),(v).end())
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define pb push_back
#define pp pop_back
#define nl "\n"

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
        ll n;
	    cin>>n;
	    vll a(n);
        forn(i,n)
	        cin>>a[i];
        SORT(a);
        cout<<a[n-1]+a[n-2]-a[0]-a[1]<<nl;
        /*
        bool ans=true;
        if(ans)
            cout<<"YES"<<nl;
        else
            cout<<"NO"<<nl;
        */
	}
	return 0;
}
