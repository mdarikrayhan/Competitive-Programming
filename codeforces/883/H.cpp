#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pi;

#define endl "\n"
#define INF 1e18

const int mod = 1e9+7;




int check(string& odd, string& even, int k){
    int n = 2*even.size() + odd.size();
    int sz = n/k;
    vector<string> estr(k);
    // vector<string> ostr(k);
    if(sz%2==0){
        if(odd.size()==0){
            // possible
        }
        else{
            return 0;
        }
    }
    else{
        if(odd.size()<=k && (k-odd.size())%2==0){
            // possible
        }
        else{
            return 0;
        }
    }

    for(int i=0; i<k; i++){
        estr[i] = even.substr(i*(sz/2), sz/2);
    }
    int e = k*(sz/2);
    while(e<even.size()){
        odd.push_back(even[e]);
        odd.push_back(even[e]);
        e++;
    }
    cout << k << endl;
    for(int i=0; i<k; i++){
        cout << estr[i];
        reverse(estr[i].begin(), estr[i].end());
        if(i<odd.size()) cout << odd[i];
        cout << estr[i] << " ";
    }
    cout << endl;
    return 1;
}



void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char,int> mp;
    for(int i=0; i<n; i++){
        mp[s[i]]++;
    }

    string odd, even;
    for(auto x:mp){
        if(x.second%2==1){
            odd.push_back(x.first);
            x.second--;
        }
        x.second /= 2;
        for(int i=0; i<x.second; i++){
            even += x.first;
        }
    }


    // cout << even << endl;
    // cout << odd << endl;

    set<int> divs;
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            divs.insert(i);
            divs.insert(n/i);
        }
    }

    for(auto k:divs){
        if(check(odd, even, k)) return;
        // cout << k << " "; 
    }
    // cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int ncases=1;
    // cin >> ncases;
    while(ncases--){
        solve();
    }
}
