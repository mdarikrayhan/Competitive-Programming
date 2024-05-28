#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<< #x <<" : "<<x<<endl;
#define dbgv(v) cout<< #v <<" : ";for(auto &i:v) cout<<i<<" ";cout<<endl;
#define endl '\n'
const int MOD = 1e9+ 7;
int seg[1000005];

int main() {
    ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
    int T = 1,i;
    cin>>T;
    while(T--) {
        //string S;
        //cin>>S;
        ll int N;
        cin>>N;
        ll int P=2*N;
        ll int X=360;
        ll int Q=__gcd(X,P);
        if(P+Q==X)
        {
            Q=Q/2;
        }
        cout<<360/Q<<endl;
    }
}