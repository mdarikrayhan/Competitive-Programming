#include "bits/stdc++.h"
// #include <sys/resource.h>
//common file for PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);   
#define Pi acos(-1.0)                               
#define ull unsigned long long                      
#define int long long 
#define krish
#define float long double
#define setbits(x) __builtin_popcount(x)
#define bit(x, y) (((x) >> (y)) & 1)
#define mkp(a,b) make_pair(a,b)
#define endl '\n'
#define fix fixed<<setprecision(12);
#define l_b(x, y) lower_bound(x.begin(), x.end(), y)-x.begin();
#define u_b(x, y) upper_bound(x.begin(), x.end(), y)-x.begin();
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vvi vector<vector<int>> 
#define vvc vector<vector<char>>
#define vvii vector<vector<pair<int, int>>>
#define vii vector<pair<int, int>> 
#define pqi priority_queue<int>
#define pqii priority_queue<pair<int, int>>
#define ini(x, i) memset(x, i, sizeof(x))
#define ff first 
#define ss second
#define all(x) x.begin(), x.end()
#define mxa(x) *max_element(x.begin(), x.end())
typedef pair<int, int> pii;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
// find_by_order order_of_key
const int MOD=1e9+7;
// const int MOD=998244353;
const int maxn=2e6+10;
int fact[maxn];
const int N=(2e5+5);
const int INF=LONG_LONG_MAX;
int POW(int a,int b){
    if(b==0) return 1;
    if(a==0) return 0;
    int temp=POW(a,b/2);
    if(b%2==0) return (temp*temp)%MOD;
    else return (((temp*temp)%MOD)*a)%MOD;
}
void factorial(){
    fact[0]=1;
    for(int i=1; i<maxn; i++){fact[i]=((i*fact[i-1])%MOD+MOD)%MOD;}
}
int factorial(int n){
    if(n==0)return 1;
    int ans=1;
    for(int i=1; i<=n; i++){ ans=((ans)*(i));}
    return ans;
}
bool isprime(int n){
    if(n==2) return 1;
    if(n==0 || n==1 || n%2==0) return 0;
    for(int i=3; i<=sqrt(n); i+=2){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
int lcm(int a, int b){ return (a/__gcd(a, b))*b;}
int add(int a, int b, int m=MOD){ a=a%m, b=b%m;  return (((a+b)%m)+m)%m;}
int sub(int a, int b, int m=MOD){ a=a%m, b=b%m;  return (((a-b)%m)+m)%m;}
int mul(int a, int b, int m=MOD){ a=a%m, b=b%m;  return (((a*b)%m)+m)%m;}
int power(int a, int b) { int r = 1; while (b) { if (b & 1) r = mul(r, a); a = mul(a, a); b >>= 1; } return r; }
int ckdiv(int a, int b) { return mul(a, power(b, MOD - 2)); }
int inv(int n){ return power(n,MOD-2);}
int nCr(int n,int r){
    if(r>n)return 0;
    if(n==r or r==0)return 1;
    int num=fact[n];
    int denm=(fact[r]*fact[n-r])%MOD;
    num = (num*inv(denm))%MOD;
    return num;
}
bool cmp(pair<string, int> &p1, pair<string, int> &p2){ if(p1.first.size()==p2.first.size()) return p1<p2; return p1.first.size()>p2.first.size();}
vector<bool> isPrime;
vi smf,pri;
void sieve(int n){
	isPrime.assign(n+1,true);
	smf.assign(n+1,0);
	isPrime[0]=isPrime[1]=false;
	pri={};
	for(int i=2;i<=n;i++){
		if(isPrime[i]){
			smf[i]=i;
			pri.pb(i);
			for(int j=i*i;j<=n;j+=i){
                if(isPrime[j]){
                    isPrime[j]=false;
                    smf[j]=i;
                }
            }
		}
	}
}
void solve(){
    string s; cin>>s;
    map<char,int> mp;
    for(auto it: s){
        mp[it]++;
    }
    char c='0';
    int mn=1e5+2;
    for(auto it: mp){
        if(it.ss==1){
            cout<<it.ff;
            sort(all(s));
            for(auto i: s)if(i!=it.ff)cout<<i;
            cout<<endl;
            return;
        }
        else if(mn!=1){
            int x=s.size()-it.ss;
            if(x-it.ss>=-1){
                c=it.ff;
                mn=1;
            }
        }
    }
    if(c=='0'){
        cout<<s<<endl;
        return;
    }
    string ans;
    sort(all(s));
    int x=s.size()-mp[s[0]];
    if((mp[s[0]]-x)<=2){
        ans+=s[0];
        ans+=s[0];
        mp[s[0]]-=2;
        for(auto it: mp){
            if(it.ff==s[0])continue;
            int x=it.ss;
            while(x--){
                ans+=it.ff;
                if(mp[s[0]])ans+=s[0], mp[s[0]]--;
            }
        }
    }
    else{
        if(mp.size()==2){
            ans+=s[0];
            for(auto it: mp){
                if(it.ff!=s[0]){
                    int x=it.ss;
                    while(x--)ans+=it.ff;
                }
            }
            int x=mp[s[0]]-1;
            while(x--)ans+=s[0];
        }
        else{
            int idx=0;
            for(int i=0; i<s.size(); i++){
                if(s[i]!=s[0]){
                    swap(s[1], s[i]);
                    idx=i+1;
                    break;
                }
            }
            for(int i=0; i<s.size(); i++){
                if(s[1]!=s[i] && s[i]!=s[0]){
                    swap(s[idx], s[i]);
                    break;
                }
            }
            ans=s;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    factorial();
    sieve(1e4);
    int t=1;
    cin>>t;  
    while(t--){
        solve();
    }
} 