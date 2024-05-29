// LUOGU_RID: 154424601
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
#define fi first
#define se second
#define endl '\n'
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define Cl(x) memset(x,0,sizeof(x))
const bool DC=0;
const ll mod=998244353;
const int N=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}
void NO(){cout<<"NO\n";}
void YES(){cout<<"YES\n";}
mt19937 rnd((unsigned long long)new char);
int rnad(){return abs((int)rnd());}
int rd(int l,int r){return rnad()%(r-l+1)+l;}

int n,m;
ll G[15][128][128],p[128],f[128][128][128],coef[2][2][2]={{{24,12},{12,4}},{{12,6},{4,1}}},ans;
vector<string>s;
bool vis[128];

void __INIT__(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
void __SOLVE__(int _case){
	cin>>n;
	for(int i=1;i<=n;i++){
		string t;
		cin>>t;
		s.push_back(t);
		reverse(all(t));
		s.push_back(t);
		for(auto x:t)vis[x]=1;
	}
	sort(all(s)),s.erase(unique(all(s)),s.end());
	for(int i=0;i<128;i++)if(vis[i])p[i]=m++;
	for(auto t:s)++G[t.size()][p[t[0]]][p[t.back()]];
	for(int l=3;l<=10;l++){
		for(int x=0;x^m;x++)for(int y=0;y^m;y++)for(int z=0;z^m;z++){
			f[x][y][z]=0;
			for(int i=0;i^m;i++)(f[x][y][z]+=G[l][i][x]*G[l][i][y]%mod*G[l][i][z])%=mod;
		}
		for(int i=0;i^m;i++)for(int x=i;x^m;x++)for(int y=x;y^m;y++)for(int z=y;z^m;z++)(ans+=f[i][x][y]*f[i][x][z]%mod*f[i][y][z]%mod*f[x][y][z]%mod*coef[i==x][x==y][y==z])%=mod;
	}
	cout<<ans<<"\n";
}
int main(){/*freopen(".in","r",stdin);freopen(".out","w",stdout);*/__INIT__();int T;DC?cin>>T,1:T=1;for(int _CASE=1;_CASE<=T;_CASE++)__SOLVE__(_CASE);return 0;}