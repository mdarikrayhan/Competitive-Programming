#include<bits/stdc++.h>
#include<cstring>
//#define Psych_x7's Code
#define   ll         long long
#define   ull        unsigned long long
#define   pb         push_back
#define   em         emplace_back
#define   ff         first
#define   ss         second
#define   all(v)     (v.begin(), v.end())
#define   rall(v)    (v.rbegin(), v.rend())
#define   pi         acos(-1.0)
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define   bug(a)     cerr << #a << " : " << a << endl
using namespace std;

void primeFactors(ll n,map<ll,ll> &M) 
{ 
    // Print the number of 2s that divide n 
    while (n % 2 == 0) 
    { 
        M[2]++;
        n = n/2; 
    } 
 
    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (ll i = 3; i <= sqrt(n); i = i + 2) 
    { 
        // While i divides n, print i and divide n 
        while (n % i == 0) 
        { 
            M[i]++;
            n = n/i; 
        } 
    } 
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2 
    if (n > 2){
        M[n]++;
    } 
} 
ll getGCD(ll a, ll b) 
{ 
    while (a > 0 && b > 0) { 
        if (a > b) { 
            a = a % b; 
        } 
        else { 
            b = b % a; 
        } 
    } 
    if (a == 0) { 
        return b; 
    } 
    return a; 
} 
  
ll GcdOfArray(vector<ll>& arr) 
{ 
    ll gcd = 0; 
    for (ll i = 0; i < arr.size(); i++) { 
        gcd = getGCD(gcd, arr[i]); 
    } 
    return gcd; 
} 
int main() {
	//code
	ll N,K,i,min,Z;
	cin>>N;
	vector<ll> V;
	map<ll,ll> M;
	min=100000000000000000;
	for(i=0;i<N;i++){
	    cin>>K;
	    if(min>K){
	        min=K;
	    }
	    V.em(K);
	}Z=GcdOfArray(V);
	primeFactors(Z,M);
	min=1;
	for(auto it:M){
	    min=min*(it.second+1);
	}cout<<min<<endl;
	return 0;
}