#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<string>
#include<set>
#include<queue>
using namespace std;
using ll = long long;
using db = double;
#define V vector
#define VI V<int>
#define VL V<ll>
#define VIV V<VI>
#define VPII V<pair<int,int>>
#define VD V<double>
#define rep(i, a, b, step) for (int i = int(a); i <= int(b); i+=step)
#define repl(i,a,b,step) for(int i=int(a);i>=int(b);i-=step)
#define sn <<'\n'
#define ed <<endl
#define sz size()
#define print cout<<
#define mpII map<int,int>
#define mpIP map<int,pair<int,int>>
#define mpPI map<pair<int,int>,int>
#define mine min_element
#define maxe max_element
#define mpIV map<int,V<int>>
#define mpLL map<ll,ll>
#define mpLP map<ll,pair<ll,rr>>
#define mpPL map<pair<ll,ll>,ll>
#define all(v) begin(v),end(v)
#define pb push_back
#define pq priority_queue
#define rev reverse
#define pk pop_back()
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define testcase int t;cin>>t;while(t--)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    VI a(n), b(3002);
    for (auto& i : a)cin >> i, b[i]++;
    for (int i = 1; i <= 3001; i++) {
        if (!b[i]) {
            print i;
            return 0;
        }
    }
}