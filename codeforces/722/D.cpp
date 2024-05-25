                    //INCLUDING..
#include "bits/stdc++.h"

                    //DEFINING..
#define LL               long long
#define ull              unsigned long long
#define LD               long double
#define all(a)           a.begin(),a.end()
#define rall(a)          a.rbegin(),a.rend()
#define pb               push_back
#define sz(s)            (int)s.size()
#define SET(n,i)         memset(n,i,sizeof(n))
#define cy               cout<<"YES\n";
#define cn               cout<<"NO\n";
#define vl               vector<LL>
#define pll              pair<LL,LL>
#define pii              pair<int,int>
#define F                first
#define S                second
#define sq(x)            (x)*(x)
#define FIX(n)           fixed<<setprecision(n)
#define fast             ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
//#define endl             '\n'

using namespace std;
template<class T, class T2> bool MAX(T& a, const T2& b) {return a < b ? a=b,1:0 ;}
template<class T, class T2> bool MIN(T& a, const T2& b) {return a > b ? a=b,1:0 ;}

                    //FUNCTION..

int dx[] = {+0,+1,+0,-1,-1,+1,-1,+1};
int dy[] = {-1,+0,+1,+0,-1,+1,+1,-1};
char direction[]={'L','D','R','U'};
const LL N=2e5+7, mod=998244353, oo=0x3f3f3f3f3f3f3f3f;
const long double pi = acos(-1), eps=1e-9 ;
LL Mul(LL x, LL y){x%=mod; y%=mod; return (x * y) % mod;}
LL Add(LL x, LL y){x%=mod; y%=mod; return (x + y) % mod;}
LL fix(LL x,LL m=mod){return (x%m+m)%m;}


LL n,m,i,j,x,y,z,l,r,q,p,k,f,d,sum,cnt,ans;
LL ar[N],br[N],vis[N];
map<LL,LL> mp,mp1;
string s,t;
vector<LL>g[N];


void SOLVE(){
    cin>>n;
    set<int>st;
    for(int i=0;i<n;i++){
        cin>>x;
        st.insert(x);
    }

    while(1){
        bool f=1;
        LL s=*st.rbegin();
        LL p=s/2;
        while(p>0 && st.count(p)){
            p/=2;
        }

        if(p){
        st.erase(s);
        st.insert(p);
        }else
        break;
    }
    for(int i:st)cout<<i<<' ';
}


                    //MAINING..
signed main(){
//    freopen("input.txt","r",stdin) ;
//    freopen("output.txt","w",stdout);
    fast
    int T=1;
    //cin>>T;
    while(T--)SOLVE();

    return 0;
}
