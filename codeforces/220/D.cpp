#pragma GCC optimize("-Ofast","-ffast-math","-funroll-all-loops")
#include <bits/stdc++.h>
using namespace std;
struct Init {
Init() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0);
#endif
}
} init__;
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int gcd(int x,int y) {
    return y?gcd(y,x%y):x;
}
typedef double ld;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define rep(x,l,r) for(int x=(l);x<=(r);++x)
#define rep0(x,n) for(int x=0;x<(n);++x)
#define rep1(x,n) for(int x=1;x<=(n);++x)
#define sz(s) (int((s).size()))
#define SZ 666666
int w,h;
const int MOD=1e9+7;
int aX[8005][2],aY[8005][2];
int ceven(int l,int r) {
    if(l>r) return 0;
    --l;
    if(r&1) --r;
    if(l&1) --l;
    return (r-l)/2;
}
template<class T>
void work(T& aY, int h) {
    for(int x=-h;x<=h;++x) {
        int L=min(x,0),R=max(x,0);
        for(int u=L-1;u>=-h;--u) {
            int p=u&1;
            int M=u,U=R;
            int e=h-(U-M)+1;
            if(e<0) break;
            (aY[x&1][p]+=e);
        }
        aY[x&1][0]+=ceven(L,R)*(ll)(h-(R-L)+1)%MOD;
        aY[x&1][1]+=ceven(L-1,R-1)*(ll)(h-(R-L)+1)%MOD;
        for(int u=R+1;u<=h;++u) {
            int p=u&1;
            int M=L,U=u;
            int e=h-(U-M)+1;
            if(e<0) break;
            (aY[x&1][p]+=e);
        }
        for(int p=0;p<=1;++p) aY[x&1][p]%=MOD;
    }
}
bool gcdd[4005][4005];
int main() {
    cin>>w>>h;
    for(int i=0;i<=max(w,h);++i) {
        gcdd[i][i]=gcdd[i][0]=gcdd[0][i]=i==1;
        for(int j=1;j<i;++j) {
            gcdd[i][j]=gcdd[j][i]=gcdd[j][i%j];
        }
    }
    work(aX,w);
    work(aY,h);
    cerr<<"A\n";
    ll ans=0;
    for(int x=0;x<2;++x)
        for(int y=0;y<2;++y) {
            for(int p=0;p<=1;++p)
                for(int q=0;q<=1;++q) {
                    if((x*q+p*y)%2==0) continue;
                    ans+=aX[x][p]*(ll)aY[y][q]; ans%=MOD;
                }
        }
    cerr<<"A\n";
    ll tot=(w+1)*(h+1);
    tot=tot*(tot-1)%MOD*(tot-2)%MOD;
    cerr<<tot<<"\n";
    cerr<<ans<<"+\n";
    tot-=ans;
    /*
    typedef pair<int,int> pii;
    map<int,vector<pii>> s;
    for(int i=-w;i<=w;++i)
        for(int j=-h;j<=h;++j) {
            if(i||j);else continue;
            int X=i,Y=j,G=gcd(X,Y);
            X/=G,Y/=G;
            if(X<0) X=-X,Y=-Y;
            if(X==0&&Y<0) Y=-Y;
            s[X*10000+Y].pb(pii(i,j));
        }
    auto work=[&](int s,int p,int q) {
        int L=min(min(p,q),0),R=max(max(p,q),0);
        return max(s-(R-L)+1,0);
    };
    for(auto p:s) {
        for(auto a:p.se)
            for(auto b:p.se) {
                if(a==b) continue;
                tot-=work(w,a.fi,b.fi)*(ll)work(h,a.se,b.se);
                tot%=MOD;
            }
    }*/
    for(int i=0;i<=w;++i)
        for(int j=i?(-h):1;j<=h;++j) if(gcdd[abs(i)][abs(j)]==1) {
            int X=i,Y=j;
            X=abs(X),Y=abs(Y);
            int up=1e9;
            if(X) up=min(up,w/X);
            if(Y) up=min(up,h/Y);
            --up;
            if(1>up) continue;
            int U=w+1-X,V=h+1-Y;
            for(int s=1;s<=up;++s)
                tot-=(U-X*s)*(V-Y*s)*(ll)s*6;//,tot%=MOD;
            tot%=MOD;
            // for(int s=2;s<=up;++s)
            //     tot-=(w+1-X*s)*(h+1-Y*s)*(s-1)*6;
        }
    // for(int i=0;i<=w;++i)
    //     tot-=(h+1)*(ll)h%MOD*(h-1)%MOD;
    // for(int i=0;i<=h;++i)
    //     tot-=(w+1)*(ll)w%MOD*(w-1)%MOD;
    tot=(tot%MOD+MOD)%MOD;
    cout<<tot<<"\n";
}