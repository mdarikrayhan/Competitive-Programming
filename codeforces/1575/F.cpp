#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int L=17, N=(1<<L);

struct comp
{
	double x, y;

	comp(): x(0), y(0) { }
	comp(const double &_x, const double &_y): x(_x), y(_y) { }

};

inline comp operator+(const comp &a, const comp &b) { return comp(a.x + b.x, a.y + b.y); }
inline comp operator-(const comp &a, const comp &b) { return comp(a.x - b.x, a.y - b.y); }
inline comp operator*(const comp &a, const comp &b) { return comp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
inline comp conj(const comp &a) { return comp(a.x, -a.y); }

const double PI = acos(-1);


comp w[N + 5];
int bitrev[N + 5];

void fft(comp *a, const int &n) {
	rep(i, 0, n) if (i < bitrev[i]) swap(a[i], a[bitrev[i]]);
	for (int i = 2, lyc = n >> 1; i <= n; i <<= 1, lyc >>= 1)
		for (int j = 0; j < n; j += i)
		{
			comp *l = a + j, *r = a + j + (i >> 1), *p = w;
			rep(k, 0, i >> 1)
			{
				comp tmp = *r * *p;
				*r = *l - tmp, *l = *l + tmp;
				++l, ++r, p += lyc;
			}
		}
}

inline void fft_prepare()
{
	rep(i, 0, N) bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (L - 1));
	rep(i, 0, N) w[i] = comp(cos(2 * PI * i / N), sin(2 * PI * i / N));
}

void conv(int *x, int *y, int *z,int K) {
	static comp a[N + 5], b[N + 5];
	static comp dfta[N + 5], dftb[N + 5], dftc[N + 5], dftd[N + 5];

	rep(i, 0, K + 1) a[i] = comp(x[i] & 32767, x[i] >> 15);
	rep(i, 0, K + 1) b[i] = comp(y[i] & 32767, y[i] >> 15);
	rep(i, K + 1, N) a[i] = b[i] = comp(0, 0);
	fft(a, N), fft(b, N);
	rep(i, 0, N)
	{
		int j = (N - i) & (N - 1);
		static comp da, db, dc, dd;
		da = (a[i] + conj(a[j])) * comp(0.5, 0);
		db = (a[i] - conj(a[j])) * comp(0, -0.5);
		dc = (b[i] + conj(b[j])) * comp(0.5, 0);
		dd = (b[i] - conj(b[j])) * comp(0, -0.5);
		dfta[j] = da * dc;
		dftb[j] = da * dd;
		dftc[j] = db * dc;
		dftd[j] = db * dd;
	}
	rep(i, 0, N) a[i] = dfta[i] + dftb[i] * comp(0, 1);
	rep(i, 0, N) b[i] = dftc[i] + dftd[i] * comp(0, 1);
	fft(a, N), fft(b, N);
	rep(i, 0, N)
	{
		int da = (ll)(a[i].x / N + 0.5) % mod;
		int db = (ll)(a[i].y / N + 0.5) % mod;
		int dc = (ll)(b[i].x / N + 0.5) % mod;
		int dd = (ll)(b[i].y / N + 0.5) % mod;
		z[i] = (da + ((ll)(db + dc) << 15) + ((ll)dd << 30)) % mod;
	}
}

ll d[N],f[N],fac[N],fnv[N],inv[N];
int n,k,occ[N],ex;
map<int,int> cnt;
int g[N],z[N];
int main() {
	fft_prepare();
	scanf("%d%d",&n,&k);
	fac[0]=fnv[0]=1;
	rep(i,1,n+1) {
		inv[i]=powmod(i,mod-2);
		fac[i]=fac[i-1]*i%mod;
		fnv[i]=fnv[i-1]*inv[i]%mod;
	}
	for (int i=1;i<n;i++) {
		d[i]=((d[i-1]*i%mod*(k-1))-(ll)i*k)%mod*inv[n-i]%mod;
		if (d[i]<0) d[i]+=mod;
	}

	per(i,0,n) f[i]=(f[i+1]+mod-d[i])%mod;
	rep(i,1,n+1) {
		int x;
		scanf("%d",&x);
		if (x==-1) ex++;
		else  cnt[x]++;
	}
	occ[0]=k;
	for (auto p:cnt) occ[p.se]++,occ[0]--;
	rep(i,0,ex+1) g[i]=powmod(k-1,ex-i)*fac[ex]%mod*fnv[i]%mod*fnv[ex-i]%mod;
	conv(occ,g,z,n);
	//rep(i,0,n-ex+1) rep(j,0,ex+1) z[i+j]=(z[i+j]+occ[i]*g[j])%mod;
	ll ans=0;
	rep(j,0,n+1) ans=(ans+z[j]*f[j])%mod;
	ans=ans*powmod(k,mod-1-ex)%mod;
	ans=(ans-(k-1)*f[0])%mod;
	if (ans<0) ans+=mod;
	printf("%lld\n",ans);
}