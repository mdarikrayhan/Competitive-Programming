#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,fast-math",3)
#define cln cerr<<"Line:   "<<__LINE__<<"    "
#define pct __builtin_popcountll
#define ctz __builtin_ctzll
#define mkp make_pair
#define MST(x) memset(x,0,sizeof(x))
#define all(x) x.begin(),x.end()
using namespace std;
constexpr int N=(1<<20)+100,_g=3,M1=1e9+7,M2=1e9+9,M=998244353;
namespace fast_io{
	char buf[N+10],*p1,*p2,c;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,N,stdin),p1==p2))?EOF:*p1++
	static inline void read(int &x){
		for(c=gc;c<48;c=gc);
		for(x=0;c>47;x=(x<<1)+(x<<3)+(48^c),c=gc);
	}
	char ob[N+100],stk[505];int tp,ot;
	void fls(){fwrite(ob,1,ot,stdout),ot=0;}
    int cntt;
	static inline void write(int x){
        if(!cntt)atexit(fls),cntt=1;
		while(x>9)stk[++tp]=48^(x%10),x/=10;
		for(ob[ot++]=48^x;tp;ob[ot++]=stk[tp--]);
		ob[ot++]='\n';if(ot>N)fls();
	}
}using fast_io::read;
using fast_io::write;
using ll=long long;
#define pli pair<ll,int>
#define pii pair<int,int>
using ul=unsigned long long;
using ld=double;
mt19937_64 rg(random_device{}());
const ll INF=3e18;
template<typename tp1,typename tp2>
    void ckmx(tp1 &x,const tp2 &y){x<y?x=y:0;}
template<typename tp1,typename tp2>
    void ckmn(tp1 &x,const tp2 &y){x>y?x=y:0;}
