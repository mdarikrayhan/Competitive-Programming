#include<bits/stdc++.h>
using namespace std;
#define MAX __INT64_MAX__
#define int long long int
#define endl "\n"
#define OUT(i) {cout << i << endl; return;}
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}


int ceil(int a, int b){
    if(a%b==0) return (a/b);
    else return (a/b)+1;
}

void solve(){
    int n; cin >> n;
    vector<pair<pair<int,int>, int>> arr(n, {{0,0},0});
    for(int i=0; i<n; i++){
        cin >> arr[i].first.first;
        cin >> arr[i].first.second;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    int max_ = arr[0].first.second;
    int maxi=-1;
    for(int i=1; i<n; i++){
        if(arr[i].first.first > max_) {maxi=i; break;}
        max_ = max(max_, arr[i].first.second);
    }
    if(maxi<0) OUT(-1)
    int ans[n];
    for(int j=0; j<n; j++){
        if(arr[j].first.first < arr[maxi].first.first) ans[arr[j].second] = 1;
        else ans[arr[j].second] = 2;
    }
    for(int j=0; j<n; j++){
        cout << ans[j] << " ";
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int tiger; cin>>tiger;
    for(int lion=0; lion<tiger; lion++){
        solve();
    }
}