#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
const ll maxvalue=(1<<31)-1;
int main() {
     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
int t;
cin>>t;
while(t--){
    int n;cin>>n;int ans =0 ;
    map<ll,int>m;for(int i=0;i<n;i++) {ll temp;cin>>temp;if(m[maxvalue-temp]){ans++;m[maxvalue-temp]--;} else {m[temp]++;}}
    cout<<n-ans<<endl;
}
return 0;
}
