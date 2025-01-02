#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

bool sec(const pair<int,int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

void solve(){
    int n, q; cin >> n >> q;
    int arr[n+9];
    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        v.pb({i, arr[i]});
    }
    sort(arr, arr + n);
    sort(v.begin(), v.end(), sec);
    vector<int> ck(32, 0);
    for(int i = 0; i < q; i++){
        int x; cin >> x;
        int srch = ceil(pow(2, x));
        int ind = 0;
        while(ind < n && ck[x] == 0){
            ind = lower_bound(arr+ind, arr + n, srch) - arr;
            if(ind < n && arr[ind]%srch == 0){
                arr[ind]+=(srch/2);
                v[ind].second = arr[ind];
            }
            ind++;
        }
        ck[x] = 1;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        cout << v[i].second << " ";
    }
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}