/*
• ▌ ▄ ·.        ▄ .▄ ▄▄▄·  ▐ ▄  ▐ ▄  ▄▄▄· ·▄▄▄▄       ▄▄▄· ▄ •▄ 
·██ ▐███▪▪     ██▪▐█▐█ ▀█ •█▌▐█•█▌▐█▐█ ▀█ ██▪ ██     ▐█ ▀█ █▌▄▌▪
▐█ ▌▐▌▐█· ▄█▀▄ ██▀▐█▄█▀▀█ ▐█▐▐▌▐█▐▐▌▄█▀▀█ ▐█· ▐█▌    ▄█▀▀█ ▐▀▀▄·
██ ██▌▐█▌▐█▌.▐▌██▌▐▀▐█ ▪▐▌██▐█▌██▐█▌▐█ ▪▐▌██. ██     ▐█ ▪▐▌▐█.█▌
▀▀  █▪▀▀▀ ▀█▄▀▪▀▀▀ · ▀  ▀ ▀▀ █▪▀▀ █▪ ▀  ▀ ▀▀▀▀▀•      ▀  ▀ ·▀  ▀
*/

#include <bits/stdc++.h>
using namespace std;

#define IOS                                 \
        ios_base::sync_with_stdio(0);       \
        cin.tie(0);                         \
        cout.tie(0)
#define ll long long
//#define int long long
#define all(v) v.begin(),v.end()
#define INF numeric_limits<int>::max()
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int N=1e3+5;

int main(){
    IOS;

    int n; cin>>n;
    vector<pair<int,int>> a(n); for(int i=0;i<n;i++)cin>>a[i].first, a[i].second=i+1;
    sort(all(a));
    if(a[0].first==a[1].first) cout<<"Still Rozdil";
    else cout<<a[0].second;
    return 0;
}
 	 	  				     		 	 					 		 	