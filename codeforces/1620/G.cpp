#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(x) (x&-x)
#define lb(x) (31^__builtin_clz(lowbit(x)))
const int mod = 998244353;
struct mint {
    int x;
    mint() : x(0) {}
    mint(long long y, bool flag = 0) {
        if (flag) x = y;
        else x = (y % mod + mod) % mod;
    }
    friend const mint ksm(mint a, long long b);
    const mint inv() {return ksm(*this, mod - 2);}
};
bool operator == (const mint a, const mint b) {return a.x == b.x;}
bool operator != (const mint a, const mint b) {return a.x != b.x;}
int operator ! (const mint a) {return !a.x;}
const mint operator + (const mint a, const mint b) {
    mint res(a.x + b.x, 1);
    if (res.x >= mod) res.x -= mod;
    return res;
}
mint& operator += (mint &a, const mint b) {
    a.x += b.x;
    if (a.x >= mod) a.x -= mod;
    return a;
}
const mint operator - (const mint a, const mint b) {
    mint res(a.x - b.x, 1);
    if (res.x < 0) res.x += mod;
    return res;
}
mint& operator -= (mint &a, const mint b) {
    a.x -= b.x;
    if (a.x < 0) a.x += mod;
    return a;
}
const mint operator * (const mint a, const mint b) {
    return mint((long long)a.x * b.x % mod, 1);
}
mint& operator *= (mint &a, const mint b) {
    a.x = (long long)a.x * b.x % mod;
    return a;
}
const mint ksm(mint a, long long b) {
    mint res(1, 1);
    for (; b; a *= a, b >>= 1)
        if (b & 1) res *= a;
    return res;
}
const mint operator / (const mint a, const mint b) {
    return a * ksm(b, mod - 2);
}
mint& operator /= (mint &a, const mint b) {
    a = a * ksm(b, mod - 2);
    return a;
}
ostream& operator << (ostream &out, const mint a) {
    return out << a.x;
}
istream& operator >> (istream &in, mint &a) {
    long long y;
    in >> y, a = mint(y);
    return in;
}

int n;

array<int,26> operator*(array<int,26> a,array<int,26> b) {
	array<int,26> c;
	c[0]=min(a[0],b[0]),c[1]=min(a[1],b[1]),c[2]=min(a[2],b[2]),c[3]=min(a[3],b[3]),c[4]=min(a[4],b[4]),c[5]=min(a[5],b[5]),c[6]=min(a[6],b[6]),c[7]=min(a[7],b[7]),c[8]=min(a[8],b[8]),c[9]=min(a[9],b[9]),c[10]=min(a[10],b[10]),c[11]=min(a[11],b[11]),c[12]=min(a[12],b[12]),c[13]=min(a[13],b[13]),c[14]=min(a[14],b[14]),c[15]=min(a[15],b[15]),c[16]=min(a[16],b[16]),c[17]=min(a[17],b[17]),c[18]=min(a[18],b[18]),c[19]=min(a[19],b[19]),c[20]=min(a[20],b[20]),c[21]=min(a[21],b[21]),c[22]=min(a[22],b[22]),c[23]=min(a[23],b[23]),c[24]=min(a[24],b[24]),c[25]=min(a[25],b[25]);
	return c;
}

string s;

array<int,26> f[(1<<23)+5];

array<int,26> a[23];

mint dp[(1<<23)+5];

ll val[(1<<23)+5];

ll ans=0;

int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>s;
		for(int j=0;j<26;j++) a[i][j]=1;
		for(auto c:s) a[i][c-'a']++;
	}
	for(int i=0;i<26;i++) f[0][i]=2e4+1;
	for(int i=1;i<(1<<n);i++) f[i]=f[i^lowbit(i)]*a[lb(i)],val[i]=val[i^lowbit(i)]+lb(i)+1;
	for(int i=0;i<(1<<n);i++) {
		dp[i]=1;
		for(int j=0;j<26;j++) dp[i]*=f[i][j];
		if(__builtin_popcount(i)&1) dp[i]=0-dp[i];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<(1<<n);j++) {
			if((j>>i)&1) dp[j]+=dp[j^(1<<i)];
		}
	}
	for(int i=(1<<n)-1;i>=0;i--) ans^=(dp[0]-dp[i]).x*val[i]*__builtin_popcount(i);
	cout<<ans;
	return 0;
}
