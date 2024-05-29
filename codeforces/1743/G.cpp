#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(register int i=j;i<=k;++i)
#define rf(i,j,k) for(register int i=j;i>=k;--i)
#define foredge(i,j) for(register int i=head[j];i;i=e[i].nxt)
#define pb push_back
#define pii pair<int,int>
#define mk make_pair
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
const int Maxn=1e3+10,mod=998244353,N=50;
inline void add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
int n;char c[Maxn];
vector<pii> vc,vc1;
int ans=1;
ll f[100];
inline int getc(int x){
    rf(i,N,2) if(x>f[i]) x-=f[i];
    // cout<<x<<endl;
    return x==1;
}
inline bool checkln(int x){fr(i,1,N) if(f[i]==x) return true;return false;}
inline void init(){
    n=read();
    f[0]=f[1]=1;fr(i,2,N) f[i]=f[i-1]+f[i-2];
}
inline void work(){
    int id=0;
    // cerr<<"**"<<endl;
    vc.pb(mk(0,1));
    // cout<<getc(3)<<endl;
    fr(i,1,n){
        scanf("%s",c+1);
        int ln=strlen(c+1);
        fr(j,1,ln){
            ++id;
            vector<pii> ().swap(vc1);
            int nc=c[j]-'0';
            int now=ans;
            for(auto p:vc){
                int nowln=id-p.first;
                if(nowln==1 || getc(nowln)==nc){
                    // cout<<"**"<<' '<<j<<' '<<p.second<<endl;
                    if(checkln(nowln)) add(now,mod-p.second);
                    if(nowln>1 || nc==1) vc1.pb(p);
                }
            }
            // cout<<j<<' '<<now<<' '<<ans<<endl;
            swap(vc,vc1);
            add(ans,now);
            vc.pb(mk(id,now));
            if(j==ln) writeln(now);
        }
    }
}
signed main(){
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
    init();work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}