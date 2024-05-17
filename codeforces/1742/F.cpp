
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
/*using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_st;*/
#define int long long
#define ld long double
#define ll long long
#define endl "\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define V vector<ll>
#define fx(n)  cout<<fixed<<setprecision(n)
#define cin(vec) for(auto& i : vec) cin >> i
#define cout(vec) for(auto& i : vec) cout << i <<" "
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
ll fpow(ll num, ll power) {
    ll ans = 1;
    while(power) {
        if(power & 1) ans *= num;
        num *= num;
        power /= 2;
    }
    return ans;
}
bool getBit(ll num, int idx) {
	return ((num >> idx) & 1);
}

ll setBit(ll num, int idx, bool val) {
	return val ? (num | (1LL << idx)) : (num & ~(1LL << idx));
}

ll flipBit(ll num, int idx) {
	return (num ^ (1LL << idx));
}

ll leastBit(ll num) {
	return (num & -num);
}

//num%mod, mod is a power of 2
ll Mod(ll num, ll mod) {
	return (num & mod - 1);
}

bool isPowerOfTwo(ll num) {
	return (num & num - 1) == 0;
}

int turnOnLastZero(int S) {
	return S | S + 1;
}

int turnOffLastBit(int S) {
	return S & S - 1;
}

int turnOnLastConsecutiveZeroes(int S) {
	return S | S - 1;
}

int turnOffLastConsecutiveBits(int S) {
	return S & S + 1;
}

vector<int> genAllSubmask(int mask) {
	vector<int> v;
	for (int subMask = mask;; subMask = (subMask - 1) & mask) {
		v.push_back(subMask);
		if (subMask == 0)
			break;
	}
	return v;
}

int
prime (int n)
{
    if (n == 1)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt (n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
/*binary search on double domain
double k, l = 0, r = 1000000000, mid=l+(l-r)/2,mid2=0,ans=0;
    while (abs(r - l) > 1e-7)
    {

        mid = l + (r - l) / 2;
        if (abs(mid - mid2) <= 1e-6)break;
        if (c * mid * log2(mid) <= time)ans = mid, l = mid;
        else r = mid;
        mid2 = mid;
    }
    double sum = 0;
    cout <<fixed<<setprecision(7)<< ans << endl;*/
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int totalsum(int n){
    return(n*(n+1)/2);
}
int f(int n){
    int res=1;
    for(int i=i;i<=n;i++){
        res*=i;
    }
    return res;
}
int div(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return n/i;
        }
    }
    return 1;
}
int const N = 5e3+1, mod =1e9+7;
void ashtar_katkout();
void file()
{
    //freopen("limited.in", "r", stdin);
   // freopen("Output.txt", "w", stdout);
}

int32_t main()
{
    //file();

    IOS;
    int t = 1;
    int tt=1;
    cin>>t;
    while(t--)
    { ashtar_katkout();
    }
}
void ashtar_katkout()
{ string s,t;
  int q;
  map<char,int>mp1;
  map<char,int>mp2;
  s+='a';
  t+='a';
  mp1['a']++;
  mp2['a']++;
  int len1=1,len2=1;
  cin>>q;
  while(q--){
    int a,k;
    string x;
    cin>>a>>k>>x;
    if(a==1){
        for(int i=0;i<x.size();i++){
            mp1[x[i]]+=k;
        }
        len1+=k*x.size();
    }
    else{
        for(int i=0;i<x.size();i++){
            mp2[x[i]]+=k;
        }
        len2+=k*x.size();
    }

    int c=0;
     if(mp2.size()==1){
        if(mp2['a']>0){
            if(mp1['a']>=1&&mp1.size()==1){
                if(len2<=len1)
                    no
                    else
                    yes
            }
            else if(mp1['a']>=1&&mp1.size()!=1)
                no
        }
        else
         yes
     }
     else{
    for(auto it:mp2){
     for(char i='a';i<it.first;i++){
        if(mp1[i]>=1){  c++;break; }
     }
  }
  if(c==0)
    no

  else
    {yes }
     }
}
}