void add(int &x,int y){(x+=y)>=M?x-=M:0;}
void del(int &x,int y){(x-=y)<0?x+=M:0;}
void add(int &x,ul y,int z){x=(y*z+x)%M;}
void del(int &x,ul y,int z){(x-=y*z%M)<0&&(x+=M);}
int qp(ll a,ll x=M-2){
    int res=1;for(;x;x>>=1,a=a*a%M)
        (x&1)&&(res=a*res%M);return res;
}
struct NTP{};
template<typename tp1,typename tp2,int N>
struct Htb{
    static constexpr int M=1e7+19;
    int hd[M+3],to[N],ct;
    tp1 ed[N];tp2 w[N];
    static int hc(ul v){
        v^=v<<13,v^=v>>7;
        return (v^(v<<17))%M;
    }
    void ins(tp1 x,tp2 y){
        int &p=hd[hc(x)];
        ed[++ct]=x,to[ct]=p;
        w[p=ct]=y;
    }
    int count(tp1 x){
        for(int i=hd[hc(x)];i;i=to[i])
            if(ed[i]==x)return 1;
        return 0;
    }
    pair<tp2,bool>find(tp1 x){
        for(int i=hd[hc(x)];i;i=to[i])
            if(ed[i]==x)return mkp(w[i],true);
        return mkp(0,false);
    }
    int operator[](tp1 x){
        int &p=hd[hc(x)];
        for(int i=p;i;i=to[i])
            if(ed[i]==x)return i;
        ed[++ct]=x,to[ct]=p;
        return p=ct;
    }
    void clear(){while(ct)hd[hc(ed[ct--])]=0;}
};
namespace MATH{
    vector<int>jc,nv;
    int dv2(int x){return x&1?x+M>>1:x>>1;}
    int C(int n,int m){
        assert(m<=n);
        return 1ll*jc[n]*nv[m]%M*nv[n-m]%M;
    }
    int P(int n,int m){
        return 1ll*jc[n]*nv[n-m]%M;
    }
    int D(int n,int m){
        if(n<0||m<0)return 0;
        if(!n)return 1;
        if(!m)return 0;
        return C(n+m-1,m-1);
    }
    void init(int n){
        int x;
        jc.resize(n+2),nv.resize(n+2);
        jc[0]=nv[0]=jc[1]=nv[1]=1;
        for(x=2;x<=n;++x){
            jc[x]=1ll*x*jc[x-1]%M;
            nv[x]=ll(M-M/x)*nv[M%x]%M;
        }
        for(x=1;x<=n;++x)nv[x]=1ll*nv[x-1]*nv[x]%M;
    }
}
struct DET{
    int a[3005][3005],n;
    int run(){
        if(!n)return 1;
        int x,y,z,k,res=1;
        for(x=1;x<=n;++x){
            for(y=x;y<=n&&!a[y][x];++y);
            if(y>n)return 0;
            if(y>x){
                for(k=1;k<=n;++k)swap(a[x][k],a[y][k]);
                res&&(res=M-res); 
            }
            k=qp(a[x][x]);
            res=1ll*res*a[x][x]%M;
            for(z=1;z<=n;++z)
                a[x][z]=1ll*a[x][z]*k%M;
            for(y=1;y<=n;++y)
                if(x!=y){
                    k=a[y][x];
                    for(z=1;z<=n;++z)
                        del(a[y][z],a[x][z],k);
                }
        }
        for(x=1;x<=n;++x)
            res=1ll*res*a[x][x]%M;
        return res;
    }
}det;
ll Gcd(ll x,ll y){
    if(!x||!y)return x|y;
    int k=min(ctz(x),ctz(y));
    ll d;y>>=ctz(y);
    while(x){
        x>>=ctz(x),d=x-y;
        if(x<y)y=x;
        if(d<0)x=-d;
        else x=d;
    }return y<<k;
}
using ll=long long;
using ul=unsigned long long;
constexpr int bceil(int n){return 1<<(std::__lg(n-1)+1);}
template<int mod>struct NTT{
    constexpr int dil(int x){return x>>31?x+mod:x;}
    constexpr int mul(ul x,int y){return x*y%mod;}
    constexpr int qpow(int a,int b,int r=1){for(;b;a=mul(a,a),b>>=1){r=b&1?mul(r,a):r;}return r;}
    int w[N>>1],wI[N>>1];
    void init(int n){
        int l=bceil(n)>>1;w[0]=wI[0]=1;
        for(int i=1;i<l;i<<=1){w[i]=qpow(_g,((mod-1)>>2)/i),wI[i]=qpow(_g,mod-1-((mod-1)>>2)/i);}
        for(int i=1;i<l;++i){w[i]=mul(w[i&(i-1)],w[i&-i]),wI[i]=mul(wI[i&(i-1)],wI[i&-i]);}
    }
    void dif(int *f,int lim){
        for(int l=lim>>1,r=lim;l;l>>=1,r>>=1)
            for(int*j=f,*o=w;j!=f+lim;j+=r,++o)
                for(int*k=j,x,y;k!=j+l;++k)
                    (x=*k)>=mod&&(x-=mod),y=mul(k[l],*o),*k=x+y,k[l]=x-y+mod;
    }
    void dit(int *f,int lim){
        for(int l=1,r=2;l<lim;l<<=1,r<<=1)
            for(int*j=f,*o=wI;j!=f+lim;j+=r,++o)
                for(int*k=j,x,y;k!=j+l;++k)
                    x=*k,y=mod-k[l],(*k=x-y)<0&&(*k+=mod),k[l]=mul(x+y,*o);
        for(int i=0,p=mod-(mod-1)/lim;i<lim;++i)f[i]=1ll*f[i]*p%mod;
    }
    void mul(int *f,int *g,int n){
        static int gg[N];
        memcpy(gg,g,n+2<<2);
        dif(f,n),dif(gg,n);
        for(int i=0;i<n;++i)f[i]=1ll*f[i]*gg[i]%M;
        dit(f,n);
    }
    void mul(int *f,int n){
        dif(f,n);int i;
        for(i=0;i<n;++i)f[i]=1ll*f[i]*f[i]%M;
        dit(f,n);
    }
};//NTT<M>ntt;
// using namespace MATH;
int T,n,m,a[N],b[N];
vector<pair<int,int>>ac;
void rec(int x,int y){
    int l=a[x],r=a[y];
    if(l>r)swap(l,r);
    ac.emplace_back(l,r);
    a[y]=r+l,a[x]=r-l;
}
using vt=vector<int>;
void sol(vt d){
    int n=d.size();
    if(!n)return;
    sort(all(d),[&](int x,int y){return a[x]<a[y];});
    for(int i=1;i<n;++i)assert(a[d[i]]==a[d[0]]*(i+1));
    if(n==(n&-n)){
        int rp=1,x,y;
        while(1){
            int k=1e9,c=-1e9;
            for(auto &p:d){
                if(a[p]>=rp)k=min(k,a[p]&-a[p]);
                c=max(c,a[p]);
            }
            if(k==c)return;
            m=0,rp=k<<1;
            for(auto &p:d)if(a[p]&k)b[++m]=p;
            x=(m&1)+1,y=m;
            while(x<y)rec(b[x++],b[y--]);
            sort(all(d),[&](int x,int y){return a[x]<a[y];});
        }
    }
    int K=1<<__lg(n),i;
    vt A,B;
    for(i=0;i<K-1;++i)
        if(K+K-i-2<n)
            rec(d[i],d[K+K-i-2]),A.push_back(d[i]);
        else B.push_back(d[i]);
    sol(A),sol(B);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,k,l,r,x,y,z,v1,v2;
    for(cin>>T;T--;){
        cin>>n;
        if(n<=2){
            puts("-1");
            continue;
        }ac.clear();
        for(x=1;x<=n;++x)a[x]=x;
        vt at(n);
        for(i=0;i<n;++i)at[i]=i+1;
        sol(at);
        v1=1<<__lg(n-1)+1;
        sort(a+1,a+n+1);
        for(x=1;x<n;++x)
            if(a[x]==a[x+1]&&a[x]!=v1)rec(x,x+1);
        sort(a+1,a+n+1);
        for(x=1;x<n;++x)
            if(a[x])
                while(a[x]<a[n])rec(1,x),rec(1,x);
        for(x=1;x<=n;++x)
            if(!a[x])rec(x,n);
        k=ac.size();
        assert(k<=n*5);
        printf("%d\n",k);
        for(auto &at:ac)printf("%d %d\n",at.first,at.second);
    }
    return 0;
}