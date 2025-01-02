// LUOGU_RID: 158934498
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i, j, k) for(int i=j;i<=k;++i)
#define rep1(i, j, k) for(int i=k;i>=j;--i)

using namespace std;

const int N=25, M=47000, K=45;
int n, m;
int a[N], b[N];

int c[N];
int pw[N], p;

int st[N][N], cnt[N];
int to[N][M];

int pre[M];
bool f[N][M][K];

int ans[N];

bool opt[N][N];

void dfs(int id, int x, int i){
	ans[id]=i;
	if(id<=1) return;
	rep(j, 1, cnt[b[id-1]]){
		int y=st[b[id]][i]&(~st[b[id-1]][j]), z=0, t=x, nw;
		bool flag=false;
		while(y){
			nw=y&-y;
			if(!(t/pre[nw]%pre[nw<<1])){
				flag=true;
				break;
			}
			t-=pre[nw];
			y-=nw;
			++z;
		}
		if(flag) continue;
		if(f[id-1][t][j]) return dfs(id-1, t, j);
	}
}

void dgs(int id, int x, int i){
	ans[id]=i;
	if(id>=m) return;
	rep(j, 1, cnt[b[id+1]]){
		int y=st[b[id]][i]&(~st[b[id+1]][j]), z=0, t=x, nw;
		bool flag=false;
		while(y){
			nw=y&-y;
			if(!(t/pre[nw]%pre[nw<<1])){
				flag=true;
				break;
			}
			t-=pre[nw];
			y-=nw;
			++z;
		}
		if(flag) continue;
		if(f[id+1][t][j]) return dgs(id+1, t, j);
	}
}

int mid;

void solve(int x, int i, int y, int j){
	dfs(mid, x, i);
	dgs(mid+1, y, j);
}

void output(){
	rep(i, 1, m){
		int j=st[b[i]][ans[i]];
		rep(k, 1, n){
			opt[k][i]=j&1, j>>=1;
		}
	}
	
	rep(i, 1, n){
		rep(j, 1, m){
			putchar(opt[i][j] ? '*' : '.');
		}
		puts("");
	}
	puts("");
}

int main(){
	
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%d", a+i);
	rep(i, 1, m) scanf("%d", b+i);
	
	pre[1]=pw[0]=1;
	int x=1;
	rep(i, 1, n){
		c[i]=min(a[i], (a[i]>>1)+1);
		
//		cout<<c[i]<<endl;
		pre[x<<=1]=pw[i]=pw[i-1]*(c[i]+1);
	}
	pre[x<<=1]=pw[n+1]=pw[n]*(c[n]+1);
	
	p=1;
	rep1(i, 1, n) p=p*(c[i]+1)+c[i];
//	cout<<p<<" "<<p%pre[2]/pre[1]<<" "<<p%pre[4]/pre[2]<<" "<<p%pre[8]/pre[4]<<endl;
	
	int num=(1<<n)-1;
	rep(i, 0, num){
		int x=0, lst=0, y=i;
		rep(j, 1, n){
			if((y&1) && !lst) ++x;
			lst=y&1, y>>=1;
		}
		st[x][++cnt[x]]=i;
		to[x][i]=cnt[x];
	}
	
//	cout<<"???"<<" "<<p<<" "<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
	
	mid=m>>1;
	f[0][0][1]=true;
	rep(i, 1, mid){
		rep(x, 0, p){
			rep(j, 1, cnt[b[i]]){
				int k=st[b[i]][j];
				rep(l, 1, cnt[b[i-1]]){
					int r=st[b[i-1]][l];
					int y=k&(~r), z=0, t=x, nw;
					bool flag=false;
//					cout<<i<<" "<<x<<" "<<j<<" "<<l<<":"<<endl;
					while(y){
						nw=y&-y;
						if(!(t%pre[nw<<1]/pre[nw])){
							flag=true;
							break;
						}
						t-=pre[nw];
						y-=nw;
						++z;
//						cout<<"???"<<endl;
					}
					if(flag) break;
					if(f[i-1][t][l]){
						f[i][x][j]=true;
						break;
					}
				}
			}
		}
	}
	
//	cout<<"???"<<endl;
	
	f[m+1][0][1]=true;
	rep1(i, mid+1, m){
		rep(x, 0, p){
			rep(j, 1, cnt[b[i]]){
				int k=st[b[i]][j];
				rep(l, 1, cnt[b[i+1]]){
					int r=st[b[i+1]][l];
					int y=k&(~r), z=0, t=x, nw;
					bool flag=false;
					while(y){
						nw=y&-y;
						if(!(t%pre[nw<<1]/pre[nw])){
							flag=true;
							break;
						}
						t-=pre[nw];
						y-=nw;
						++z;
					}
					if(flag) break;
					if(f[i+1][t][l]){
						f[i][x][j]=true;
						break;
					}
				}
//				if(f[i][x][j]) cout<<i<<" "<<x<<" "<<j<<endl;
			}
		}
	}
	
//	cout<<"???"<<endl;
	
	int ch[10], h[10];
	rep(x, 0, p){
		int t=x;
//		cout<<x<<":";
		rep(i, 1, n){
			ch[i]=t%(c[i]+1);
			t/=c[i]+1;
//			cout<<ch[i]<<" ";
		}
//		cout<<endl;
		rep(i, 1, cnt[b[mid]]){
			if(!f[mid][x][i]) continue;
			rep(j, 1, cnt[b[mid+1]]){
				int y=st[b[mid]][i]&st[b[mid+1]][j];
				bool flag=false;
				rep(i, 1, n){
					h[i]=a[i]-ch[i]+(y&1);
					if(h[i]>c[i] || a[i]-ch[i]<0){
						flag=true;
						break;
					}
					y>>=1;
				}
				if(flag) continue;
				int q=0;
				rep1(i, 1, n) q=q*(c[i]+1)+h[i];
//				cout<<x<<" "<<i<<" "<<q<<" "<<j<<":"<<q;
//				rep(i, 1, n) cout<<" "<<h[i];
//				cout<<endl;
				if(f[mid+1][q][j]){
					solve(x, i, q, j);
					output();
					return 0;
				}
			}
		}
	}
	
	return 0;
}
/*

3 3
1 1 2
1 1 1

*/
