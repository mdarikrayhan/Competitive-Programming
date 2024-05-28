#include "bits/stdc++.h"
using namespace std;

#ifdef N_N_C
#include "debug.h"
#else
#define cebug(...) "Arya"
#endif

#define int long long

const int N=2e7+5;
const int mod=1e9+7;

int n,fir,f;
bool isPrime[N+5];
void sieve(){
    for(int i=2; i<=N; i++) isPrime[i]=1;
    for(int i=2; i*i<=N; i++) if(isPrime[i]) for(int j=i*i; j<=N; j+=i) isPrime[j]=0;
}
int fz(int x){
	for(int i=2; i<x; i++) if(isPrime[i] and isPrime[x-i]) return i;
	return 0;
}
void sol(){
	cin>>n;
	int s=n*(n+1)/2;
	if(isPrime[s]){
		for(int i=1; i<=n; i++) cout<<"1 ";
		return;
	}
	fir=fz(s);
	if(!fir){
		fir=fz(s-3);
		f=1;
	}
	if(!f){
		for(int i=1; i<=n; i++){
			if(i==fir) cout<<"2 ";
			else cout<<"1 ";
		}
	}else{
		for(int i=1; i<=n; i++){
			if(i==3) cout<<"2 ";
			else if(i==fir) cout<<"3 ";
			else cout<<"1 "; 
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    sieve();
    int tt=1;
    //cin>>tt; 
    while(tt--){
    	sol();
    }
    cerr << "\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms.\n";
    return 0;
}