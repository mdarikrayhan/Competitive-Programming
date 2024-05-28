#include<iostream>
#include<cstdio>
#define ls(rt) tr[rt].ls
#define rs(rt) tr[rt].rs
using namespace std;
int tot;
struct node{
	int sum,ls,rs;
}tr[30000005];
int rt[1000005];
int n;
void push(int rt){tr[rt].sum=tr[ls(rt)].sum+tr[rs(rt)].sum;}
void update(int &rt,int l,int r,int x,int k){
	if(!rt)rt=++tot,tr[rt].sum=0,ls(rt)=rs(rt)=0;
	if(l==r)return tr[rt].sum+=k,void();
	int mid=l+r>>1;
	if(x<=mid)update(ls(rt),l,mid,x,k);
	else update(rs(rt),mid+1,r,x,k);
	push(rt);
}int que(int rt[],int l,int r,int x,int y){
	if(x<=l&&r<=y){
		int ans=0;
		for(int i=1; i<=rt[0]; i++)ans+=tr[rt[i]].sum;
		return ans;
	}int mid=l+r>>1;
	int ans=0;
	if(x<=mid){
		int rtt[100];
		rtt[0]=rt[0];
		for(int i=1; i<=rt[0] ;i++)rtt[i]=ls(rt[i]);
		ans+=que(rtt,l,mid,x,y);
	}if(y>mid){
		int rtt[100];
		rtt[0]=rt[0];
		for(int i=1; i<=rt[0] ;i++)rtt[i]=rs(rt[i]);
		ans+=que(rtt,mid+1,r,x,y);
	}return ans;
}int lowbit(int x){return x&-x;}
void upd(int x,int k,int t){for(int i=x; i<=n; i+=lowbit(i))update(rt[i],1,n,k,t);}
int query(int x,int y,int l,int r){
	int rtt[100];
	
	int ans=0;//cout<<114<<endl;
	rtt[0]=0;
	for(int i=x-1; i; i-=lowbit(i)){
//		cout<<i<<endl;
		rtt[++rtt[0]]=rt[i];
//		cout<<114<<endl;
	}
	ans=que(rtt,1,n,l,r);rtt[0]=0;
	for(int i=y; i; i-=lowbit(i))rtt[++rtt[0]]=rt[i];
	ans=que(rtt,1,n,l,r)-ans;
	return ans;
}int a[200005];
int main(){
//	int n,m;
	int m;
	scanf("%d%d",&n,&m);
	long long ans=0;
	for(int i=1; i<=n ;i++)upd(i,i,1),a[i]=i;
//	cout<<query(2,3,1,4)<<endl; 
//	cout<<query(1,1,1,n)<<endl;
//	cout<<query(5,5,4,5)<<endl;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y){
			printf("%lld\n",ans);
			continue;
		}
		ans+=query(x+1,y,a[x],n);
		ans-=query(x+1,y,1,a[x]);
		if(y!=x+1){
			ans+=query(x+1,y-1,1,a[y]);
			ans-=query(x+1,y-1,a[y],n);
		}
		
		printf("%lld\n",ans);
		upd(x,a[x],-1);
		upd(y,a[x],1);
		upd(x,a[y],1);
		upd(y,a[y],-1);
		swap(a[x],a[y]);
	}
	return 0;
}
 	 		  	  	 						 	 		   	 		