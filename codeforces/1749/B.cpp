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
   vector<int> v(n), v2(n);
   int maximum = 0;
   ull cnt = 0;
   ull cnt2 = 0;

   for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt += v[i];
   }

   for(int i = 0; i < n; i++){
    cin >> v2[i];
    if(v2[i] > maximum){
        maximum = v2[i];
    }
    cnt2 += v2[i];
   }

   cnt2 -= maximum;
   cout << cnt + cnt2;
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
