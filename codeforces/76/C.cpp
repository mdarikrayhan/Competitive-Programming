#include<bits/stdc++.h>
using namespace std;
#define int long long
const int K=22;
int n,k,T,all,lst[K],t[K],a[K][K],f[1<<K];
char s[200005];
signed main(){
	cin.tie(0);
	cin>>n>>k>>T>>s;
	for(int i=0;i<n;i++){
		s[i]-='A';
		all|=1<<s[i];
	}
    for(int i=0;i<k;i++)cin>>t[i];
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)cin>>a[i][j];
    memset(lst,-1,sizeof(lst));
    for(int i=0;i<k;i++)f[1<<i]=t[i];               
    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++)if(lst[j]>=0) {
                if(!((lst[j]>>j)&1)&&!((lst[j]>>s[i])&1)) {
                    f[lst[j]]+=a[j][s[i]];
                    f[lst[j]|(1<<j)]-=a[j][s[i]];
                    f[lst[j]|(1<<s[i])]-=a[j][s[i]];
                    f[lst[j]|(1<<j)|(1<<s[i])]+=a[j][s[i]];
                }
                lst[j]|=(1<<s[i]);
            }
        lst[s[i]]=0;
    }
    for(int i=0;i<k;i++)
        for(int j=0;j<(1<<k);j++)
            if((j>>i)&1)
                f[j]+=f[j^(1<<i)]; 
    int ans=0;
    for(int i=0;i<(1<<k);i++){
    	if((i&all)==i&&f[i]<=T&&i!= all)ans++;
	} 
    cout<<ans;
    return 0;
}




#if 0
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define rint register int
#define maxn 1000010
#define root 1,n,1
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
int n, m;
int a[maxn << 2], lst[maxn << 2];
int tree[maxn << 2], ans[maxn << 2];
vector<int> vis[maxn << 2];
struct QUE{
	int l, r, id;
}q[maxn << 3];
inline void read(int &x){
	char ch=getchar();int f=1;x=0;
	while(!isdigit(ch) && ch^'-') ch=getchar();
	if(ch=='-') f=-1,ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	x*=f;
}
inline bool cmp(const QUE &a, const QUE &b) {
	return a.r < b.r;
}
void update(int rt) {
	tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}
void build(int l, int r, int rt, int tar){
	if(l == r && l == tar){
		tree[rt] = 1;
		return;
	}
	int mid=(l+r)>>1;
	if(tar<=mid) build(lson,tar);
	else build(rson,tar);
	update(rt);
}

void modify(int l,int r,int rt,int tar){
	if(l==r && l==tar){
		tree[rt]=0; return;
	}
	int mid=(l+r)>>1;
	if(tar<=mid) modify(l,mid,rt<<1,tar);
	else modify(mid+1,r,rt<<1|1,tar);
	update(rt);
}

int query(int l,int r,int rt,int nowl,int nowr){
	if(l==nowl&&r==nowr) return tree[rt];
	int mid=(l+r)>>1;
	if(nowr<=mid) return query(lson,nowl,nowr);
	else if(mid<nowl) return query(rson,nowl,nowr);
	else return query(lson,nowl,mid)+query(rson,mid+1,nowr);
}

int main(){
	read(n);
	for(rint i=1;i<=n;++i) read(a[i]);
	read(m);
	for(rint i=1;i<=m;++i){
		read(q[i].l); read(q[i].r);
		q[i].id=i;
	}
	
	sort(q + 1, q + m + 1, cmp);
	for(rint i = 1; i <= m; ++i) vis[q[i].r].push_back(i);

	for(rint i = 1; i <= n; ++i) {
		if(!lst[a[i]]){
			lst[a[i]] = i;
			build(root, i);
		} else {
			modify(root, lst[a[i]]);
			lst[a[i]] = i;
			build(root, i);
		}
		
		for(rint j = 0; j < vis[i].size(); ++j) {
			int tmp = vis[i][j];
			ans[q[tmp].id] = query(root, q[tmp].l, q[tmp].r);
		}
	}
	
	for(rint i = 1; i <= m; ++i) printf("%d\n", ans[i]);
	return 0;
}
#endif
