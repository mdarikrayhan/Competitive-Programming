#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()

#define file \
  freopen("knapsack.in", "r", stdin);\
  freopen("knapsack.out", "w", stdout)

#define OJudge(in,out) \
      freopen(in, "r", stdin);\
      freopen(out, "w", stdout)


#define FIn   \
  cin.tie(0); \
  cout.tie(0); \
  ios_base::sync_with_stdio(false)

const string IN = "input.txt";
const string OUT = "output.txt";

int  tc;
ll arr[200100], pref[300100];
ll n,m,k,a,b,d,c;
string str, str1;
//cout<<fixed<<setprecision(10);
vector<ll> vect,vect2;
set <ll> st;



void solve(){
    cout<<fixed<<setprecision(10);
    cin>>n>>m;
    pair<int,int> frst,scnd;
    cin>>frst.first>>frst.second>>scnd.first>>scnd.second;
    cin>>a>>b;
    bool w = 0, h = 0;
    if (a + (scnd.first - frst.first) <= n)
        w = 1;
    if (b + (scnd.second - frst.second) <= m)
        h = 1;
    if (!w && !h){
        cout<<"-1\n";
        return;
    }
    double rslt = 1e8;
    if (w){
        int dis1 = n - scnd.first;
        if (dis1 >= a){
            cout<<0<<"\n";
            return;
        }
        rslt = min(rslt, double(a-dis1));
        if (frst.first >= a){
            cout<<0<<"\n";
            return;
        }
        rslt = min(rslt, double (a - frst.first));
    }

    if (h){
        int dis1 = m - scnd.second;
        if (dis1 >= b){
            cout<<0<<"\n";
            return;
        }
        rslt = min(rslt, double(b-dis1));
        if (frst.second >= b){
            cout<<0<<"\n";
            return;
        }
        rslt = min(rslt, double (b - frst.second));
    }
    cout<<rslt<<"\n";
}


int main() {
    FIn;
#ifndef ONLINE_JUDGE
    OJudge(IN.c_str(),OUT.c_str());
#endif
    //file;
    bool test = 1;
    if (test)
        cin>>tc;
    else tc = 1;
    while(tc--){
        solve();
    }
}