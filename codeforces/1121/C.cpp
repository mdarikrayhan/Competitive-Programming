#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c> {i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
    ~debug() { cerr << endl; }
    eni( != ) cerr << boolalpha << i; ris;
}
eni( == ) ris << range(begin(i), end(i));
}
sim, class b dor(pair < b, c > d) {
    ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
        *this << ", " + 2 * (it == d.b) << *it;
    ris << "]";
}
#else
    sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
#define int long long
void test_case(){   
   int n, k;
   cin >> n >> k;
   vector<int> a(n + 1);
   int ans = 0;
   for(int i = 1; i <= n; i++){
    cin >> a[i];
   }
   vector<pair<int, int>> testati;
   vector<bool> good(n + 1);
   for(int i = 1; i <= min(n, k); i++){
    testati.push_back({a[i], i});
   }
   int finiti = 0;
   int val = 0;
   int pos = k + 1;
   while((int)testati.size() > 0){
    vector<pair<int, int>> nxt;
    debug() << imie(val) imie(testati) imie(finiti) imie(ans);
     for(int i = 0; i < (int)testati.size(); i++){
         int ora = testati[i].first - 1;
         int fatti = a[testati[i].second] - ora;
         if(fatti == val){
            good[testati[i].second] = true;
         } 
         if(ora > 0){
            nxt.push_back({ora, testati[i].second});
         }
         else{
            finiti++;
         }
     }
     double vald = ((double)(100 * finiti) / n) + 0.5;
     val = floor(vald);
     //debug() << imie(vald) imie(val);
     while(pos <= n && (int)nxt.size() < k){
        nxt.push_back({a[pos], pos});
        pos++;
     }
     testati = nxt; 
   }
   for(int i = 1; i <= n; i++){
    ans += good[i];
   }
   cout << ans << '\n';
}
int32_t main() {
 ios::sync_with_stdio(false);
 cin.tie(0);
 int t;
 t = 1;
 while(t--){
     test_case();
 }
}

// 1, 100,  50 200


