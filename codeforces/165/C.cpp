#include<bits/stdc++.h>
#include <math.h>
#define int long long int
#define setbits(x)  __builtin_popcountll(x)
#define zrobits(x)  __builtin_ctzll(x)   //no of zero bits befor the first set bits
#define inf         1e9
#define ps(x,y)     fixed<<setprecision(y)<<x
#define w(x)        int x; cin>>x; while(x--)
#define rep(i,a,b)  for(int i = a; i < b; i++)
#define Rep(i,a,b)  for(int i = a; i <= b; i++)
#define ff          first
#define ss          second
#define pb          push_back
#define LL long long
#define INF         998244353
#define mod         1e9 + 7
#define pii         pair<int,int>
#define mxhi        priority_queue<int>
#define mnhi        priority_queue<int,vi,greater<int>>
using namespace std;
 
struct node {int x1, y1, x2, y2, x3, y3;} p[5];
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
 
struct man{
	int h,w,id;
};
 
int power(int x, int y, int m){
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}
 
const int MAX = 10000005;
bool prime[MAX]; 
void sieve(){
	memset(prime,0,sizeof(prime));
	prime[0] = prime[1] = 1;
	for(int p=2;p<MAX;p++){
		if(!prime[p]){
			for(int j=2*p;j<MAX;j+=p)prime[j] = 1;
		}
	}
}

void solve(){

	int k;cin>>k;
	string s;cin>>s;
	int n = s.length();
	vector<int> v;
	for(int i=0;i<n;i++){
		if(s[i]=='1')v.push_back(i);
	}

	int x = v.size();
	int cnt = 0;
	if(x<k){
		cout<<cnt<<endl;
		return;
	}

	if(k==0){
		if(x==0){
			cout<<(n*(n+1))/2<<endl;
			return;
		}
		int s = 0;
		for(int i=0;i<x;i++){
			int sze = v[i]-s;
			cnt += (sze*(sze+1))/2;
			s = v[i]+1;
		}
		if(v.back()!=n-1){
			int sze = n-1 - v.back();
			cnt += (sze*(sze+1))/2;
		}
		cout<<cnt<<endl;
		return;
	}

	for(int i=0;i<=x-k;i++){
		int a = (i-1>=0?v[i]-v[i-1]-1:v[i]);
		int b = (i+k<x?v[i+k]-v[i+k-1]:n-v[i+k-1]);
		cnt += (a+1)*(b);
	}

	cout<<cnt<<endl;

}
 
int32_t main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
 	 	
    int t;
    t = 1;
    // cin>>t;
    // sieve();
    for(int test=1;test<=t;test++){
        // cout<<"Case #"<<test<<": ";
    	solve();
    }
 
	return 0;
} 
 