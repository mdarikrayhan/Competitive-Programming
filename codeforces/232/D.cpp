// LUOGU_RID: 158026762
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int len,n,q,s[N],p[N],a[N],m,tax[N],sa[N],tp[N],rnk[N],st[20][N],lg[N],rt[N],tot;
inline void sort(){
	for(int i = 0;i<=m;i++)tax[i]=0;
	for(int i = 1;i<=n;i++)tax[rnk[i]]++;
	for(int i = 1;i<=m;i++)tax[i]+=tax[i-1];
	for(int i = n;i>=1;i--)sa[tax[rnk[tp[i]]]--]=tp[i];
}
inline int query(int x,int y){
	if(x>y)return N*2;
	int k=lg[y-x+1];
	return min(st[k][x],st[k][y-(1<<k)+1]);
}
struct tree{
	int lc,rc,k;
}t[N*30];
inline void insert(int&p,int q,int l,int r,int pos){
	p=++tot;t[p]=t[q];t[p].k++;
	if(l==r)return ;
	int mid=l+r>>1;
	if(pos<=mid)insert(t[p].lc,t[q].lc,l,mid,pos);
	else insert(t[p].rc,t[q].rc,mid+1,r,pos);
}
inline int query(int p,int q,int l,int r,int ql,int qr){
	if(!p||ql>qr)return 0;
	if(ql<=l&&r<=qr)return t[p].k-t[q].k;
	int mid=l+r>>1,ans=0;
	if(ql<=mid)ans=query(t[p].lc,t[q].lc,l,mid,ql,qr);
	if(qr>mid)ans+=query(t[p].rc,t[q].rc,mid+1,r,ql,qr);
	return ans;
}
int main(){
	scanf("%d",&len);
	for(int i = 1;i<=len;i++)scanf("%d",&s[i]);
	for(int i = 1;i<len;i++)a[++n]=s[i+1]-s[i],p[n]=a[n];
	for(int i = 1;i<len;i++)++n,a[n]=-a[n-len+1],p[n]=a[n];
	sort(p+1,p+n+1);m=unique(p+1,p+n+1)-p-1;
	for(int i = 1;i<=n;i++)rnk[i]=a[i]=lower_bound(p+1,p+m+1,a[i])-p,tp[i]=i;
	m=n;sort();
	for(int w = 1,p=0;p<n;m=p,w<<=1){
		p=w;
		for(int i = 1;i<=w;i++)tp[i]=n-i+1;
		for(int i = 1;i<=n;i++)if(sa[i]>w)tp[++p]=sa[i]-w;
		sort();
		swap(tp,rnk);
		p=rnk[sa[1]]=1;
		for(int i = 2;i<=n;i++)rnk[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])?p:++p;
	}
	lg[0]=-1;
	for(int i = 1,k=0,j;i<=n;i++){
		lg[i]=lg[i>>1]+1;
		if(k)k--;
		j=sa[rnk[i]-1];
		while(a[i+k]==a[j+k])++k;
		st[0][rnk[i]]=k;
	}
	for(int i = 1,k=0,j;i<=n;i++){
		if(sa[i]>len-1)insert(rt[i],rt[i-1],1,len,sa[i]-len+1);
		else rt[i]=rt[i-1];
	}
	for(int j = 1;j<=lg[n];j++)for(int i = 1;i+(1<<j)-1<=n;i++)st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
	scanf("%d",&q);
	int d,u,L,R,l,r,mid;
	while(q--){
		scanf("%d%d",&d,&u);
		if(d==u){
			printf("%d\n",len-1);
			continue;
		}
		l=1,r=rnk[d];
		while(l<=r){
			mid=l+r>>1;
			if(query(mid+1,rnk[d])>=u-d)r=mid-1;
			else l=mid+1;
		}
		L=r+1;
		l=rnk[d],r=n;
		while(l<=r){
			mid=l+r>>1;
			if(query(rnk[d]+1,mid)>=u-d)l=mid+1;
			else r=mid-1;
		}
		R=l-1;
		printf("%d\n",query(rt[R],rt[L-1],1,len,1,d-(u-d+1))+query(rt[R],rt[L-1],1,len,u+1,len-(u-d)));
	}
	return 0;
}