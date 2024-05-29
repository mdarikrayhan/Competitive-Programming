// LUOGU_RID: 160672295
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
struct pt{int x,y;}a[maxn],b[maxn];
pt operator-(pt a,pt b){return {a.x-b.x,a.y-b.y};}
int operator^(pt a,pt b){return a.x*b.y-a.y*b.x;}
int stk[maxn],tp=0;
int n;
#define db double 
db A[maxn],B[maxn],ans[maxn];
db calc(pt a,pt b,db c){
	return a.y+(b.y-a.y+0.0)/(b.x-a.x)*(c-a.x);
}
signed main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)a[i].x=i,cin>>a[i].y;
	for(int i=0;i<n;i++)b[i].x=i,cin>>b[i].y;
	int mid=n/2;db M=(n-1.0)/2;
	for(int i=mid;i<n;i++){
		while(tp>1&&((a[stk[tp]]-a[stk[tp-1]])^(a[i]-a[stk[tp-1]]))>=0)--tp;
		stk[++tp]=i;
	}
	// cerr<<"Right Convex Hull:"<<endl;
	// for(int i=1;i<=tp;i++)cerr<<stk[i]<<" ";
	// cerr<<endl;
	for(int i=0;i<mid;i++){
		int L=1,R=tp-1;
		A[i]=calc(a[i],a[stk[1]],M);
		while(L<=R){
			int mi=L+R>>1;
			A[i]=max(A[i],calc(a[i],a[stk[mi]],M));
			A[i]=max(A[i],calc(a[i],a[stk[mi+1]],M));
			if(((a[stk[mi+1]]-a[i])^(a[stk[mi]]-a[i]))>=0)R=mi-1;
			else L=mi+1;
		}
		// cerr<<"A["<<i<<"]="<<A[i]<<endl;
	}
	for(int i=0;i<mid;i++){
		int L=1,R=tp-1;
		B[i]=calc(b[i],a[stk[1]],M);
		while(L<=R){
			int mi=L+R>>1;
			B[i]=max(B[i],calc(b[i],a[stk[mi]],M));
			B[i]=max(B[i],calc(b[i],a[stk[mi+1]],M));
			if(((a[stk[mi+1]]-b[i])^(a[stk[mi]]-b[i]))>=0)R=mi-1;
			else L=mi+1;
		}
		// cerr<<"B["<<i<<"]="<<B[i]<<endl;
	}
	for(int i=1;i<mid;i++)B[i]=max(B[i],B[i-1]);
	for(int i=mid-2;i>=0;i--)A[i]=max(A[i],A[i+1]);
	A[mid]=-1e9;
	for(int i=0;i<mid;i++){
		db res=max(B[i],A[i+1]);
		ans[i]=res*2;
	}
	tp=0;
	for(int i=0;i<mid;i++){
		while(tp>1&&((b[stk[tp]]-b[stk[tp-1]])^(b[i]-b[stk[tp-1]]))>=0)--tp;
		stk[++tp]=i;
	}
	for(int i=mid;i<n;i++){
		int L=1,R=tp-1;
		A[i]=calc(b[stk[1]],a[i],M);
		while(L<=R){
			int mi=L+R>>1;
			A[i]=max(A[i],calc(b[stk[mi]],a[i],M));
			A[i]=max(A[i],calc(b[stk[mi+1]],a[i],M));
			if(((b[stk[mi+1]]-a[i])^(b[stk[mi]]-a[i]))<=0)R=mi-1;
			else L=mi+1;
		}
	}
	for(int i=mid;i<n;i++){
		int L=1,R=tp-1;
		B[i]=calc(b[stk[1]],b[i],M);
		while(L<=R){
			int mi=L+R>>1;
			B[i]=max(B[i],calc(b[stk[mi]],b[i],M));
			B[i]=max(B[i],calc(b[stk[mi+1]],b[i],M));
			if(((b[stk[mi+1]]-b[i])^(b[stk[mi]]-b[i]))<=0)R=mi-1;
			else L=mi+1;
		}
	}
	for(int i=mid+1;i<n;i++)B[i]=max(B[i],B[i-1]);
	for(int i=n-2;i>=mid;i--)A[i]=max(A[i],A[i+1]);
	A[n]=-1e9;
	for(int i=mid;i<n;i++){
		db res=max(B[i],A[i+1]);
		ans[i]=res*2;
	}
	for(int i=0;i<n;i++)printf("%.10lf ",ans[i]);
	printf("\n");
	return 0;
}
