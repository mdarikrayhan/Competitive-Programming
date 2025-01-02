#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i, j, k) for(int i=j;i<=k;++i)
#define rep1(i, j, k) for(int i=k;i>=j;--i)

using namespace std;

const int N=1e3+5, M=35, mod=1e9+9;
int n, h;
ll f[M][M][M][2], g[M][M][M][2];
ll ans;
#define hd(i) min(i, h)
int _2[5];

int main(){
	
	scanf("%d%d", &n, &h);
	
	f[1][1][1][1]=4;
	rep(i, 1, n-1){
		rep(j, 1, h){
			rep(k, 1, h){
				rep(l, 1, h){
					rep(r, 0, 1){
						if(!f[j][k][l][r]) continue;
						
						(g[r ? 1 : h][hd(k+1)][hd(l+1)][j<h]+=f[j][k][l][r])%=mod;
						
						(g[hd(j+1)][r ? 1 : h][hd(l+1)][k<h]+=f[j][k][l][r])%=mod;
						
						(g[hd(j+1)][hd(k+1)][r ? 1 : h][l<h]+=f[j][k][l][r])%=mod;
						
						(g[hd(j+1)][hd(k+1)][hd(l+1)][r]+=f[j][k][l][r])%=mod;
					}
				}
			}
		}
		rep(j, 1, h){
			rep(k, 1, h){
				rep(l, 1, h){
					if(!l && i) continue;
					rep(r, 0, 1){
						f[j][k][l][r]=g[j][k][l][r];
						g[j][k][l][r]=0;
					}
				}
			}
		}
	}
	
	rep(j, 1, h){
		rep(k, 1, h){
			rep(l, 1, h){
				rep(r, 0, 1) if(r || j<h || k<h || l<h) (ans+=f[j][k][l][r])%=mod;
			}
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
/*

Chtholly Nota Seniorious

*/
	   	  	  		 	     	 	     	