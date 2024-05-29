// LUOGU_RID: 158552993
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;

int p[N],tot;
bool isp[N];

//#define __int128 ll//转__int128时把这句删掉即可,两个ll相乘一般都要转

ll powM(ll a, ll b, ll mod) {
 	ll ans = 1;
 	while (b) {
	  	if (b & 1) {
	   		ans = ((__int128)ans * a) % mod;
	  	}
	  	a = ((__int128)a * a) % mod;
	  		b >>= 1;
 	}
 	return ans;
}

bool mr(ll n) {
	if(n==1||n==0)return false;
	if (n == 2)return true;
	ll n1 = n - 1;
	ll t = 0;
	while (n1 % 2==0) {
		t++;
		n1 /= 2;
	}
	ll u = n1;
	const int T = 7;
	for (int i = 0; i < T; ++i) {
		  bool flag = 0;
		  ll a = rand() % (n - 1) + 1;
		  ll v = powM(a, u, n);
		  if (v == 1)continue;
		  for (int i = 1; i <= t; ++i) {
			   if (v == n - 1) {
				    flag = 1;
				    break;
			   }
			   v = powM(v, 2, n);
		  }
		  if (!flag)return false;
	 }
	 return true;
}

const int M=7000;

ll ans,A;
unordered_map<ll,int> buk;
ll d[M];
vector<ll> posd[M];
unordered_map<ll,int> id; 
int f[2][M];
int vis[N];

void llz(){
	cin>>A;
	if(A==1){
		cout<<1<<"\n";
		return;
	}
	if(A==2){
		cout<<0<<"\n";
		return;
	}
	int lim=sqrtl(A);
	for(int i=2;i<=lim;++i){
		if(!isp[i])p[++tot]=i;
		for(int j=1;j<=tot&&p[j]*i<=lim;++j){
			isp[p[j]*i]=true;
			if(i%p[j]==0)break;
		}
	}
	for(int i=1;i<=tot;++i){
		ll u=p[i];
		while(u<=A){
			buk[u]=i;
			if(u>A/p[i])break;
			u*=p[i];
		}
	}
	int cntd=0,cntpos=0;
	for(ll t=1;t*t<=A;++t){
		if(A%t==0){
			d[++cntd]=t,id[t]=cntd;
			if(buk[t-1]){
				if(!vis[buk[t-1]]){
					++cntpos;
					posd[cntpos].push_back(t);
					vis[buk[t-1]]=cntpos;
				}
				else posd[vis[buk[t-1]]].push_back(t);
			}
			else if(mr(t-1))++cntpos,posd[cntpos].push_back(t);

			if(t*t!=A){
				d[++cntd]=A/t,id[A/t]=cntd;
				if(buk[A/t-1]){
					if(!vis[buk[A/t-1]]){
						++cntpos;
						posd[cntpos].push_back(A/t);
						vis[buk[A/t-1]]=cntpos;
					}
					else posd[vis[buk[A/t-1]]].push_back(A/t);
				}
				else if(mr(A/t-1))++cntpos,posd[cntpos].push_back(A/t);
			}
		}
	}
	f[0][1]=1;
	for(int i=1;i<=cntpos;++i){
		for(int j=1;j<=cntd;++j){
			f[i&1][j]=f[(i-1)&1][j];
			for(auto v:posd[i])if(d[j]%v==0)f[i&1][j]=(f[i&1][j]+f[(i-1)&1][id[d[j]/v]]);
		}
	}
	cout<<f[cntpos&1][id[A]]<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)llz();
	return 0;
}