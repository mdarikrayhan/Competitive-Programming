#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define sz(x) (int)(x.size())
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef priority_queue <ll, vector<ll>, greater<ll>> pqmin;
const double EPS = 1e-16;
const ll INF = 1e18;
const int MOD = 1e9+7;

const int p=1e5+5;
int ans[p];

void solve(){
    int n,q;
    cin>>n>>q;
    vector<pll>op(n);
    for(int i=0;i<n;i++){
        cin>>op[i].fs>>op[i].sc;
        if(op[i].fs==2){
            op[i].sc++;
        }
    }
    priority_queue<pll>pq;
    for(int i=0;i<q;i++){
        ll k;
        cin>>k;
        pq.push({k,i});
    }
    ll tot=0;
    for(int i=0;i<n;i++){
        if(tot>INF){
            reverse(op.begin(),op.begin()+i);
            n=i;
            break;
        }
        if(op[i].fs==1){
            tot++;
        }else{
            ll mxmmul=(INF+tot-1)/tot;
            if(op[i].sc>mxmmul){
                reverse(op.begin(),op.begin()+i);
                n=i;
                break;
            }
            tot*=op[i].sc;
        }
        if(i==n-1){
            reverse(op.begin(),op.end());
            break;
        }
    }
    while(true){
        pll tp=pq.top();
        ll idx=tp.sc;
        ll val=tp.fs;
        if(val>tot){
            pq.pop();
            if(val%tot==0){
                pq.push({tot,idx});
            }else{
                pq.push({val%tot,idx});
            }
        }else{
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(pq.empty())break;
        pll tp=pq.top();
        ll idx=tp.sc;
        ll val=tp.fs;
        if(op[i].fs==1){
            while(!pq.empty()){
                tp=pq.top();
                idx=tp.sc;
                val=tp.fs;
                if(tot!=val)break;
                ans[idx]=op[i].sc;
                pq.pop();
            }
            tot--;
        }else{
            ll g=tot/op[i].sc;
            while(true){
                tp=pq.top();
                idx=tp.sc;
                val=tp.fs;
                if(val<=g)break;
                pq.pop();
                if(val%g==0){
                    pq.push({g,idx});
                }else{
                    pq.push({val%g,idx});
                }
            }
            tot/=op[i].sc;
        }
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    cin.get();
    return 0;
}
