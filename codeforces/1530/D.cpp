#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;

void solve(){  
    int n;
    cin >> n;
    vector<int> a(n + 1),b(n + 1);
    vector<vector<int>> w(n + 1);
    set<int> s;
    for(int i = 1;i <= n;i++){
        cin >> b[i];
        w[b[i]].push_back(i);
        s.insert(i);
    }
    for(int i = 1;i <= n;i++){
        if(s.count(b[i])){
            s.erase(b[i]);
            a[i] = b[i];
        }
    }
    int k = n - s.size();
    for(int i = 1;i <= n;i++){
        if(!a[i]){
            a[i] = *s.begin();
            s.erase(s.begin());
        }
    }
    for(int i = 1;i <= n;i++){
        if(a[i] == i){
            for(auto j : w[b[i]]){
                if(j != i){
                    swap(a[i],a[j]);
                    break;
                }
            }
        }
    }
    cout << k << endl;
    for(int i = 1;i <= n;i++)cout << a[i] << " ";
    cout << endl;
    
    
    

} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}