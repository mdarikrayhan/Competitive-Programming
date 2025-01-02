#include<bits/stdc++.h>
using namespace std;
#define int  long long int 
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(a) a.begin(), a.end()
#define mp make_pair
#define mod 1000000007
#define nl '\n'
int gcd(int a, int b)  
{  
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
}
int lcm(int a, int b)  
{  
    return (a / gcd(a, b)) * b; 
}  
bool compare(pair<int,int> &p1, pair<int,int> &p2)
{
    if(p1.first!=p2.first)
    return p1.first>p2.first;
    return p1.second<p2.second;
}
int max(int a,int b){if(a>b)return a;return b;}
int min(int a,int b){ if(a<b)return a;return b;}
int computeXOR(int n)
{if (n % 4 == 0)  return n; if (n % 4 == 1) return 1; if (n % 4 == 2)   return n + 1; return 0;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
#define fast_io      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define out(v) for(int i = 0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<nl;
#define pre(pref,v) for(int i = 0;i<v.size();i++) { pref.push_back(v[i]); if(i>=1) pref[i]+=pref[i-1];}
#define suf(suff,v) for(int i = 0;i<v.size();i++) {suff.push_back(v[i]); } for(int i=v.size()-2;i>=0;i--){ suff[i]+=suff[i+1];}
#define read(v,n) for(int i = 0;i<n;i++){ int p; cin>>p; v.push_back(p);}
void solve()
{
    int n,m;
    cin>>n>>m;
    vi v;;
    read(v,n);
    set<int>st;
    map<int,int>mp;
    for(auto it:v){
        st.insert(it);
        mp[it]++;
    }
    int dis = 1;
    vi ans;
    while(m>0){
        set<int>tmp;
        for(auto it:st){
            if(mp.find(it-dis)!=mp.end() && mp.find(it+dis)!=mp.end() ){
                tmp.insert(it);
            } if(mp.find(it-dis)==mp.end()){
                mp[it-dis]++;
                m--;
                ans.push_back(it-dis);
                if(m==0){
                    break;
                }
            }
                if(mp.find(it+dis)==mp.end()){
                    mp[it+dis]++;
                m--;
                ans.push_back(it+dis);
                if(m==0){
                    break;
                }
                }
                
            

        }
        dis++;
        for(auto it:tmp){
            st.erase(it);
        }
    }
    // cout<<1<<nl;
    int val = 0;
    sort(all(v));
    for(auto it:ans){
        int ind = lower_bound(all(v),it)-v.begin();
    
        int t=INT_MAX;
        if(ind<v.size()){
            t =  v[ind]-it;
        }
        if((ind-1)>=0){
            t = min(t,it-v[ind-1]);
        }
        val += t;
    }
    cout<<val<<endl;
    out(ans);
}

main()  {
fast_io;
int t;
t=1;
// cin>>t;
while(t--) {
solve();
}
return 0;
}