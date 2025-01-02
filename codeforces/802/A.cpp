#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <chrono>
#include <random>
#include <climits>

using namespace std;

#define itn int
#define dsf dfs
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> have;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans = 0;
    for(int i=0;i<n;i++){
        if(count(have.begin(),have.end(),arr[i])){
            continue;
        }
        ans++;
        have.push_back(arr[i]);
        if(have.size() <= k){
            continue;
        }
        // cout<<"v: ";
        // for(auto v:have){
        //     cout<<v<<" ";
        // }
        // cout<<endl;
        vector<int> idxs;
        for(int j=0;j<have.size();j++){
            for(int k=i;k<=n;k++){
                if(k==n){
                    idxs.push_back(n);
                    break;
                }
                else{
                    if(arr[k] == have[j]){
                        idxs.push_back(k);
                        break;
                    }
                }
            }
        }
        // cout<<"idxs: ";
        // for(auto v:idxs){
        //     cout<<v<<" ";
        // }
        // cout<<endl;
        int mx = 0, best = 0;
        for(int j=0;j<have.size();j++){
            if(idxs[j] > mx){
                mx = idxs[j], best = j;
            }
        }
        have.erase(have.begin() + best);
    }
    cout<<ans<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    // cin >> t;
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve();
    }
}