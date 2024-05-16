/*
 * author: saifabrar
 * created: 2024-05-16 22:43:18
 * problem link: 
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'
#define pii pair<ll, ll>

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i+=2){
        for(int j=1;j<=m;j++){
            cout<<i*m+j<<" ";
        }
        cout<<nl;
    }
    for(int i=0;i<n;i+=2){
        for(int j=1;j<=m;j++){
            cout<<i*m+j<<" ";
        }
        cout<<nl;
    }
    cout<<nl;
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
				    		      	  		 		  		 		