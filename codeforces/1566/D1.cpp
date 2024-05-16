#include<bits/stdc++.h>
using namespace std;
#define babizhansturbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#pragma GCC optimize("Ofast")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define TXT freopen ("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
using namespace __gnu_pbds;
#define int long long
const int MOD = 1e9 + 7;
void solution(){
    int n , m;
    cin >> n >> m;
    int a[m] , b[m];
    vector<int>ans(m + 100);
    for(int i = 0  ; i< m ;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    map<int , int>bib;
    sort(b , b + m);
    int h = 0;
    for(int i = 0 ; i < m ; i++){
        int kol = 0;
        for(int j =0 ; j < i ; j++){
            if(a[i] > a[j]){
                kol++;
            }
        }
        h =h + kol;
    }
    cout << h;
}
signed main(){
    //cout << fixed << setprecision(8);
    //TXT
    babizhansturbo
    int t;
    cin >> t;
	while(t--){
		solution();
		cout << '\n';
	}
}
