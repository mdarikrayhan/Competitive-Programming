#include<bits/stdc++.h>
#include <chrono>
#include <random>

using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) {
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ll long long
#define fo(i, n) for(i=0;i<n;i++)
#define deb(x) cout<< #x << "=" << x <<endl;
#define deb2(x, y) cout<< #x <<"="<< x<<","<< #y << "=" <<y<<endl;
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define mem(x) memset(x,0,sizeof(x))
#define itr(it,a) for(auto it=a.begin(); it!=a.end(); it++)
#define Fast_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
ll  mod = 1e9 + 7;




//Compute all subset sum

ll m;

vector<ll>get_subset_sum(ll l, ll r, vector<ll>&a) {

    ll len = r - l + 1;
    vector<ll>res;

    for (int i = 0; i < (1 << len); i++) {

        ll sum = 0;

        for (int j = 0; j < len; j++) {

            if (i & (1 << j))sum += a[l + j];
        }

        res.push_back(sum % m);
    }

    return res;
}


int main()
{
    ll t, i, n, target;

    cin >> n >> m;

    vector<ll>a(n);

    for (i = 0; i < n; i++)cin >> a[i];



    vector<ll>left = get_subset_sum(0, n / 2 - 1, a);
    vector<ll>right = get_subset_sum(n / 2, n - 1, a);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    ll ans = 0;

    target = m;

    for (i = 0; i < left.size(); i++) {

        ans = max(ans, left[i]);
    }

    for (i = 0; i < right.size(); i++)ans = max(ans, right[i]);

    for (i = 0; i < left.size(); i++) {

        if (left[i] <= target)ans = max(left[i], ans);

        ll need = target - left[i];

        //    deb2(left[i], need);


        ll idx = lower_bound(right.begin(), right.end(), need) - right.begin();

        idx--;

        if (idx >= 0) {

            ll cur = left[i] + right[idx];

            ans = max(cur, ans);
        }

    }

    cout << ans << endl;



}
