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
//const int N=1e3+5;

int n, a, b;
bool can(int n, int a, int b, int mid) {
    int na = a / mid;
    int nb = b / mid;

    return na + nb >= n;
}

int main() {
    IOS;

    cin >> n >> a >> b;

    int l=1, r=min(a,b), ans=0;
    while (l<=r) {
        int mid=l+(r-l)/2;

        if (can(n, a, b, mid)) {
            ans=mid;
            l=mid+1;
        } 
        else r=mid-1;
    }

    cout << ans << endl;

    return 0;
}

	 			    		 					     							