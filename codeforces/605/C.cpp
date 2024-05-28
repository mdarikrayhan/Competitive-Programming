// LUOGU_RID: 157128396
// Problem: C. Freelancer's Dreams
// Contest: Codeforces - Codeforces Round 335 (Div. 1)
// URL: https://codeforces.com/contest/605/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
 
#define debug(x) cerr << #x << ": " << (x) << endl
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define dwn(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define all(x) (x).begin(), (x).end()
 
#define x first
#define y second
#define int long long
using pii = pair<int, int>;
using ll = long long;
 
inline void read(int &x){
    int s=0; x=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')x=-1;ch=getchar();}
    while(ch>='0' && ch<='9') s=(s<<3)+(s<<1)+ch-'0',ch=getchar();
    x*=s;
}

const int N=1e5+5;

int n, p, q;
pii w[N];
int a[N], b[N];

bool KCmp(int x, int y, int z){
	int a1=a[x], b1=b[x];
	int a2=a[y], b2=b[y];
	int a3=a[z], b3=b[z];
	ll fir=1LL*(b2-b1)*(a3-a2);
	ll sec=1LL*(b3-b2)*(a2-a1);
	// debug(fir);
	// debug(sec);
	return fir<=sec;
}

bool Small(int x, int y){
	int a1=a[x], b1=b[x];
	int a2=a[y], b2=b[y];
	return a1<=a2 && b1<=b2;
}

signed main(){
	cin>>n>>p>>q;
	rep(i, 1, n) read(w[i].x), read(w[i].y);
	sort(w+1, w+1+n);
	rep(i, 1, n) a[i]=w[i].x, b[i]=w[i].y;
	
	double res=1e18+10;
	rep(i, 1, n){
		res=min(res, max((double)p/a[i], (double)q/b[i]));
	}
	
	vector<int> stk;
	rep(i, 1, n){
		// cerr<<a[i]<<" "<<b[i]<<endl;
		if(stk.size()<2){
			if(stk.size()){
				int a1=a[stk.back()];
				int b1=b[stk.back()];
				int a2=a[i];
				int b2=b[i];
				bool fl=true;
				if(1LL*a1*b2==1LL*a2*b1) fl=false;
				if(fl){
					double x=(double)(a2*q-p*b2)/(a2*b1-a1*b2);
					double y=(double)(p*b1-a1*q)/(a2*b1-a1*b2);
					// cerr<<x<<" "<<y<<endl;
					if(x>=0 && y>=0) res=min(res, x+y);
				}
			}
			stk.pb(i);
		}
		else{
			int sz=stk.size();
			while(sz>=2 && KCmp(stk[sz-2], stk[sz-1], i) || sz>=1 && Small(stk[sz-1], i)){
				stk.pop_back();
				sz--;	
			}
			if(stk.size()){
				int a1=a[stk.back()];
				int b1=b[stk.back()];
				int a2=a[i];
				int b2=b[i];
				bool fl=true;
				if(1LL*a1*b2==1LL*a2*b1) fl=false;
				if(fl){
					double x=(double)(a2*q-p*b2)/(a2*b1-a1*b2);
					double y=(double)(p*b1-a1*q)/(a2*b1-a1*b2);
					// cerr<<x<<" "<<y<<endl;
					if(x>=0 && y>=0) res=min(res, x+y);
				}
			}
			stk.pb(i);
			// debug(stk.size());
		}
	}
	printf("%.10lf\n", res);
	
	return 0;
}