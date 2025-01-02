#include <bits/stdc++.h>
using namespace std;

#define ull     unsigned long long
#define ll      long long
#define all     s.begin(), s.end()
#define pb      push_back
#define mp      make_pair

void solve(){
   int n;
   cin >> n;
   string question = "";
   for(int i = 0; i < n; i++){
    question += "BAN";
   }
   vector<pair<int,int>> v;

   int l = 1;
   int r = 3*n-1;

   while(l <= (3*n) / 2){
    v.pb(make_pair(l+1, r+1));
    l+=3;
    r-=3;
   }

   cout << v.size() << endl;
   for(const auto & i : v){
    cout << i.first << ' ' << i.second << endl;
   }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}

// CPJ
