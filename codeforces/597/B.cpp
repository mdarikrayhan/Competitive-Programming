#include <bits/stdc++.h>
 
#define ll                              long long int
#define vr                              vector
#define pb                              push_back
#define pf                              push_front
#define ppb                             pop_back
#define pii                             pair<ll, ll>
#define vri                             vector <ll>
#define vrs                             vector <string>
#define take1(arr,n)                    for(int i=1; i<=n; i++){ll A; cin>>A; arr[i]=A;}
#define take(arr,n)                     for(int i=0; i<n; i++){ll A; cin>>A; arr[i]=A ;}
#define takevrs(arr,n)                  for(int i=0; i<n; i++){string s; cin>>s; arr[i]=s;}
#define showpair(v)                     for(auto [f , s]:v){ cout<<f<<" "<<s<<"\n";} cout<<"\n";
#define takesum(arr,n,sum)              for(int i=0; i<n; i++){ll A; cin>>A; arr[i]=A; sum+=A;}
#define take1sum(arr,n,sum)             for(int i=1; i<=n; i++){ll A; cin>>A; arr[i]=A; sum+=A;}
#define takecount(arr,n,count)          for(int i=0; i<n; i++){ll A; cin>>A; arr[i]=A; count[A]++;}
#define take1count(arr,n,count)         for(int i=1; i<=n; i++){ll A; cin>>A; arr[i]=A; count[A]++;}
#define dsort(arr)                      sort(arr.begin() , arr.end() , greater<int>())
#define mp                              make_pair
#define show(arr)                       for(auto i:arr) cout<< i <<" ";  cout << "\n";
#define show1(arr,n)                    for(int i = 1; i<=n; i++)   cout << arr[i]<<" "; cout<<"\n";
#define all(v)                          v.begin(),v.end()
#define takepairii(v,n)                 for(ll i=0; i<n; i++){ ll x; ll y;cin>>x>>y; v.pb(mp(y,x)); }
#define take2d(a , n , m)               for(int i = 1; i <= n; i++){for(int j = 1; j <= m; j++)  cin >> a[i][j];}
#define mod                             1000000007
using namespace std;


void solve(){
    
    ll n , dish = 0 , lastFinished = -1;
    cin >> n;

    vr < pii > v;
    takepairii(v , n);

    sort(all(v));

    for(int i = 0; i < n; i++){

        if(lastFinished < v[i].second){
            
            dish++;
            lastFinished = v[i].first;
        }
    }
    cout << dish;
    
}
 
int main(){
    
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
    // ll tc;
    // cin>>tc;
    // while(tc--){
    //     solve();
    // }
}