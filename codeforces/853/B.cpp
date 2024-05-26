#include <iostream>

#include <limits>
#include <vector>
#include <map>
#include <set>
#include <cmath>

typedef long long ll;

using namespace std;
typedef pair<ll, ll> pii;

ll N, M, K;

const ll INF = 1LL<<60;
const int MAX_D = (1e6)+1;

void solve() {
    cin>>N>>M>>K;

    vector<vector<pii>> to_capital(MAX_D, vector<pii>());
    vector<vector<pii>> from_capital(MAX_D, vector<pii>());

    for(int i=0; i<M; i++) {
        int d, f, t, c;
        cin>>d>>f>>t>>c;
        if(f == 0) {
            from_capital[d].push_back({t, c});
        } else {
            to_capital[d].push_back({f, c});
        }
    }


    vector<ll> L(MAX_D, INF);
    map<ll, ll> mins;
    ll cur_sum = 0;
    for(int i=1; i<MAX_D; i++) {
        L[i] = min(L[i], L[i-1]);
        for(int j=0; j<to_capital[i].size(); j++) {
            int city = to_capital[i][j].first;
            int cost = to_capital[i][j].second;

            if(mins.find(city) == mins.end()) {
                mins[city] = cost;
                cur_sum += cost;
            } else {
                if(cost < mins[city]) {
                    cur_sum -= (mins[city] - cost);
                    mins[city] = cost;
                }
            }
            if(mins.size() == N) {
                L[i] = cur_sum;
            }
        }
    }

    vector<ll> R(MAX_D, INF);
    mins.clear();
    cur_sum = 0;
    for(int i=MAX_D-2; i>=0; i--) {
        R[i] = min(R[i], R[i+1]);
        for(int j=0; j<from_capital[i].size(); j++) {
            int city = from_capital[i][j].first;
            int cost = from_capital[i][j].second;

            if(mins.find(city) == mins.end()) {
                mins[city] = cost;
                cur_sum += cost;
            } else {
                if(cost < mins[city]) {
                    cur_sum -= (mins[city] - cost);
                    mins[city] = cost;
                }
            }
            // cout<<"day "<<i<<" now city = "<<city<<" cost = "<<cost<<" mins.size() = "<<mins.size()<<" R[i] = "<<R[i]<<endl;
            if(mins.size() == N) {
                R[i] = cur_sum;
            }

        }
    }
    /*
    for(int i=0; i<=20; i++) {
        cout<<L[i]<<" ";
    }cout<<endl;
    for(int i=0; i<=20; i++) {
        cout<<R[i]<<" ";
    }cout<<endl;
    */

    ll ans = INF;
    for(int i=1; i+K<MAX_D; i++) {
        ans = min(L[i-1] + R[i+K], ans);
    }
    if(ans == INF ) {
        cout<<-1<<endl;
    } else{
        cout<<ans<<endl;
    }



}


int main() {
    // speed up
    ios::sync_with_stdio(0);
	cin.tie(0);

    solve();

    return 0;
}
