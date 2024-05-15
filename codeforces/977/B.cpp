#include<bits/stdc++.h>
using namespace std;
#define GADO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
//#define int long long
#define ll long long
#define X first
#define Y second
#define all(x) x.begin(),x.end()
set<int> beg, smul;
#define begelment(n) cout<<*beg.upper_bound(n); // The first item is greater than me or equal to me
#define smalelment(n) cout<<*smul.lower_bound(n); // The first item is smaller than me
int  main() {
    int n;cin>>n;
    string s;cin>>s;
    map<string,int>mp;
    int mx=-1e9;
    string ans;
    for(int i=0;i<n-1;i++){
        string ss=s.substr(i,2);
        mp[ss]++;
        if(mp[ss]>mx) {
            mx=max(mx,mp[ss]);
            ans = ss;
        }
    }
    cout<<ans;
}
 	 	 			 	   		  		   			 		 	