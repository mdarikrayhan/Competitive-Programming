//in the name of god

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int , int>
#define piii pair<pii , int>
#define F first
#define S second
#define pb push_back
#define all(vc) vc.begin(),vc.end()


const int maxx = 1e6+10;
const int Log = 21;
const int Mod = 1e9+7;
const int inf = 1e18+10;
const int SQ = 360;    

int n , q , a[maxx] , answ[maxx] , L[maxx] , R[maxx] , lmx[maxx];
pii fen[maxx];
vector<pii> query[maxx];
vector<int> askk[maxx] , resa[maxx];

void update(int v , pii a){

    for(;v<=n;v += (v & -v)){
        fen[v].F += a.F;
        fen[v].S += a.S;
    }
}
pii ask(int v)
{
    pii res = {0,0};
    for(;v;v -= (v & -v)){
        res.F += fen[v].F;
        res.S += fen[v].S;
    }
    return res;
}

void find_ans()
{
    stack<int> st;
    for(int i = 1 ; i <= n ; i++)resa[i].clear();

    for(int i = 1 ; i <= n ; i++){
        while(st.size() && a[i] >= a[st.top()]){
            st.pop();
        }    
        if(st.size() == 0){
            lmx[i] = -1;
            update(i , {i, -1});
        }

        else {
            lmx[i] = st.top();
            resa[lmx[i]].pb(i);
            update(i , {i-lmx[i]-1 , 0});
        }
        st.push(i);
    }

    
    

    for(int i = 1 ; i <= n ; i++){
        for(auto X : askk[i])
        {
            pii ans = ask(R[X]);
            
            answ[X] += ans.F + (ans.S)*i;
        }

        for(auto J : resa[i]){
            update(J , {i+1,-1});
        }
        update(i , {-i , 1});
    }
}

void solve(){
    cin>>n>>q;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i];
    }    
    for(int i = 1 ; i <= q ; i++){
        cin>>L[i];
    }
    for(int i = 1 ; i <= q ; i++){
        cin>>R[i];
        answ[i]+=R[i]-L[i]+1;
    }

    for(int i = 1 ; i <= q ; i++){
        askk[L[i]].pb(i);
    }
    
    find_ans();
    // cout<<"S";
    
    for(int i = 1; i <= n/2; i++)
		swap(a[i], a[n-i+1]);
    for(int i = 1; i <= n; i++)
		askk[i].clear();
    
    for(int i = 1; i <= q; i++) {
        swap(L[i], R[i]);
        L[i] = n-L[i]+1;
        R[i] = n-R[i]+1;
        askk[L[i]].pb(i);
    }
    find_ans();
    
    for(int i = 1 ; i <= q ; i++){
        cout<<answ[i]<<" "; 
    }
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--)solve();
}