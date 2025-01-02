// LUOGU_RID: 159128616
#include<bits/stdc++.h>
/* --------------- fast io --------------- */ // begin
namespace Fread {
const int SIZE = 1 << 21;
char buf[SIZE], *S, *T;
inline char getchar() {
	if (S == T) {
		T = (S = buf) + fread(buf, 1, SIZE, stdin);
		if (S == T) return '\n';
	}
	return *S++;
}
} // namespace Fread
namespace Fwrite {
const int SIZE = 1 << 21;
char buf[SIZE], *S = buf, *T = buf + SIZE;
inline void flush() {
	fwrite(buf, 1, S - buf, stdout);
	S = buf;
}
inline void putchar(char c) {
	*S++ = c;
	if (S == T) flush();
}
struct NTR {
	~ NTR() { flush(); }
} ztr;
} // namespace Fwrite
#ifdef ONLINE_JUDGE
#define getchar Fread :: getchar
#define putchar Fwrite :: putchar
#endif
namespace Fastio {
struct Reader {
	template<typename T>
	Reader& operator >> (T& x) {
		char c = getchar();
		T f = 1;
		while (c < '0' || c > '9') {
			if (c == '-') f = -1;
			c = getchar();
		}
		x = 0;
		while (c >= '0' && c <= '9') {
			x = x * 10 + (c - '0');
			c = getchar();
		}
		x *= f;
		return *this;
	}
	Reader& operator >> (char& c) {
		c = getchar();
		while (c == ' ' || c == '\n') c = getchar();
		return *this;
	}
	Reader& operator >> (char* str) {
		int len = 0;
		char c = getchar();
		while (c == ' ' || c == '\n') c = getchar();
		while (c != ' ' && c != '\n' && c != '\r') { // \r\n in windows
			str[len++] = c;
			c = getchar();
		}
		str[len] = '\0';
		return *this;
	}
	Reader(){}
} cin;
const char endl = '\n';
struct Writer {
	template<typename T>
	Writer& operator << (T x) {
		if (x == 0) { putchar('0'); return *this; }
		if (x < 0) { putchar('-'); x = -x; }
		static int sta[45];
		int top = 0;
		while (x) { sta[++top] = x % 10; x /= 10; }
		while (top) { putchar(sta[top] + '0'); --top; }
		return *this;
	}
	Writer& operator << (char c) {
		putchar(c);
		return *this;
	}
	Writer& operator << (char* str) {
		int cur = 0;
		while (str[cur]) putchar(str[cur++]);
		return *this;
	}
	Writer& operator << (const char* str) {
		int cur = 0;
		while (str[cur]) putchar(str[cur++]);
		return *this;
	}
	Writer(){}
} cout;
} // namespace Fastio
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
/* --------------- fast io --------------- */ // end
#define ll long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=1e6+5;
int n,m;
ll ans,ans1,ans2;
int val[N<<2],idx;
struct node{
	int l,r;
	ll w;
	int op,id;
}a[N],b[N],c[N];
ll tr[N<<2];
int pos[N<<2];
void upd(int l,int r,int fl,ll k,int kk,int x){
	if(l==r){
		if(tr[x]<k) tr[x]=k,pos[x]=kk;
		return;
	}
	int mid=l+r>>1;
	if(fl<=mid) upd(l,mid,fl,k,kk,x<<1);
	else upd(mid+1,r,fl,k,kk,x<<1|1);
	if(tr[x<<1]>tr[x<<1|1]) tr[x]=tr[x<<1],pos[x]=pos[x<<1];
	else tr[x]=tr[x<<1|1],pos[x]=pos[x<<1|1];
}
ll mxx;
int id;
void ask(int l,int r,int fl,int fr,int x){
	if(fl<=l && r<=fr){
//		cout<<val[l]<<' '<<val[r]<<' '<<tr[x]<<' '<<pos[x]<<'\n';
		if(tr[x]>mxx) mxx=tr[x],id=pos[x];
		return;
	}
	int mid=l+r>>1;
	if(fl<=mid) ask(l,mid,fl,fr,x<<1);
	if(fr>mid) ask(mid+1,r,fl,fr,x<<1|1);
}
bool cmp1(node d,node e){
	if(d.r==e.r) return d.op<e.op;
	return d.r<e.r;
}
bool ff;
void solve0(bool f){
	memset(tr,0,sizeof tr);
	if(f){
		for(int i=1;i<=m;i++) c[i]=a[i],c[i].op=0;
		for(int i=1;i<=n;i++) c[i+m]=b[i],c[i+m].op=1;
	}else{
		for(int i=1;i<=n;i++) c[i]=a[i],c[i].op=0;
		for(int i=1;i<=m;i++) c[i+n]=b[i],c[i+n].op=1;
	}
	n+=m;
	sort(c+1,c+1+n,cmp1);
	for(int i=1;i<=n;i++){
		int l=c[i].l,r=c[i].r;
		ll w=c[i].w;
		if(!c[i].op) upd(1,idx,l,(val[r]-val[l])*w,c[i].id,1);
		else{
			mxx=0;
			ask(1,idx,l,r,1);
			ll x=mxx*w;
			if(x>ans){
				ans=x,ans1=id,ans2=c[i].id;
				if(f) swap(ans1,ans2);
			}
		}
	}
	n-=m;
}
int cnt;
struct LINE{
	int k;
	ll b;
}ln[N];
int vis[N];
int ww[N];
void add_line(ll sx,ll sy,ll ex,ll ey,ll k){
	vis[++cnt]=k;ww[cnt]=sy;
	if(sx==ex) ln[cnt]={0,max(sy,ey)};
	else ln[cnt].k=(ey-sy)/(ex-sx),ln[cnt].b=sy-ln[cnt].k*sx;
}
ll calc(int k,ll x){
	x=val[x];
	return 1ll*ln[k].k*x+ln[k].b;
}
int cmp(ll x,ll y){
	if(x>y) return 1;
	if(x<y) return -1;
	return 0;
}
void upt(int l,int r,int fl,int fr,ll k,int x){
	if(fl<=l && r<=fr){
		ll &now=tr[x];
		int mid=l+r>>1;
		int s=cmp(calc(k,mid),calc(now,mid));
		if(s==1 || (!s && k<now)) swap(now,k);
		int sl=cmp(calc(k,l),calc(now,l)),sr=cmp(calc(k,r),calc(now,r));
		if(sl==1 || (!sl && k<now)) upt(l,mid,fl,fr,k,x<<1);
		if(sr==1 || (!sr && k<now)) upt(mid+1,r,fl,fr,k,x<<1|1);
		return;
	}
	int mid=l+r>>1;
	if(fl<=mid) upt(l,mid,fl,fr,k,x<<1);
	if(fr>mid) upt(mid+1,r,fl,fr,k,x<<1|1);
}
void get_max(pair<ll,int>&x,pair<ll,int>y){
	if(cmp(x.fi,y.fi)==-1 || (cmp(x.fi,y.fi)==0 && x.se>=y.se)) x=y;
}
pair<ll,int>query(int l,int r,int fl,int x){
	ll now=calc(tr[x],fl);
	if(l==r) return {now,tr[x]};
	int mid=l+r>>1;
	pair<ll,int> ans;
	ans={now,tr[x]};
	if(fl<=mid) get_max(ans,query(l,mid,fl,x<<1));
	else get_max(ans,query(mid+1,r,fl,x<<1|1));
	return ans;
}
bool cmp2(node d,node e){
	if(d.l==e.l) return d.op<e.op;
	return d.l<e.l;
}
void solve1(bool f){
	memset(tr,0,sizeof tr);cnt=0;
	if(f){
		for(int i=1;i<=m;i++) c[i]=a[i],c[i].op=0;
		for(int i=1;i<=n;i++) c[i+m]=b[i],c[i+m].op=1;
	}else{
		for(int i=1;i<=n;i++) c[i]=a[i],c[i].op=0;
		for(int i=1;i<=m;i++) c[i+n]=b[i],c[i+n].op=1;
	}
	n+=m;
	sort(c+1,c+1+n,cmp2);
	for(int i=n;i>=1;i--){
		ll l=c[i].l,r=c[i].r,w=c[i].w,op=c[i].op;
		if(!op){
			add_line(val[l],w,val[r],(val[r]-val[l]+1)*w,c[i].id);
			upt(1,idx,l,r,cnt,1);
		}else{
			pair<ll,int> now=query(1,idx,r,1);
			ll x=w*(now.fi-ww[now.se]);
//			cout<<vis[now.se]<<' '<<c[i].id<<' '<<now.fi<<' '<<x<<'\n';
			if(ans<x){
//				cout<<w<<' '<<(ll)now.fi<<' '<<((ll)ln[now.se].k)<<'\n';
				ans=x,ans1=vis[now.se],ans2=c[i].id;
				if(f) swap(ans1,ans2);
			}
		}
	}
	n-=m;
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r,a[i].w=1,val[++idx]=a[i].l,val[++idx]=a[i].r;
	for(int i=1;i<=m;i++) cin>>b[i].l>>b[i].r>>b[i].w,val[++idx]=b[i].l,val[++idx]=b[i].r;
	sort(val+1,val+1+idx);
	idx=unique(val+1,val+1+idx)-val-1;
	for(int i=1;i<=n;i++){
		a[i].id=i;
		a[i].l=lower_bound(val+1,val+1+idx,a[i].l)-val;
		a[i].r=lower_bound(val+1,val+1+idx,a[i].r)-val;
	}
	for(int i=1;i<=m;i++){
		b[i].id=i;
		b[i].l=lower_bound(val+1,val+1+idx,b[i].l)-val;
		b[i].r=lower_bound(val+1,val+1+idx,b[i].r)-val;
	}
	solve0(0);swap(a,b),solve0(1);
	solve1(1);swap(a,b);solve1(0);
	cout<<ans;
//	if(ans==197724995467392635) cout<<'\n'<<val[a[ans1].l]<<' '<<val[a[ans1].r]<<' '<<val[b[ans2].l]<<' '<<val[b[ans2].r]<<' '<<b[ans2].w<<'\n';
	if(ans) cout<<'\n'<<ans1<<' '<<ans2;
	return 0;
}