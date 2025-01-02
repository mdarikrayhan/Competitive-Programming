#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// ordered_set.find_by_order(k) returns the iterator to kth element
// ordered_set.order_of_key(k) returns the number of elements strictly less than k 

(FOR ORDERED MULTISET "UPPER_BOUND" AND "LOWER_BOUND" ARE REVERSED)
template<class T> using ordered_multiset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// ordered_set.find_by_order(k) returns the iterator to kth element
// ordered_set.order_of_key(k) returns the number of elements strictly less than k 
*/
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define fastio ios_base::sync_with_stdio(0)
#define flush_off cin.tie(0)
#define mod 1000000007
#define ganja 998244353



void solve()
{
    int n; cin>>n;
    int arr[n];
    for(auto &i:arr) cin>>i;
    // for(auto i:arr) cerr<<i<<endl;
    int ans = 0;
    while(1)
    {
        if(is_sorted(arr,arr+n)) break;
        ++ans;
        if(ans%2)
        {
            for(int i=1; i<n; i+=2)
            {
                if(arr[i-1]>arr[i]) swap(arr[i-1],arr[i]);
            }
        }
        else
        {
            for(int i=2; i<n; i+=2)
            {
                if(arr[i-1]>arr[i]) swap(arr[i-1],arr[i]);
            }
        }
    }  
    cout<<ans<<endl;
}

int main() {
    fastio;
    flush_off; //turn this off if cout needs to be flushed
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t=1; 
    cin>>t;
    while(t--)
    {
        solve();
    }
}