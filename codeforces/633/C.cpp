// #include <bits/stdc++.h>
// #include <cctype>
// #include <string>
// using namespace std;
// #define all(x) x.begin(),x.end()
// #define ll long long
// #define MP make_pair
// #define ld long double
// #define fuk return
// #define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
// #define pb push_back
// #define tr(it,a) for(auto it=a.begin();it!=a.end();it++)
// #define fo(i,n) for(int i=0;i<n;i++)
// #define fop(i,x,n) for(int i=x;i<=n;i++)
// #define forv(i,l,n) for(int i=l;i>=n;i--)
// #define nl  <<  "\n";
// typedef  pair<ll,ll>  pl;
// typedef vector<ll> vl;
// typedef vector < pair <ll,ll > > vp;
// typedef vector<bool> vb;
// typedef vector<ld> vd;
// typedef vector<string> vs;
// #define inp(v, n) for(int i=0; i<n; ++i) cin >> v[i];
// #define opt(v) for(auto x: v) cout << x << ' '; cout << endl;
// const ll mod = 1000000007;
// const ll N = 2e5+10;
// #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define int long long
// ll binpow(ll a, ll b) {
// ll result = 1;
// while (b > 0) {
// if (b & 1)
// result *= a;
//         a *= a;
// a %= mod;
// b /= 2;
// result %= mod;
// }
// return result;
// }
// vector <vl> dp,kp;
// string s;
// ll n;
//  ll m;
// ll mn=0;
// map<string,ll> mp;
// vector <string> vse,ans2;
// ll rec(ll level,ll len){
//     if(len>mn) {
//         // vse.clear();
//         return 0;}
//     if(level==n){
//         if(len==0){
//             // cout<<"hi\n";
//             ans2=vse;
//             vse.clear();
//             return 1;
//         }else{
//             // vse.clear();
//         return 0;
//         }
        
//     }
//     if(dp[level][len]!=-1){
//         return dp[level][len];
//     }
//     ll ans=0;
//     ans=max(ans,rec(level+1,len+1));
//     string q=s.substr(level-len,len+1);
//     // cout<<q nl
//     if(mp[q]){
//         vse.pb(q);
//         // cout<<q nl
//         ans=max(ans,rec(level+1,0));
//     }
//     return dp[level][len]=ans;
// }
// void solve(){
//     // ll n;
//     cin>>n; 
//     cin>>s;
//     cin>>m;
    
//     string str[m+1];
    
//     fo(i,m){
//         cin>>str[i+1];
//         string f=str[i+1];
//         transform(f.begin(), f.end(), f.begin(), ::tolower); 
//         mp[f]=i+1;
//         ll y=f.size();
//         mn=max(mn,y);
//     }
//     mn=1001;
//     // cout<<s.size() nl
//     reverse(all(s));
//     string q;
//     vl ans;
//     // ll dp[n+1][mn+2];
    
//     // ll kp[n+2][mn+2];
//     dp=vector <vl> (n+2,vl(mn+2));
//     kp=vector <vl> (n+2,vl(mn+2));
//     fo(i,n+1){
//         fo(j,mn+2) {
//             dp[i][j]=-1;
//             kp[i][j]=-1;
//         }
//     }
//     ll hie=rec(0,0);
//     reverse(all(ans2));
//     fo(i,ans2.size()){
//         ll ind=mp[ans2[i]];
//         cout<<str[ind]<<" ";
//     }
// }
// signed main(){
//     IOS
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define ll long long
#define MP make_pair
#define ld long double
#define fuk return
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define pb push_back
#define tr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define fo(i,n) for(int i=0;i<n;i++)
#define fop(i,x,n) for(int i=x;i<=n;i++)
#define forv(i,l,n) for(int i=l;i>=n;i--)
#define nl  <<  "\n";
typedef  pair<ll,ll>  pl;
typedef vector<ll> vl;
typedef vector < pair <ll,ll > > vp;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<string> vs;
#define inp(v, n) for(int i=0; i<n; ++i) cin >> v[i];
#define opt(v) for(auto x: v) cout << x << ' '; cout << endl;
const ll mod = 1000000007;
const ll N = 100010;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
ll binpow(ll a, ll b) {
ll result = 1;
while (b > 0) {
if (b & 1)
result *= a;
        a *= a;
a %= mod;
b /= 2;
result %= mod;
}
return result;
}
struct Trie{
    Trie *ch[26];
    ll ind;
    Trie(){
        ind=-1;
        fo(i,26)ch[i]=NULL;
    }
};
string s;
ll n,m;
vs elem,ender;
ll dp[100010];
ll ansp[100010];
Trie *root;
ll rec(ll x){
    if(x>n) return 0;
    if(x==n) return 1;
    if(dp[x]!=-1){
        return dp[x];
    }
    ll ans=0;
    // Trie *root=new Trie();
    Trie *p=root;
    fop(i,x,n-1){
        ll ve=s[i]-'a';
        if(p->ch[ve]==NULL){
            break;
        }
        p=p->ch[ve];
        if(p->ind!=-1){
            if(rec(i+1)){
                ans=1;
                ansp[x]=p->ind;
            }
        }
    }
    return dp[x]=ans;
}
void solve(){
    cin>>n;
    cin>>s;
    cin>>m;
    fo(i,m){
        string str;
        cin>>str;
        elem.pb(str);
        string novi;
        for(int j = 0; j < str.size(); j++)
        {
            char c = str[j];
            if(!(str[j] >= 'a' && str[j] <= 'z'))
                c = str[j] - 'A' + 'a';
            novi.push_back(c);
        }
        reverse(all(novi));
        ender.pb(novi);
    }
    
    root=new Trie();
    fo(i,ender.size()){
        Trie *p=root;
        fo(j,ender[i].size()){
            ll fg=ender[i][j]-'a';
            if(p->ch[fg]==NULL){
                p->ch[fg]=new Trie();
            }
            p=p->ch[fg];
        }
        p->ind=i;
    }
 
    fo(i,N) dp[i]=-1;
    ll srk=rec(0);
    // cout<<srk nl
    ll x=0;
    while(x<n){
        cout<<elem[ansp[x]]<<" ";
        x+=elem[ansp[x]].size();
    }
    cout nl
}
signed main(){
    IOS
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
    return 0;
}