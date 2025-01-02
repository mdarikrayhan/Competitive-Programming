#include <bits/stdc++.h>
#define int long long  
#define PII pair<int,int>
#define PCI pair<char,int>
#define PSI pair<string,int>
#define lowbit(x) x&-x
using namespace std;
using LL = long long;
using ULL = unsigned long long;

const int N = 2e5;
int MOD = 998244353;
const int INF = 1e18;
const ULL base = 13331; 


vector<vector<int>> D(N+10);

void solve(){
    int l,r; cin>>l>>r;
    int len=r-l+1;
    int ans=len*(len-1)*(len-2)/6;
    for(int k=l+2;k<=r;k++){
        int cnt=0;
        for(int v:D[k]){
            if(l<=v && v<k){
                cnt++;
            }
        }
        //cout << "k: " << k << " cnt: " << cnt << "\n";
        ans-=cnt*(cnt-1)/2;
        if(k%3==0){
            if(k%5==0 && 2*k/5>=l) ans--;
            if(k%2==0 && k/2>=l) ans--;
        }
    }
    cout << ans << "\n";
}    
signed main (){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            D[j].push_back(i);
        }
    }
    int Task=1; cin>>Task;
    for(int T=1;T<=Task;T++){
        //cout << "Test: " << T << "\n";
        solve();
    }
    return 0;
}


/*

*/
