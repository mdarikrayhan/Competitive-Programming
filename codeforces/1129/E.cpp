#include<bits/stdc++.h>
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
const int Maxn=5e2+10;
int siz[Maxn];
int n;
inline int getsiz(int x){
    cout<<1<<endl<<1<<endl<<n-2<<endl;
    fr(i,2,n) if(i!=x) cout<<i<<' ';cout<<endl;
    cout<<x<<endl;
    int ans;cin>>ans;
    return ans;
}
int p[Maxn];
inline bool cmp(int a,int b){return siz[a]<siz[b];}
inline void init(){
    cin>>n;siz[1]=n;p[1]=1;
    if(n==2){
        cout<<"ANSWER"<<endl;
        cout<<1<<' '<<2<<endl;
        exit(0);
    }
    fr(i,2,n) siz[i]=getsiz(i)+1,p[i]=i;
}
inline int query(vector<int> &now,int x){
    cout<<1<<endl<<1<<endl<<now.size()<<endl;
    for(auto p:now) cout<<p<<' ';cout<<endl;
    cout<<x<<endl;
    int ans;cin>>ans;
    return ans;
}
inline vector<int> merge(vector<int> a,vector<int> b){
    vector<int> now;
    for(auto x:a) now.pb(x);
    for(auto x:b) now.pb(x);
    return now;
}
vector<int> vc;
vector<pii> edge;
inline vector<int> solve(vector<int> now,int x){
    if(now.empty()) return now;
    if(query(now,x)==0) return now;
    if(now.size()==1){
        edge.pb(mk(x,now[0]));
        vector<int> ().swap(now);
        return now;
    }
    vector<int> vc1,vc2;
    int ln=now.size();
    fr(i,0,ln/2-1) vc1.pb(now[i]);
    fr(i,ln/2,ln-1) vc2.pb(now[i]);
    now=merge(solve(vc1,x),solve(vc2,x));
    return now;
}
inline void work(){
    sort(p+1,p+n+1,cmp);
    fr(i,1,n){
        int x=p[i];
        if(siz[x]==1){vc.pb(x);continue;}
        if(i==n){
            while(!vc.empty()) edge.pb(mk(x,vc.back())),vc.pop_back();
            continue;
        }
        // cout<<"*"<<x<<' '<<vc.size()<<endl;
        vc=solve(vc,x);vc.pb(x);
    }
    cout<<"ANSWER"<<endl;
    for(auto x:edge) cout<<x.first<<' '<<x.second<<endl;
    // fr(i,1,n) cout<<i<<' '<<siz[i]<<endl;
}
signed main(){
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
    init();work();
    // printf("\nTIME:%.3lf",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}