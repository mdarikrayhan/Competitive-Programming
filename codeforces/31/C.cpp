#include <bits//stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define V vector
#define VI V<int>
#define VL V<ll>
#define VP V<pair<int,int>>
#define rep(i, a, b, step) for (int i = int(a); i <= int(b); i+=step)
#define repl(i,a,b,step) for(int i=int(a);i>=int(b);i-=step)
#define sn <<'\n'
#define ed <<endl
#define sz size()
#define print cout<<
#define mpII map<int,int>
#define mine min_element
#define maxe max_element
#define mpIV map<int,VI>
#define mpLL map<ll,ll>
#define all(v) begin(v),end(v)
#define pb push_back
#define pq priority_queue
#define rev reverse
#define pk pop_back()
#define ff first
#define ss second
#define ts to_string
#define ub upper_bound
#define lb lower_bound
#define testcase int t;cin>>t;while(t--)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,l,r,cnt,p;
    cin>>n;
    V<pair<pair<int,int>,int>>s;
    VI a;
    rep(i,1,n,1){
        cin>>l>>r;s.pb({{l,1},i});s.pb({{r,-1},i});
    }
    sort(all(s));
    rep(i,1,n,1){
        cnt=0;p=1;
        for(auto j:s){
            if(j.ss!=i)cnt+=j.ff.ss;
            if(cnt>1)p=0;
        }
        if(p)a.pb(i);
    }
    print a.sz sn;
    for(auto& i:a)print i<<' ';
}