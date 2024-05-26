#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define rep(i, j, k) for(int i=j;i<=k;++i)
#define rep1(i, j, k) for(int i=k;i>=j;--i)

using namespace std;

const int N=5e2+5;
int t;
int n, m;
char s[N][N];


int main(){
	
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%s", s[i]+1);
		
		int beg=(n%3==0 ? 2 : 1);
		for(int i=beg;i<=n;i+=3){
			rep(j, 1, m) s[i][j]='X';
		}
		
		for(int i=beg+1;i<n;i+=3){
			bool flag=false;
			rep(j, 1, m){
				if(s[i][j]=='X' || s[i+1][j]=='X'){
					s[i][j]=s[i+1][j]='X';
					flag=true;
					break;
				}
			}
			if(!flag) s[i][1]=s[i+1][1]='X';
		}
		
		rep(i, 1, n){
			rep(j, 1, m){
				putchar(s[i][j]);
			}
			puts("");
		}
	}
	
	
	
	return 0;
}

