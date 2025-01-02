#include <bits/stdc++.h>
#define HJT ios_base::sync_with_stdio(false);cin.tie(0);
#define h(x) cerr << #x <<" "<<x << endl;
#define NO cout << "NO" << endl;
#define YES cout << "YES" << endl;
#define MOD 1000000007
#define MOD2 998244353
#define INF INT_MAX / 2
#define endl '\n'
#define re return 0;
#define er exit(0);
#define eps 1e-6
#define ce cout << endl;
#define bit(x) (1<<x)
#define MM 100005
#//tupel < int , int , int >
// __builtin_popcount(x): the number of ones in the number

using namespace std;

int  n , m;
vector < int > V[MM];
int head[MM];
int F(int id){
	return id == head[id] ? id : head[id] = F(head[id]); 
}
int main(){
	HJT
	#ifndef ONLINE_JUDGE 
	freopen("in.txt", "r", stdin);
#endif
	int T = 1;
	int  i , j , k , v, u ;
	cin >> T;
	while(T -- ){
		cin >> n >> m ;
		for(i = 1; i <= n ; i ++) head[i] = i;
		int cnt = 0 ;
		for(i = 0 ; i < m ; i ++){
			cin >> u >> v ;
			if(u == v) cnt -- ;
			else{
				if(F(u) == F(v)) cnt ++ ;
				head[F(u)] = F(v);	
			}
			
		}
		cout << m + cnt << endl;
	}
}

