/**Love for others what you love for yourself.
–Prophet Muhammad (peace be upon him)**/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin() , a.rend()
#define no cout << "-1\n"
#define prnt(v) for(auto it : v) cout<<it<<" ";cout<<"\n";
#define db(x) cout << #x << " = " << x << " , " << '\n';
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
int ceil_div(int a, int b) { return a % b == 0 ? a / b : a / b + 1; }

void solve(){
    int n, i ,mx = LONG_LONG_MIN,mn = LONG_LONG_MAX;
    cin >> n;
    vector<int> v(n+2);
    for(i = 1; i <= n; i++){
        cin >> v[i];
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
    }
    if(mn == mx){
        no;
    }
    else{
        for(i = 1; i <= n; i++){
            if(v[i] == mx){
                if( (v[i-1] < mx && v[i-1] > 0) || ( v[i+1] < mx && v[i+1] > 0))
                    {cout << i << '\n';
                    return;}
            }   
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T=1;
    cin>>T;

    while(T--) 
        solve();

    return 0;
}
