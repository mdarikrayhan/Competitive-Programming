#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int,int>
int mod = 1e9+7;
struct matrix{
	int n , m ;
	int d[105][105];
	void make(int N , int M){
		n = N , m = M;
		memset(d , 0 , sizeof(d));
	} 
	void make1(int N , int M){
		n = N , m = M;
		memset(d , 0 , sizeof(d));
		for(int i = 0  ; i < n ;i ++){
			d[i][i]=1;
		}
	} 
	matrix plus(matrix a){
		matrix b;
		b.make(n , m);
		for(int i= 0 ; i < n ; i ++){
			for(int j = 0 ; j <m ; j ++){
				b.d[i][j] = d[i][j] + a.d[i][j];
				if(b.d[i][j] >= mod) b.d[i][j] -=mod;	
			}
		}
		return b;
	}
	matrix mul(matrix a){

		matrix b;
		b.make(n , a.m);
		for(int i = 0 ;i < n ; i ++){	
			for(int j = 0 ; j < a.m ; j ++){
				for(int l = 0 ; l < m ; l ++){
					b.d[i][l] += d[i][j]*a.d[j][l];
					if(b.d[i][l]>= mod) b.d[i][l]%=mod;
				}
			}
//			cout << endl;
		}
		return b;
	}
	matrix po(matrix a , int k){
		matrix b ;
		b.make1(n , n);
		while(k){
			if(k&1)	b=b.mul(a);
			k/=2;
			a=a.mul(a); 
		}
		
		return b;
	}
};
int m , n ; 
int dp[200];
int di(int vt){
	if(vt == 0)
		return 1;
	if(dp[vt]!=0)
		return dp[vt];
	dp[vt]+= di(vt-1);
	if(vt>=m) dp[vt] += di(vt-m);
	return dp[vt];
}
signed main(){
	
//    freopen("aha.inp", "r", stdin);
//    freopen("aha.out", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin >> n >> m ; 	
	matrix a, b;
	a.make(1 , m);
	b.make(m , m); 
	for(int i = 1 ; i< m ; i ++){
		a.d[0][i] = di(i);
	}

	for(int i = 0 ; i+1 < m ; i ++){
		b.d[i+1][i] = 1;
	}
	b.d[m-1][m-1] = b.d[0][m-1]=1;

	a = a.mul(b.po(b, n+1)) ;
	cout << a.d[0][0];
}

	 	 	  	  			   		 		  		 					