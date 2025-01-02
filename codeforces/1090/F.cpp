
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int maxn=1005;
int n;
ll c[maxn];
ll ask(ll x, ll y, ll z){
	cout << "? "<< x << ' ' << y << ' ' << z << endl;
	ll a;
	cin >> a;
	return a;
}
ll solve(int id1,int id2,int id3,int id4){
	vector<ll>siu;
	siu.pb(ask(id1,id2,id3));
	siu.pb(ask(id1,id2,id4));
	siu.pb(ask(id1,id3,id4));
	siu.pb(ask(id2,id3,id4));
	sort(siu.begin(),siu.end());
	return siu[0]+siu.back();
}
void solve1(){
	vector<ll>siu;
	ll sum=0;
	ll x1=solve(2,3,4,5);
	ll x2=solve(1,3,4,5);
	ll x3=solve(1,2,4,5);
	ll x4=solve(1,2,3,5);
	ll x5=solve(1,2,3,4);
	sum=x1+x2+x3+x4+x5;
	sum/=4;
	c[1]=sum-x1;
	c[2]=sum-x2;
	c[3]=sum-x3;
	c[4]=sum-x4;
	c[5]=sum-x5;
}
signed main(){
	//freopen("input.inp","r",stdin);
	//freopen("output.out","w",stdout);
	cin.tie(0),cout.tie(0)->sync_with_stdio(0);
	cin >> n;
	solve1();
	for(int i=6;i<=n;i++){
		c[i]=solve(i-3,i-2,i-1,i)-c[i-3]-c[i-2]-c[i-1];
	}
	cout << "! ";
	for(int i=1;i<=n;i++){
		cout << c[i] << ' ';
	}
}

  				 		  		 	 		   				 	  		