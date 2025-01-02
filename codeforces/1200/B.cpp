#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define forr(x, n) for (int i = x; i < n; i++)
#define ff first
#define ss second
#define pb push_back
#define nl '\n'
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                 \
    cout.tie(0);
 
const double PI = 3.141592653589793238462643383279502884197;
const int N = (int)1e6 + 5;
const ll inf = (ll)1e18 + 5;
const int mod = (int)1e9 + 7;


void solve(){
    int n, k;
    ll m;
    cin>>n>>m>>k;
    int a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    int idx = 1;
    for(int i = 0; i < n-1; i++){
        if(a[i]>=a[i+1]){
            ll diff = (a[i]-a[i+1])+min(k,a[i+1]);
            m+=diff;
        }
        else if(a[i+1]>a[i]){
            if(a[i+1]>(a[i]+k+m)){
                cout<<"NO\n";
                return;
            }
            else if(a[i+1]-a[i]<k){
                m += min(k-(a[i+1]-a[i]),a[i]);
            }
            else{
                m -= ((a[i+1]-a[i])-k);
            }
        }
        //cout<<m<<" ";
        if(m<0){
            cout<<"NO\n";
            return;
        }
        idx++;
    }
    if(idx==n){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}


int main(){
    faster;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
   	 						  	     			 			 		