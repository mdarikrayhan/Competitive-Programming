#include <bits/stdc++.h>
using namespace std;
#define runLP4 cin.tie(nullptr); ios_base::sync_with_stdio(false);
#define ll long long
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pair<int,int>>
#define vb vector<bool>
#define pb push_back
#define for1(i,fst,scd) for(int i=fst;i<scd;i++)
#define for2(i,fst,scd) for(int i=fst;i<=scd;i++)
#define sii cout<<"YES\n";
#define nop cout<<"NO\n";

void solve(){
	ll n, k; cin>>n>>k;
	if(k*k>n) nop
	else if(n%2==k%2){
		sii
	} else {
		nop
	}
}

int main() {
    runLP4
    int t = 1; cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}
