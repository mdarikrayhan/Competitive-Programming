// LUOGU_RID: 159117492
// Problem: A. Mike and Frog
// Contest: Codeforces - Codeforces Round 305 (Div. 1)
// URL: https://codeforces.com/problemset/problem/547/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
using pii = pair<int, int>;
using ll = long long;

#define int ll
 
inline void read(int &x){
    int s=0; x=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')x=-1;ch=getchar();}
    while(ch>='0' && ch<='9') s=(s<<3)+(s<<1)+ch-'0',ch=getchar();
    x*=s;
}

const int N=1e6+5;

// xh+y
int h1, a1;
int x1, y1;
int h2, a2;
int x2, y2;

int nx1[N], nx2[N];
int m;

int add(int x, int y){
	return (x+y+m)%m;
}

int mul(int x, int y){
	return 1LL*x*y%m;
}

int cal(int x, int h, int y){
	return add(mul(x, h), y);
}

bool fl1, fl2;
int rt1, rt2;

int A[3], M[3];

int mul(int x, int p, int mod){
    int res=0;
    for(; p; p>>=1, x=(x+x)%mod) if(p&1) res=(res+x)%mod;
    return res;
}

int exgcd(int a, int b, int &x, int &y){
    if(!b) return x=1, y=0, a;
    int d=exgcd(b, a%b, y, x);
    y-=a/b*x;
    return d;
}

int exCRT(int n, int *A, int *M){
    int x, y;
    int m=M[1], res=(A[1]%m+m)%m;
    rep(i, 2, n){
        int a=m, b=M[i], d=((A[i]-res)%b+b)%b;
        int g=exgcd(a, b, x, y);
        if(d%g) return -1;

        int P=b/g;
        x=mul(x, d/g, P);
        res+=x*m, m*=P;
        (res=res%m+m)%=m;
    }
    return res;
}

signed main(){
	cin>>m;
	cin>>h1>>a1>>x1>>y1;
	cin>>h2>>a2>>x2>>y2;
	int u1=h1, u2=h2;
	rep(i, 1, m){
		if(nx1[u1]==cal(x1, u1, y1)) rt1=u1;
		nx1[u1]=cal(x1, u1, y1);
		u1=nx1[u1];
		// if(u1==a1) fl1=true;
		
		if(nx2[u2]==cal(x2, u2, y2)) rt2=u2;
		nx2[u2]=cal(x2, u2, y2);
		u2=nx2[u2];
		// if(u2==a2) fl2=true;
		
		if(u1==a1 && u2==a2){
			cout<<i<<endl;
			return 0;
		}
	}
	
	
	int sz1=1, sz2=1;
	int t1=rt1, t2=rt2;
	if(t1==a1) fl1=true;
	if(t2==a2) fl2=true;
	while(nx1[t1]!=rt1){
		t1=nx1[t1], sz1++;	
		if(t1==a1) fl1=true;
	}
	while(nx2[t2]!=rt2){
		t2=nx2[t2], sz2++;
		if(t2==a2) fl2=true;
	}
	// debug(sz1),debug(sz2);
	if(!(fl1 && fl2)){
		puts("-1");
		return 0;
	}
	
	int d1=0, d2=0;
	u1=h1, u2=h2;
	while(u1!=rt1) u1=nx1[u1], d1++;
	while(u2!=rt2) u2=nx2[u2], d2++;
	int res=max(d1, d2);
	rep(i, d1+1, d2) u1=nx1[u1];
	rep(i, d2+1, d1) u2=nx2[u2];
	
	d1=0, d2=0;
	while(u1!=a1) d1++, u1=nx1[u1];
	while(u2!=a2) d2++, u2=nx2[u2];
	// find min t 
	// t % sz1 == d1
	// t % sz2 == d2
	M[1]=sz1, M[2]=sz2;
	A[1]=d1, A[2]=d2;
	
	int t=exCRT(2, A, M);
	if(t==-1){
		puts("-1");
		return 0;
	}
	cout<<t+res<<endl;
	
	return 0;
}