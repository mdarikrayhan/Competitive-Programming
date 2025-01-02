#include<bits/stdc++.h>
#define pb push_back
#define LL long long
#define int long long
#define MP make_pair
#define F first
#define S second
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define inf LLONG_MAX
#define all(x) (x).begin(),(x).end()
#define endl "\n"
using namespace std;
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.F != b.F)return (a.F < b.F);
    else return (a.S < b.S);
}
void solve(){
    int n,m;
    string s;
    cin>>n;
    vector<int> a(n),b;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    b=a;
    sort(all(b));
    for(int i=0; i<n; i++) {
        if(a[i]!=b[n-1]) {
            cout<<b[upper_bound(all(b),a[i])-b.begin()]<<" ";
        }
        else {
            cout<<b[0]<<" ";
        }
    }cout<<endl;

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}