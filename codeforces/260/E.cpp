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
int n,a[30];
#define pc __builtin_popcount
typedef pair<int,int> pii;
pii operator + (pii a,pii b) {
    return pii(max(a.fi,b.fi),min(a.se,b.se));
}
#define x first
#define y second
pii p[SZ];int q[SZ];
vector<pair<pii,pii> > G[2][1<<9];
//vector<pair<pair<pii,pii>,vector<int> > > G[3];
int SU[SZ];
bool ne(pii s) {
    return s.fi<s.se;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;++i) cin>>p[i].x>>p[i].y;
    sort(p+1,p+1+n);
    for(int i=0;i<9;++i) cin>>a[i];
    for(int i=0;i<(1<<9);++i)
        for(int j=0;j<9;++j) if(i&(1<<j)) SU[i]+=a[j];
    auto chk=[&](int*q,const int*b,int tot) {
sort(q+1,q+1+tot);
//            nth_element(q+1,q+b[0],q+1+tot);
//            nth_element(q+b[0]+1,q+b[1]+b[0]+1,q+1+tot);
            int*L=q+b[0]+1,*R=q+b[0]+b[1];
            pii A(q[b[0]],q[b[0]+1]),
            B(q[b[0]+b[1]],q[b[0]+b[1]+1]);
            return mp(A,B);
    };
    for(int U=0;U<(1<<9);++U) if(pc(U)==3) {
        vector<int> b; int CUT=SU[U];
        for(int s=0;s<9;++s) if(U&(1<<s)) b.pb(a[s]); // actually a[s] suffice
        sort(b.begin(),b.end());
        do {
            for(int i=1;i<=CUT;++i) q[i]=p[i].y;
            auto _=chk(q,b.data(),CUT);
            auto A=_.fi,B=_.se;
            // cerr<<U<<":"<<A.fi<<","<<A.se<<" "<<B.fi<<","<<B.se<<"\n";
            if(ne(A)&&ne(B)) G[0][U].pb({A,B});
        }while(next_permutation(b.begin(),b.end()));
    }
    // exit(0);
    for(int U=0;U<(1<<9);++U) if(pc(U)==3) {
        vector<int> b; int CUT=SU[U];
        for(int s=0;s<9;++s) if(U&(1<<s)) b.pb(a[s]);
        sort(b.begin(),b.end());
        do {
            for(int i=1;i<=CUT;++i) q[i]=p[i+n-CUT].y;
            auto _=chk(q,b.data(),CUT);
            auto A=_.fi,B=_.se;
            if(ne(A)&&ne(B)) G[1][U].pb({A,B});
        }while(next_permutation(b.begin(),b.end()));
    }
    int b[3];
    int C=0;
    for(b[0]=0;b[0]<(1<<9);++b[0]) if(pc(b[0])==3)
        for(b[1]=0;b[1]<(1<<9);++b[1]) if(!(b[0]&b[1])&&pc(b[1])==3) {
            b[2]=((1<<9)-1)^b[0]^b[1];
            // if(b[0]>b[2]) continue;
            int C0=SU[b[0]],C1=SU[b[1]],C2=SU[b[2]];
            // cerr<<C0<<","<<C1<<","<<C2<<"\n";
            if(p[C0].x==p[C0+1].x) continue;
            if(p[C0+C1].x==p[C0+C1+1].x) continue;
            // cerr<<"checking..\n";
            for(auto A:G[0][b[0]])
                for(auto B:G[1][b[2]]) {
                    // cerr<<A.fi.fi<<"~"<<B.fi.fi<<"\n";
                    pii L=A.fi+B.fi,R=A.se+B.se;
                    // cerr<<L.fi<<","<<L.se<<" "<<R.fi<<","<<R.se<<"\n";
                    if(ne(L)==0||ne(R)==0) continue;
                    // cerr<<"here\n";
                    int X=0,Y=0,Z=0,FuzzL=0,FuzzR=0;
                    for(int s=C0+1;s<=C0+C1;++s) {
                        int u=p[s].y;
                        if(u<=L.fi) ++X;
                        else if(u>=R.se) ++Z;
                        else if(u>=L.se&&u<=R.fi) ++Y;
                        else if(u<L.se) ++FuzzL;
                        else ++FuzzR;
                    }
                    // try to match...
                    vector<int> s;
                    for(int u=0;u<9;++u) if(b[1]&(1<<u)) s.pb(a[u]);
                    sort(s.begin(),s.end());
                    do {
                        for(int i=1;i<=C1;++i) q[i]=p[i+C0].y;
                        auto _=chk(q,s.data(),C1);
                        auto LL=L+_.fi,RR=R+_.se;
                        if(ne(LL)&&ne(RR)) {
                            auto prt=[&](int s) {
                                if(s>0) {
                                    printf("%d.5",s);
                                }
                                else printf("-%d.5",-s-1);
                            };
                            assert(p[C0].x<p[C0+C1].x);
                            assert(LL.fi<RR.fi);
                            prt(p[C0].x);
                            printf(" ");
                            prt(p[C0+C1].x);
                            printf("\n");
                            prt(LL.fi);
                            printf(" ");
                            prt(RR.fi);
                            printf("\n");
                            exit(0);
                        }
                    }while(next_permutation(s.begin(),s.end()));
                }
            ++C;
        }
    cerr<<C<<"+\n";
    printf("-1\n");
}
