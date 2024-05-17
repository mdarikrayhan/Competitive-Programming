#include<bits/stdc++.h>
using namespace std;
#define babizhansturbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#pragma GCC optimize("Ofast")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define TXT freopen ("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
using namespace __gnu_pbds;
const int MOD = 1e9 + 7;
#define int long long
void solution(){
    int n;
    cin >> n;
    int a[n];
    int kol = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    vector<int>first;
    vector<int>second;
    vector<int>third;
    int l = 0 , r = n - 1;
    while(l < r){
        kol += 6;
        for(int i = 0 ; i < 6 ; i++){
            if(i % 2){
                first.push_back(2);
            }
            else{
                first.push_back(1);
            }
            second.push_back(l + 1);
            third.push_back(r + 1);
        }
        l++;
        r--;
    }
    cout << kol << '\n';
    for(int i = 0 ; i < kol ; i++){
        cout << first[i] << " " << second[i] << " " << third[i] << '\n';
    }
}
signed main(){
    //TXT
    babizhansturbo
    int t;
    cin >> t;
	while(t--){
		solution();
	}
}
