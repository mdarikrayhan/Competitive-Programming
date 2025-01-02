#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
typedef long long i64;
const int maxn=2e6+10;
const i64 p=1000000000000000003ll;
int n,m,q;
int x[maxn],v[maxn],b[maxn];
i64 a[maxn];
struct node{
    int l,r;
    i64 add,mul,sum;
}tree[maxn];
set<int>st;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void write(i64 x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');

}
i64 ksm(i64 r,i64 k){
    i64 ans=1;
    while(k){
        if(k&1)ans=(ll)ans*r%p;
        r=(ll)r*r%p;
        k>>=1;
    }
    return ans;
}
void build(int id,int l,int r)
{
	
	tree[id].l=l,tree[id].r=r,tree[id].mul=1;
	if(tree[id].l==tree[id].r){
		tree[id].sum=a[l];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
void pushdown(int id)
{
	if(tree[id].mul!=1){
        tree[id*2].mul=(ll)tree[id*2].mul*tree[id].mul%p;
        tree[id*2+1].mul=(ll)tree[id*2+1].mul*tree[id].mul%p;
        tree[id*2].add=(ll)tree[id*2].add*tree[id].mul%p;
        tree[id*2+1].add=(ll)tree[id*2+1].add*tree[id].mul%p;
        tree[id*2].sum=(ll)tree[id*2].sum*tree[id].mul%p;
        tree[id*2+1].sum=(ll)tree[id*2+1].sum*tree[id].mul%p;
        tree[id].mul=1;
	}
	if(tree[id].add){
        tree[id*2].add=(tree[id*2].add+tree[id].add)%p;
        tree[id*2+1].add=(tree[id*2+1].add+tree[id].add)%p;
        tree[id*2].sum=(tree[id*2].sum+((ll)tree[id*2].r-tree[id*2].l+1)*tree[id].add)%p;
        tree[id*2+1].sum=(tree[id*2+1].sum+((ll)tree[id*2+1].r-tree[id*2+1].l+1)*tree[id].add)%p;
        tree[id].add=0;
	}
}
void update(int id,int l,int r,i64 c,int opt)
{
	if(tree[id].l==l&&tree[id].r==r){
		if(opt==1){
            tree[id].add=((ll)tree[id].add+c)%p;
            tree[id].sum=((ll)tree[id].sum+(r-l+1)*c)%p;
		}else{
            tree[id].mul=((ll)tree[id].mul*c)%p;
            tree[id].add=((ll)tree[id].add*c)%p;
            tree[id].sum=((ll)tree[id].sum*c)%p;
		}
		return ;
 	}
 	int mid=(tree[id].l+tree[id].r)/2;
 	if(tree[id].mul!=1||tree[id].add)pushdown(id);
 	if(r<=mid)update(id*2,l,r,c,opt);
 	else if(l>mid)update(id*2+1,l,r,c,opt);
 	else update(id*2,l,mid,c,opt),update(id*2+1,mid+1,r,c,opt);
 	tree[id].sum=(tree[id*2].sum+tree[id*2+1].sum)%p;
}
i64 query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)return tree[id].sum;
	if(tree[id].mul!=1||tree[id].add)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r);
	else if(l>mid)return query(id*2+1,l,r);
	else return (query(id*2,l,mid)+query(id*2+1,mid+1,r))%p;
}
void work(int pos,i64 val)
{
    a[pos]=val;
    auto nxt=st.lower_bound(pos);
    auto pre=prev(nxt);
    st.insert(pos);
    update(1,(*pre)+1,pos,-a[*pre]*((*nxt)-pos),1);
    update(1,pos+1,*nxt,(ll)a[pos]*ksm(a[*pre],p-2)%p,2);
}
int main(){
    n=read(),m=read(),q=read();
    for(int i=1;i<=m;i++){
        x[i]=read();
        st.insert(x[i]);
    }
    for(int i=1;i<=m;i++)
        v[i]=read();
    for(int i=1;i<=m;i++)
        a[x[i]]=v[i];
    for(int i=1;i<=n;i++)
        if(a[i]!=0)
            b[i]=1;
    for(int i=1;i<=n;i++)
        if(a[i]==0)
            a[i]=a[i-1];
    for(int i=n;i>=1;i--)
        if(b[i]==0)
            b[i]=b[i+1]+1;
    for(int i=1;i<=n;i++)
        a[i]*=(b[i]-1);
    build(1,1,n);
    for(int i=1;i<=n;i++)
        a[i]=0;
    for(int i=1;i<=m;i++)
        a[x[i]]=v[i];
    for(int i=1;i<=q;i++){
        int op;
        op=read();
        if(op==1){
            int pos;
            i64 val;
            pos=read(),val=read();
            work(pos,val);
        }
        if(op==2){
            int l,r;
            l=read(),r=read();
            i64 ans=query(1,l,r);
            write(ans),putchar('\n');
        }
    }
    return 0;
}