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
const int INF = 2e9;
const int MOD = 1e9+7;

const int p=1e5+5;
const int sqrtp=sqrt(p);
ll suf[sqrtp+5][p];
ll sum[sqrtp+5][p];
ll a[p];

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sqrtn=sqrt(n);
    for(int i=sqrtn;i>0;i--){
        for(int j=n;j>0;j--){
            int scl=(j+i-1)/i;
            suf[i][j]=0;
            sum[i][j]=0;
            if(j+i<=n){
                suf[i][j]=suf[i][j+i];
                sum[i][j]=sum[i][j+i];
            }
            suf[i][j]+=a[j]*scl;
            sum[i][j]+=a[j];
        }
    }
    for(int i=0;i<q;i++){
        int s,d,k;
        cin>>s>>d>>k;
        if(d>sqrtn){
            ll ans=0;
            ll g=1;
            for(int j=s;j<=n;j+=d){
                ans+=a[j]*g;
                g++;
                if(g>k)break;
            }
            cout<<ans<<" ";
        }else{
            ll ans=suf[d][s];
            if(s+k*d<=n){
                ans-=suf[d][s+k*d];
            }
            ll scl=(s+d-1)/d;
            ll sb=sum[d][s];
            if(s+k*d<=n){
                sb-=sum[d][s+k*d];
            }
            ans-=(scl-1)*sb;
            cout<<ans<<" ";
        }
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
