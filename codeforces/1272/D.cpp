#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<int,int> pii;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN = 2e5 + 7;
int arr[MAXN];
int st[MAXN], nd[MAXN];
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	int st_point = 1;
	int ans = 0;
	for(int i=2;i<=n + 1;++i){
		if(arr[i] <= arr[i - 1]){
			for(int j=st_point;j<=i - 1;++j){
				st[j] = st_point;
				nd[j] = i - 1;
			}
			ans = max(ans, i - st_point);
			st_point = i;
		}
	}
	for(int i=2;i<=n - 1;++i){
		if(arr[i - 1] < arr[i + 1]) ans = max(ans, nd[i + 1] - st[i - 1]);
	}
	cout << ans << "\n";
}
