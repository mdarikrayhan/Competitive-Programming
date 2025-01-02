#include <bits/stdc++.h>
using namespace std;
const int V=1e5;
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

int n,m;

mint suf[100005];

mint ans=0;

mint dp[1005][1005],pre[1005][1005];

int a[1005],pr[1005];

mint solve(int k) {
	int ptr=0;
	for(int i=1;i<=n;i++) {
		while(ptr+1<=n && a[ptr+1]<=a[i]-k) ptr++;
		pr[i]=ptr;
	}
	dp[0][0]=1;
	for(int i=0;i<=n;i++) pre[i][0]=1;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) dp[i][j]=pre[pr[i]][j-1],pre[i][j]=pre[i-1][j]+dp[i][j];
	}
	mint ans=0;
	for(int i=1;i<=n;i++) ans+=dp[i][m];
	return ans;
}

int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i*(m-1)<=V;i++) suf[i]=solve(i);
	for(int i=1;i*(m-1)<=V;i++) ans+=i*(suf[i]-suf[i+1]);
	cout<<ans;
	return 0;
}
