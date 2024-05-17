#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define f(i,x,y) for(int i=x;i<y;i++)
#define f2(i,x,y) for(int i=x;i>=y;i--)
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tup tuple<int,int,int>
const int MOD =1e8;
const int INF = 9999999;
const int N = 2e5;
void _debug(vector<pair<int,int>>&v){for(auto it : v)cout << it.ff << " " << it.ss << endl;}

void solve(int tc){

    int n,m; cin >> n >> m;

    vector<int>v(n); for(int i=0;i<n;i++)cin >> v[i];

    int k; cin >> k;

    vector<int>w(k); for(int i=0;i<k;i++)cin >> w[i];

    vector<pair<int,int>>a,b;

    for(int i=0;i<n;i++){

        int cnt=1;
        
        while(v[i]%m==0){
            
            v[i]/=m;
            
            cnt*=m;
        }
        
        a.pb({v[i],cnt});
    }

    for(int i=0;i<k;i++){

        int cnt=1;
        
        while(w[i]%m==0){
            
            w[i]/=m;
            
            cnt*=m;
        }
        
        b.pb({w[i],cnt});
    }

    int aa = a.size(),bb = b.size();
    
    //for(auto it : a)cout << it.ff << " " << it.ss << endl;

    int i=0,j=0;

    while(i < aa and j < bb){

        //cout << a[i].ff << " " << b[j].ff << endl;

        if(a[i].ff != b[j].ff){

            cout << "No" << endl;

            return;
        }

        if(a[i].ss == b[j].ss){

            a[i].ss = 0;

            b[j].ss = 0;

            i++;

            j++;
        }
        else if(a[i].ss > b[j].ss){

            a[i].ss -= b[j].ss;

            b[j].ss = 0;

            j++;
        }
        else {

            b[j].ss -= a[i].ss;

            a[i].ss = 0;

            i++;
        }
    }

    bool f = 0;

    for(int i=0;i<aa;i++){

        f |= a[i].ss!=0;
    }

    for(int i=0;i<bb;i++){

        f |= b[i].ss!=0;
    }

    cout << (!f?"Yes":"No") << endl;
}
int32_t main(){

    Fast

    int t=1;

    cin >> t;

    for(int tc=1;tc<=t;tc++){

        solve(tc);
    }
}