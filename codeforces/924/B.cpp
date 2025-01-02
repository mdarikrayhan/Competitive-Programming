#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define vi vector<int>
#define rep(i,a,b) for(int i = a; i < b; i++)
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
const ll mod = 1e9 + 7;
#include<bits/stdc++.h>
using namespace std;
//-----------------------------------------------------------------------------




int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); // this one for taking input
    freopen("o.txt", "w", stdout);   // this one for output
#endif
    int n,u;cin>>n>>u;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    
    int k=0;
    double answer=-1;
    for(int i=0;i<n-2;i++){
        while(k<n && v[k]-v[i]<=u){
            k++;
        }
        if(k-i <3){
            continue;
        }
        else{
            answer=max(answer,(double)(v[k-1]-v[i+1])/(v[k-1]-v[i]));
        }
    }
    cout.precision(20);
    cout<<answer<<endl;
}