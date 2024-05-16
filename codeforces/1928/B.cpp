
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    
    vector<ll> arr;
    unordered_set<ll> st;
    ll x;
    
    for(int i = 0; i < n; ++i)
    {
        cin >> x;
        
        if(st.count(x) == false)
        {
            arr.push_back(x);
            st.insert(x);
        }
    }
    
    sort(arr.begin(), arr.end());
    
    ll l = 0;
    ll r = 0;
    
    ll ans = 1;

    while(r < arr.size())
    {
        if(arr[r] - arr[l] <= n-1)
        {
            ans = max(ans, r-l+1);
            r++;
        }
        else
            l++;
    }
    cout << ans << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;

	while(t--)
	{
    	solve();
	}
	
	return 0;
}