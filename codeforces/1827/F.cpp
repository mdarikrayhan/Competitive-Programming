// LUOGU_RID: 160426432
#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
constexpr int n_MAX=200000+5;
inline long long mul(const int x,const int y){return ((long long)x*y);}
inline long long len(const int x){return (mul(x,x+1)>>1);}
int n,k,a[n_MAX],prec[n_MAX],succ[n_MAX]; array<int,2> mem[n_MAX];
long long R[n_MAX],G[n_MAX],W[n_MAX],B[n_MAX],Y[n_MAX],ans[n_MAX];
long long cur_B,cur_Y;
int l[n_MAX],r[n_MAX],tag[n_MAX],cur[n_MAX];
vector<array<int,3>> S[n_MAX],T[n_MAX],Q[n_MAX];
void init(){For(i,0,n+1) S[i]=T[i]=Q[i]={{0,0,0}};}
inline int gap_succ(const int i){return (succ[i]-i-1);}
inline int gap_prec(const int i){return (i-prec[i]-1);}
void Insert_S(const int i,const int w)
{
	const int bleem=(3+((l[k-1]==i)&&((tag[k-1]-gap_prec(r[k-1]))==w)));
	cur_B-=mul(S[i].back()[2]>>1,gap_succ(i));
	array<int,3> &A=S[i].back();
	if(w==A[0]) A[1]+=2,A[2]=max(A[2],A[1]);
	else S[i].push_back({w,bleem,max(A[2],bleem)});
	cur_B+=mul(S[i].back()[2]>>1,gap_succ(i));
}
void Delete_S(const int i)
{
	cur_B-=mul(S[i].back()[2]>>1,gap_succ(i));
	array<int,3> &A=S[i].back();
	if(A[1]<=4) S[i].pop_back();
	else A[1]-=2,A[2]=max(S[i][S[i].size()-2][2],A[1]);
	cur_B+=mul(S[i].back()[2]>>1,gap_succ(i));
}
void Insert_T(const int i,const int w)
{
	const int bleem=(3+((r[k-1]==i)&&((tag[k-1]-gap_succ(l[k-1]))==w)));
	cur_Y-=mul(T[i].back()[2]>>1,gap_prec(i));
	array<int,3> &A=T[i].back();
	if(w==A[0]) A[1]+=2,A[2]=max(A[2],A[1]);
	else T[i].push_back({w,bleem,max(A[2],bleem)});
	cur_Y+=mul(T[i].back()[2]>>1,gap_prec(i));
}
void Delete_T(const int i)
{
	cur_Y-=mul(T[i].back()[2]>>1,gap_prec(i));
	array<int,3> &A=T[i].back();
	if(A[1]<=4) T[i].pop_back();
	else A[1]-=2,A[2]=max(T[i][T[i].size()-2][2],A[1]);
	cur_Y+=mul(T[i].back()[2]>>1,gap_prec(i));
}
void Insert_Q(const int i)
{
	const int w=(tag[k-1]-gap_succ(l[k-1])-gap_prec(r[k-1]));
	if(i==(-1)){++cur[w];return;}
	array<int,3> &A=Q[i].back();
	if((w==A[0])&&A[1]) ++A[1],++cur[w];
	else cur[A[0]]-=A[1],Q[i].push_back({w,1,0}),++cur[w];
}
void Delete_Q(const int i)
{
	const int w=(tag[k-1]-gap_succ(l[k-1])-gap_prec(r[k-1]));
	if(i==(-1)){--cur[w];return;}
	array<int,3> &A=Q[i].back(),&B=Q[i][Q[i].size()-2];
	if(A[1]>=2) --A[1],--cur[w];
	else B[0]+=A[2],B[2]+=A[2],cur[B[0]]+=B[1],Q[i].pop_back(),--cur[w];
}
void push_stack()
{
	Insert_S(l[k],tag[k]);
	Insert_T(r[k],tag[k]);
	if(((l[k-1]+1)<=l[k])&&(r[k]<=(r[k-1]-1))) Insert_Q(-1);
	else if(l[k-1]==l[k]) Insert_Q(l[k-1]);
	else if(r[k-1]==r[k]) Insert_Q(r[k-1]);
}
void pop_stack()
{
	Delete_S(l[k]);
	Delete_T(r[k]);
	if(((l[k-1]+1)<=l[k])&&(r[k]<=(r[k-1]-1))) Delete_Q(-1);
	else if(l[k-1]==l[k]) Delete_Q(l[k-1]);
	else if(r[k-1]==r[k]) Delete_Q(r[k-1]);
}
void Truncate_L(const int x,const int y,const int z)
{
	cur_B-=mul(S[x].back()[2]>>1,z-y);
	if(l[k-1]==x)
	{
		array<int,3> &A=Q[x].back();
		cur[A[0]]-=A[1],A[0]+=(z-y),A[2]+=(z-y),cur[A[0]]+=A[1];
	}
}
void Truncate_R(const int x,const int y,const int z)
{
	cur_Y-=mul(T[z].back()[2]>>1,y-x);
	if(r[k-1]==z)
	{
		array<int,3> &A=Q[z].back();
		cur[A[0]]-=A[1],A[0]+=(y-x),A[2]+=(y-x),cur[A[0]]+=A[1];
	}
}
void clear(int a[]){memset(a,0,(n+3)<<2);}
void clear(long long a[]){memset(a,0,(n+3)<<3);}
void clear(array<int,2> a[]){memset(a,0,(n+3)<<3);}
void clear_all()
{
	clear(a),clear(prec),clear(succ),clear(mem);
	clear(R),clear(G),clear(W),clear(B),clear(Y),clear(ans);
	clear(l),clear(r),clear(tag),clear(cur);
	For(i,0,n+2)
	{
		S[i].clear(),S[i].shrink_to_fit();
		T[i].clear(),T[i].shrink_to_fit();
		Q[i].clear(),Q[i].shrink_to_fit();
	}
	n=k=cur_B=cur_Y=0;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T; cin>>T;
	while(T--)
	{
		cin>>n;
		For(i,1,n) cin>>a[i];
		For(i,1,n) prec[i]=(i-1),succ[i]=(i+1);
		succ[0]=1,prec[n+1]=n;
		For_down(i,n,1)
		{
			const int x=prec[a[i]],y=a[i],z=succ[a[i]];
			mem[i]={x,z},succ[x]=z,prec[z]=x,prec[y]=succ[y]=0;
		}
		l[0]=(-1),r[0]=n,G[0]=len(n),init();
		For(i,1,n)
		{
			cur_B=B[i-1],cur_Y=Y[i-1];
			const int x=mem[i][0],y=a[i],z=mem[i][1];
			while(!((l[k]<=y)&&(y<=r[k]))) pop_stack(),--k;
			++k,l[k]=x,r[k]=z,tag[k]=(z-x+i),push_stack();
			succ[x]=y,prec[y]=x,succ[y]=z,prec[z]=y;
			Truncate_L(x,y,z); // x ----> y ----> z
			Truncate_R(x,y,z); // x <---- y <---- z
			R[i]=(R[i-1]+(cur[i+2]+1)),W[i]=(k-(cur[i+2]+1));
			G[i]=(G[i-1]-(len(z-x-1)-len(y-x-1)-len(z-y-1)));
			B[i]=cur_B,Y[i]=cur_Y;
		}
		For(i,0,n) ans[i]=(R[i]+G[i]+W[i]+B[i]+Y[i]);
		For(i,0,n-1) cout<<ans[i]<<' ';
		cout<<ans[n]<<'\n',clear_all();
	}
	cerr<<clock()<<" ms\n"; return 0;
}