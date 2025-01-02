#include "bits/stdc++.h"
#ifdef DEBUG
#include "PrettyDebug.hpp"
#else
#define debug(...) [](){}()
#define debuga(...) [](){}()
#endif
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(int i=a;i>=b;i--)
#define Fin(file) freopen(file,"r",stdin)
#define Fout(file) freopen(file,"w",stdout)
using namespace std; typedef long long ll;
constexpr int N=4e5+5; const double PI=acos(-1.0);
void DFT(complex<double> f[],int n){
    for(int i=n>>1;i;i>>=1){
        for(int j=0;j<n;j+=i*2){
            complex<double> w0(cos(PI/i),sin(PI/i)), w(1,0);
            for(int k=0;k<i;k++){
                auto x=f[j+k], y=f[i+j+k];
                f[j+k]=x+y; f[i+j+k]=(x-y)*w;
                w*=w0;
            }
        }
    }
}
void IDFT(complex<double> f[],int n){
    for(int i=1;i<n;i<<=1){
        for(int j=0;j<n;j+=i*2){
            complex<double> w0(cos(PI/i),sin(PI/i)), w(1,0);
            for(int k=0;k<i;k++){
                auto x=f[j+k], y=f[i+j+k]*w;
                f[j+k]=(x+y)/2.0; f[i+j+k]=(x-y)/2.0;
                w*=w0;
            }
        }
    }
    reverse(f+1,f+n);
}
int n,m,Q,a[N],b[N],A,B; complex<double> f0[N],g0[N],f1[N],g1[N],f2[N],g2[N],res[N]; ll ans[N];
signed main(){
    atexit([](){cerr<<"Time = "<<clock()<<" ms"<<endl;});
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>Q; For(i,1,n) cin>>a[i],A=max(A,a[i]);; For(i,1,m) cin>>b[i],B=max(B,b[i]);
    int O=1; while(O<=A+B+1) O<<=1;
    auto work=[&](complex<double> f[],complex<double> g[],int op,int dir){
        For(i,0,O-1) res[i]=f[i]*g[i];; IDFT(res,O);
        if(dir==0) { ll tt=0; For(i,0,A+B+1) ans[i]+=op*tt,tt+=ll(res[i].real()+0.5); }
        else { ll tt=0; Rev(i,A+B+1,0) tt+=ll(res[i].real()+0.5),ans[i]+=op*tt; }
    };
    For(i,1,n) f0[a[i]]+=1.0;
    For(i,1,m) g0[b[i]]+=1.0;
    For(i,1,n-1) f1[min(a[i],a[i+1])]+=1.0;
    For(i,1,n-1) f2[max(a[i],a[i+1])]+=1.0;
    For(i,1,m-1) g1[min(b[i],b[i+1])]+=1.0;
    For(i,1,m-1) g2[max(b[i],b[i+1])]+=1.0;
    DFT(f0,O); DFT(g0,O); DFT(f1,O); DFT(g1,O); DFT(f2,O); DFT(g2,O);
    work(f0,g0,1,1); work(f0,g0,-1,0);
    work(f1,g0,-1,1); work(f0,g1,-1,1);
    work(f2,g0,1,0); work(f0,g2,1,0);
    work(f1,g1,1,1); work(f2,g2,-1,0);
    while(Q--) { int x; cin>>x; cout<<ans[min(x,A+B+1)]<<'\n'; }
    return 0;
}

// CONTINUE, NON-STOPPING, FOR CHARLIEY
// START TYPING IF YOU DON'T KNOW WHAT TO DO
// STOP TYPING IF YOU DON'T KNOW WHAT YOU'RE DOING

// Started Coding On: April 27 Sat, 21 : 41 : 37