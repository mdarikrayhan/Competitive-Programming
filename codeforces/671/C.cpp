#include<bits/stdc++.h>
// #define int long long
#define fr(i,j,k) for(register int i=j;i<=k;++i)
#define rf(i,j,k) for(register int i=j;i>=k;--i)
#define foredge(i,j) for(register int i=head[j];i;i=e[i].nxt)
#define pb push_back
#define Times printf("Time:%.3lf\n",clock()/CLOCKS_PER_SEC)
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void writeln(int x){write(x); puts("");}
inline void writepl(int x){write(x); putchar(' ');}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int randfind(int l,int r){return rnd()%(r-l+1)+l;}
//inline void init(){
//	int t=read();
//	while(t--) work();
//}
const int Maxn=2e5+10;
int n,a[Maxn];
vector<int> vc[Maxn];
vector<int> num[Maxn];
int L[Maxn],R[Maxn];
int maxn;
inline void init(){
    n=read();
    fr(i,1,n) a[i]=read();
    fr(i,1,n) maxn=max(maxn,a[i]);
    fr(i,1,maxn) fr(j,1,maxn/i) vc[i*j].push_back(i);
    fr(i,1,n) for(auto x:vc[a[i]]) num[x].push_back(i);
}
long long answer;
namespace sgt{
    long long s[Maxn<<2];
    int tag[Maxn<<2];
    inline int ls(int x){return x<<1;}
    inline int rs(int x){return x<<1|1;}
    inline void pushup(int x){s[x]=s[ls(x)]+s[rs(x)];}
    inline void change(int x,int l,int r,int k){
        s[x]=1ll*(r-l+1)*k;
        tag[x]=k;
    }
    inline void pushdown(int x,int l,int r){
        if(tag[x]){
            int mid;
            mid=(l+r)>>1;
            change(ls(x),l,mid,tag[x]);
            change(rs(x),mid+1,r,tag[x]);
            tag[x]=0;
        }
    }
    inline void update(int ql,int qr,int l,int r,int x,int k){
        // cout<<ql<<' '<<qr<<' '<<l<<' '<<r<<' '<<x<<' '<<k<<endl;
        if(ql<=l && r<=qr){
            change(x,l,r,k);
            return;
        }
        pushdown(x,l,r);
        int mid;
        mid=(l+r)>>1;
        if(ql<=mid) update(ql,qr,l,mid,ls(x),k);
        if(mid<qr) update(ql,qr,mid+1,r,rs(x),k);
        pushup(x);
    }
    inline long long query(int ql,int qr,int l=1,int r=n,int x=1){
        if(ql<=l && r<=qr) return s[x];
        pushdown(x,l,r);
        int mid;
        mid=(l+r)>>1;
        long long ans=0;
        if(ql<=mid) ans+=query(ql,qr,l,mid,ls(x));
        if(mid<qr) ans+=query(ql,qr,mid+1,r,rs(x));
        return ans; 
    }
}
vector<pair<int,int> > Que[Maxn];
inline void work(){
    if(n<=2){
        puts("0");
        return;
    }
    Que[1].push_back(make_pair(n-2,1));
    Que[2].push_back(make_pair(n-1,1));
    Que[3].push_back(make_pair(n,1));
    // fr(i,2,maxn) if(L[i]<R[i]){
    //     // cout<<i<<' '<<L[i]<<' '<<R[i]<<endl;
    //     if(L[i]>1) Que[1].push_back(make_pair(L[i]-1,i));
    //     Que[L[i]+1].push_back(make_pair(R[i]-1,i));
    //     if(R[i]<n) Que[R[i]+1].push_back(make_pair(n,i));
    // }
    fr(i,2,maxn){
        if(num[i].size()<2) continue;
        int L=num[i][0],R=num[i][1];
        if(L>1) Que[1].push_back(make_pair(L-1,i));
        Que[L+1].push_back(make_pair(R-1,i));
        if(R<n) Que[R+1].push_back(make_pair(n,i));
        L=num[i][num[i].size()-2],R=num[i][num[i].size()-1];
        // cout<<i<<' '<<L<<' '<<R<<endl;
        if(L>1) Que[1].push_back(make_pair(L-1,i));
        Que[L+1].push_back(make_pair(R-1,i));
        if(R<n) Que[R+1].push_back(make_pair(n,i));
        L=num[i][0],R=num[i].back();
        if(L>1) Que[1].push_back(make_pair(L-1,i));
        Que[L+1].push_back(make_pair(R-1,i));
        if(R<n) Que[R+1].push_back(make_pair(n,i));
    }
    fr(i,1,n){
        for(auto p:Que[i]){
            // cout<<"*"<<i<<' '<<p.first<<' '<<p.second<<endl;
            int l=i,r=p.first;
            int ans=0;
            while(l<=r){
                int mid;
                mid=(l+r)>>1;
                if(sgt::query(mid,mid)<=p.second) ans=mid,r=mid-1;
                else l=mid+1;
            }
            // cout<<ans<<endl;
            if(ans<=p.first && ans) sgt::update(ans,p.first,1,n,1,p.second);
        }
        // fr(j,i,n) cout<<sgt::query(j,j)<<' ';cout<<endl;
        answer+=sgt::query(i,n);
        // cout<<answer<<endl;
    }
    printf("%lld\n",answer);
}
signed main(){
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
    init();work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}