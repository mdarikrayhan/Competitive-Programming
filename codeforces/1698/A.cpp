 
//
// Created by gansukh on 5/10/24.
// 
#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;

#define OUT(x) cout << (x) << "\n";
#define OUTA OUT(ans);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, mul;
    vi a;
    cin >> t;
    while (t--) {
        mul = 0;
        cin >> n;
        a.resize(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
            mul ^= a[i];
        };
        for(int i=0;i<n;i++){
            if(mul ^ a[i] == a[i]){
                OUT(a[i]);
                break;
            }
        }
    }
 
    return 0;
}

