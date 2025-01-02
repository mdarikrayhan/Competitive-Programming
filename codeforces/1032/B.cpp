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
#define ld long double
void solution(){
    string s;
    cin >> s;
    int n=  s.size();
    int a = 1e9 , b = a , plu = 1e9;
    for(int i = 0 ; i <= n ; i++){
        int h = n + i;
        for(int j = 1 ; j <= h ; j++){
            if(h % j == 0){
                int x = j;
                int y = h / j;
                if(x < 6 && a > x && y < 21){
                    a = x;
                    b = y;
                    plu = i;
                }
            }
        }
    }
    cout << a << " " << b << '\n';
    int l = 0;
    for(int i = 0 ; i < a ; i++){
        int k = 0;
        for(int j = 0 ; j < b ; j++){
            if(plu > 0 && k == 0){
                k++;
                plu--;
                cout << '*';
            }
            else{
                cout << s[l];
                l++;
            }
        }
        cout << '\n';
    }
}
signed main(){
    //cout << fixed << setprecision(8);
    //TXT
    babizhansturbo
    int t = 1;
	while(t--){
		solution();
		cout << '\n';
	}
}
