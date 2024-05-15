#include<bits/stdc++.h>
using namespace std;

//short forms

#define pb push_back
#define endl '\n'
#define int long long
#define F first
#define S second

const int MOD = 1e7 + 7;

signed main(){   
    (ios_base:: sync_with_stdio(false),cin.tie(NULL));
    #ifndef ONLINE_JUDGE   //if online judge is not defined
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
              
    int tc = 1;
    cin>>tc;
    //check();
    while(tc--){
         //-------------------------------start here ------------------------------------------------------//
        int n;
        cin>>n;
        if(n<2020){
            cout<<"NO"<<endl;
        }
        else{
            int r = n%2020;
            int d = n/2020;
            if(r>d){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}
