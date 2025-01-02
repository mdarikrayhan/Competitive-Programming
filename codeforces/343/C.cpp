#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool IsPossible(ll x, vector<ll>& a, vector<ll>& b){
    ll p = 0;
    for(ll i = 0;i<a.size();++i){
        ll z  = x;
        ll prev = a[i];
        ll d = abs(b[p]-prev);
        while(z>=abs(b[p]-prev) || (z-abs(b[p]-prev)+d-abs(b[p]-a[i])>=0)){
            z-=abs(b[p]-prev);
            prev = b[p];
            p++;
            if(p>=b.size())return true;
        }
    }
    return false;
}
ll Bins(ll x,ll y, vector<ll>& a, vector<ll>& b){
    if(x==y)return x;
    ll mid = (x+y)/2;
    if(IsPossible(mid,a,b))return Bins(x,mid,a,b);
    return Bins(mid+1, y,a,b);
}
int main() {
	ll n,m;cin>>n>>m;
	vector<ll> a(n);
	vector<ll> b(m);
	for(ll i=0;i<n;++i){
	    cin>>a[i];
	}
	for(ll i=0;i<m;++i){
	    cin>>b[i];
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	cout<<Bins(0,pow(10,17),a,b);
	
}
