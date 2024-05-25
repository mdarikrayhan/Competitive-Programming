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
    vector<pair<pair<int,int>, int>> arr;
    for(int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        arr.push_back({{a,-b}, i+1});
    }
    sort(arr.begin(), arr.end());
    for(int i=1; i<n; i++){
        if(-arr[i].first.second <= -arr[i-1].first.second) {cout << arr[i].second << " " << arr[i-1].second << endl; return;}
    }
    cout << "-1 -1\n";
    return; 
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    solve();
}