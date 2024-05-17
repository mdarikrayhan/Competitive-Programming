#include <bits/stdc++.h>
#include <iostream>
#define ll long long int
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define gcd __gcd
#define int_string to_string
#define string_int stoi
#define mn(v) *min_element(v.begin(), v.end())
#define mx(v) *max_element(v.begin(), v.end())
#define index_character s.find('character')
#define countxchar count(s.begin(), s.end(), 'x')
#define index_ofX_vector find(v.begin(), v.end(), x) - v.begin()
#define point cout << fixed << setprecision(10)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define n1 cout << "-1" << endl
#define bug cout << "ok" nl
#define sorted is_sorted(v.begin(), v.end())
#define nl << endl
#define sp << " "
#define mp make_pair
#define fi first
#define se second
#define Mx LLONG_MAX
#define Mn LLONG_MIN
#define mod %1000000007
// ordered_set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// bitsize-> ll size=log2(n)+1 (last set bit=size-1;/ /Last bit->__lg(value); )
// first bit-> name._Find_First()
// next bit after x-> name._Find_next()
// freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
// BesidesDuplicateCharacterEraseInString s.erase(unique(s.begin(), s.end()), s.end());
// Upper/lower-> transform(s.begin(), s.end(), s.begin(), ::toupper/tolower);
using namespace std;
ll i, j, k, n, m;
const ll N = 2e5+5;
const ll e=1e+9;
const double pi=acos(-1);
bool comp(pair<long double,ll> a,pair<long double,ll> b){
    if(a.fi==b.fi) return (a.se<b.se); return (a.fi>b.fi);}
//
// Don't get stuck on a single approach for long, think of multiple ways
// You will destroy your dream if you stay in your comfort zone
// **********************|| Main Code ||********************************
//
 
int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    // point;
    ll test = 1; 
    // cin >> test;    
    again: 
    while (test--)
    {       
        ll n,m,k;
        cin>>n>>m>>k;
        set<ll> s;
        for(i=1;i*i<=k;i++){
            if(k%i==0){
                s.insert(i),s.insert(k/i);
            }
        }
        ll a[n],b[m],count=0;
        vector<ll> va,vb;
        for(i=0;i<n;i++){
            cin>>a[i];
            if(a[i]) count++;
            else va.pb(count),count=0;
        }
        if(count) va.pb(count);
        count=0;
        for(i=0;i<m;i++){
            cin>>b[i];
            if(b[i]) count++;
            else vb.pb(count),count=0;
        }
        if(count) vb.pb(count);
        map<ll,ll> ma,mb;
        for(auto x: s){
            for(i=0;i<va.size();i++){
                if(va[i]>=x){
                    ma[x]+=va[i]-x+1;
                }
            }
            for(i=0;i<vb.size();i++){
                if(vb[i]>=x){
                    mb[x]+=vb[i]-x+1;
                }
            }
        }
        ll ans=0;
        for(auto x: s){
            ll d=k/x;
            ans+=ma[x]*mb[d];
        }
        cout << ans nl;
    }       
}