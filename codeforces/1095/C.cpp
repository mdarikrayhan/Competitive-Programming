#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 1e9+7;
const long long INF = 1e18;

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //#ifndef ONLINE_JUDGE
        //freopen("inputf.in","r",stdin);
        //freopen("outputf.in","w",stdout);
    //#endif
}

void solve(){
    int n,k;
    cin >> n >> k;

    priority_queue<int> pq;

    for(int i=0;i<62;i++){
        if((n>>i)&1){
            pq.push((1LL<<i));
        }
    }
    if(pq.size()>k){
        cout << "NO" << endl;
        return;
    }

    while(pq.size()<k){
        auto curr = pq.top();
        if(curr==1) break;
        pq.pop();

        pq.push(curr/2);
        pq.push(curr/2);
    }

    if(pq.size()==k){
        cout << "YES" << endl;
        while(pq.size()){
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
    

}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}