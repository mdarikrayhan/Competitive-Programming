#pragma gcc diagnostic "-std=c++1z"
#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define f first
#define s second
#define MOD 1000000007
#define pii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
using namespace std;
int n,m,T,p;
void test_case() {
     cin>>n>>p;
     int t[n+1],ans[n+1];
     priority_queue<pair<pii,int>> e;
     for (int i=1; i<=n; i++) {
          cin>>t[i]; e.push({{-t[i],1},-i});
          ans[i]=-1;
     }
     deque<int> q; priority_queue<int> w;
     while (!e.empty()) {
          pair<pii,int> E=e.top(); e.pop();
          int tt=-E.f.f,k=-E.f.s,i=-E.s;
          if (k) {
               if (q.empty()) {
                    q.pb(i); e.push({{-(tt+p),0},-i});
               }
               else if (q.back()>i) q.pb(i);
               else w.push(-i);
          }
          else {
               ans[i]=tt; q.pop_front();
               if (q.empty()) {
                    if (w.empty()) continue;
                    q.pb(-w.top()); w.pop();
               }
               int j=q.front(); 
               e.push({{-(tt+p),0},-j});
          }
     }
     for (int i=1; i<=n; i++) cout<<ans[i]<<" "; cout<<endl;
}
main () {
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	T=1; 
	while (T--) test_case();
}
