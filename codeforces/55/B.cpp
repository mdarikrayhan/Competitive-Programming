#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<< #x <<" : "<<x<<endl;
#define dbgv(v) cout<< #v <<" : ";for(auto &i:v) cout<<i<<" ";cout<<endl;
#define endl '\n'
const int MOD = 1e9+ 7;
int seg[1000005];

ll int func(vector<ll int>V,char P,char Q,char R){
    int count=0;
    if(P=='+'){count++;}
    if(Q=='+'){count++;}
    if(R=='+'){count++;}
    vector<ll int>ans;
    if(P==Q && Q==R){
        if(P=='*'){ ans.push_back(V[0]*V[1]*V[2]*V[3]);}
        else{ ans.push_back(V[0]+V[1]+V[2]+V[3]);}
    }
    else{
        if(count==2){
           if(P=='+' && Q=='+'){ ans.push_back((V[0]+V[1]+V[2])*V[3]); ans.push_back((V[0]+V[1])*(V[2]+V[3]));}
           else if(P=='+' && R=='+'){ ans.push_back((V[0]+V[1])*V[2] + V[3]); ans.push_back((V[0]+V[1])*(V[2]+V[3])); ans.push_back(V[0]+(V[1]*V[2]) + V[3]);}
           else if(Q=='+' && R=='+'){ ans.push_back((V[0]*V[1]) + (V[2]+V[3]));}
        }
        else{
            if(P==Q && Q=='*'){ ans.push_back((V[0]*V[1])*V[2] + V[3]); ans.push_back((V[0]*V[1]) + (V[2]*V[3]));}
            else if(P==R && R=='*'){ ans.push_back(((V[0]*V[1]) + V[2])*V[3]);}
            else if(Q==R && R=='*'){ ans.push_back((V[0]+V[1])*V[2]*V[3]);}
        }
    }
    ll int X=*min_element(ans.begin(),ans.end());
    return X;
}
int main() {
    ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
    int T = 1,i;
    while(T--) {
        ll int A,B,C,D; cin>>A>>B>>C>>D;
        char P,Q,R; cin>>P>>Q>>R;
        vector<ll int>V; V.push_back(A);V.push_back(B);V.push_back(C);V.push_back(D);
        vector<vector<ll int>>W; sort(V.begin(),V.end());
        do {
                W.push_back(V);
         } while (next_permutation(V.begin(),V.end()));
         ll int ans=1e18;
         for(int i=0;i<W.size();i++){ ll int X=func(W[i],P,Q,R); ans=min(ans,X);
         }
         cout<<ans<<endl;
    }
}