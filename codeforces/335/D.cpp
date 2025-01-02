// LUOGU_RID: 159820454
#include<bits/stdc++.h>
#define ffor(i,a,b) for(int i=(a);i<=(b);i++)
#define roff(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int MAXN=3000+10,MAXM=1e5+10;
int n,m=3000,tl[MAXN][MAXN],tr[MAXN][MAXN],tu[MAXN][MAXN],td[MAXN][MAXN],cov[MAXN][MAXN];
int xl[MAXM],xr[MAXM],yl[MAXM],yr[MAXM];
int a[MAXN],recl[MAXN][MAXN],recr[MAXN][MAXN];
void output(int x0,int y0,int x1,int y1) {
	cout<<"YES ";
	vector<int> ans;
	ffor(i,1,n) if(x0<=xl[i]&&xr[i]<=x1&&y0<=yl[i]&&yr[i]<=y1) ans.push_back(i);
	cout<<ans.size()<<'\n';
	for(auto id:ans) cout<<id<<' ';
	exit(0);	
}
void solve(int x0,int y0,int x1,int y1) {
	stack<int> st;
	int covx=x0,covy=y0;
	int len=x1-x0+1;
	ffor(i,1,len) {
		while(cov[x0+i-1][y0+i-1]-cov[covx][y0+i-1]-cov[x0+i-1][covy]+cov[covx][covy]) covx++,covy++;
		int l=max({covx-x0+1,i-tl[x0+i-1][y0+i-1],i-td[x0+i-1][y0+i-1]});
		while(!st.empty()&&a[st.top()]<i) st.pop();
		if(!st.empty()&&st.top()>=l) output(x0+st.top()-1,y0+st.top()-1,x0+i-1,y0+i-1);
		a[i]=min(i+tr[x0+i-1][y0+i-1],i+tu[x0+i-1][y0+i-1]);
		while(!st.empty()&&a[i]>=a[st.top()]) st.pop();
		st.push(i);
	}
	return ;
}
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	ffor(i,1,n) {
		cin>>xl[i]>>yl[i]>>xr[i]>>yr[i];
		recl[xl[i]][yl[i]]=i;
		recr[xr[i]][yr[i]]=i;
	}
	roff(i,m,0) roff(j,m,0) if(recl[i][j]) {
		int id=recl[i][j];
		tr[i][j]=tr[xr[id]][j]+xr[id]-xl[id];
		tu[i][j]=tu[i][yr[id]]+yr[id]-yl[id];
	}
	ffor(i,0,m) ffor(j,0,m) if(recr[i][j]) {
		int id=recr[i][j];
		tl[i][j]=tl[xl[id]][j]+xr[id]-xl[id];
		td[i][j]=td[i][yl[id]]+yr[id]-yl[id];	
	}
	ffor(i,1,n) {
		int X0=xl[i]+1,X1=xr[i],Y0=yl[i]+1,Y1=yr[i];
		cov[X0][Y0]++,cov[X0][Y1+1]--,cov[X1+1][Y0]--,cov[X1+1][Y1+1]++;
	}
	ffor(i,1,m) ffor(j,1,m) cov[i][j]=cov[i-1][j]+cov[i][j-1]-cov[i-1][j-1]+cov[i][j];
	ffor(i,1,m) ffor(j,1,m) cov[i][j]=cov[i-1][j]+cov[i][j-1]-cov[i-1][j-1]+(cov[i][j]^1);
	ffor(i,0,m) solve(0,i,m-i,m);
	ffor(i,1,m) solve(i,0,m,m-i);
	cout<<"NO";
	return 0;
}
