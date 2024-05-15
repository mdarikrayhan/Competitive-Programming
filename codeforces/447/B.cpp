#include<bits/stdc++.h>
using namespace std;
#define fastio
//defining macros
#define int long long
#define ff first
#define ss second
#define ll long long
#define ull unsigned long long
#define lld long double
#define ar array
#define vi vector<int>
#define vll vector<long long>
//define data structures
/*tuple defining */
#define tup tuple<int,int,int>
/*pair vector*/
#define vpi pair<vector<int>,vector<int>>
/*vector pairs (both are different)*/
#define pv vector<pair<int,int>>
#define sza(x) ((int)x.size())
#define pb push_back
#define ppb pop_back
#define mk make_pair
#define all(enter_vect) (enter_vect).begin(), (enter_vect).end()
#define allp(enter_pairvec) (enter_pairvec).ff.begin(), (enter_pairvec).ss.end() /*taking first as elements*/
/*def maxes and minis*/
#define imax INT_MAX
#define imin INT_MIN
//debugging
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
/*!creating print debugs for primitive datatypes*/
// void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(long double t) {cerr << t;}
// void _print(ull t) {cerr << t;}
//*debugging data structures
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(vector<pair<T, V>> vp) {cerr << "[ "; for (auto i : vp) {_print(i); cerr << " ";} cerr<<"]";}

/*1849B - Sorting technique - here we sort if hp%k> of some other element*/
/*if it's same we return the rem (hp%k) which is of smallere index*/
bool compare(pair<int,int> x,pair<int,int> y){
    if(x.ff!=y.ff){
        return x.ff>y.ff;
    }
    else{
        return x.ss<y.ss;
    }
}


//kadane algorithm - largest sum contigous array - we will also print the array
tup kadane(vi arr){
    int max_end_here = 0;int max_so_far=INT_MIN;
    int start=0,end=0,s=0;
    for (int i = 0; i < arr.size(); i++)
    {
        max_end_here+=arr[i];
        if(max_end_here>max_so_far){
            max_so_far = max_end_here;
            start = s;end = i;
        }
        if(max_end_here<0){
            max_end_here=0;
            s = i+1;
        }
    }
    tup ans = make_tuple(max_so_far,start,end);
    return ans;
    
}

//power of factorial divisor - if we wanted to find the largest
//power of k x such that n! is divisivle by k^x
int power_fact(int n,int k){
    int res=0;
    while(n){
        n/=k;
        res+=n;
    }
    return res;
}

void solve(){
    string s;int k;vi alpha(26);
    cin>>s>>k;
    int n = sza(s); int max_h;int id;
    for (int i = 0; i < 26; i++)
    {
        cin>>alpha[i];
        if(i==0){
            max_h = alpha[i];id=i;
        }    
        else{
            if(alpha[i]>max_h){
                max_h=alpha[i];
                id=i;
            }
        }
    }
    debug(max_h);
    int sum=0;
    for (int i = 0; i <n; i++)
    {
        sum+=(i+1)*alpha[s[i]-'a'];
        // debug(sum);
    }
    for (int i = n+1; i <=n+k; i++)
    {
        sum+=i*max_h;
    }
    debug(sum);
    cout<<sum<<endl;
    
    

}
signed main(){
    /*desync c standard and cpp cin/cout,uncomment these while debugging/writing*/
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fastio;
    // int tc;
    // cin>>tc;
    // for (int i = 1; i <= tc; i++)
    // {
    // }
    solve();
    return 0;
}