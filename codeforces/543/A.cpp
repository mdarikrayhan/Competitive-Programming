/*

Build | ..... | Peace

*/

#include<bits/stdc++.h>


//----------------------- MACRO START ---------------------------

#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define fore(i, a, b) for(int i = (a); i < (b); i++)
#define fori(i, a, b) for(int i = (a); i <= (b); i++)

#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vector<vi>>
#define vpii vector<pair<int,int>>
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mpii map<int,int>

#define direc_4 vector<pair<int,int>> {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}
#define direc_8 vector<pair<int,int>> {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}

//----------------------- MACRO END ---------------------------

using namespace std;

int n,m,b,md;
vi a;
int dp[2][510][510];


// int f(int lvl, int currLOC, int currBugs){
// 	if(lvl>n)return 0;
// 	if(currLOC>m)return 0;
// 	if(currBugs>b)return 0;
// 	if(lvl==n){
// 		if(currLOC==m) return 1;
// 		else return 0;
// 	}

// 	int ans=0;

// 	// do not write any loc
// 	ans+=f(lvl+1, currLOC, currBugs);

// 	// here one sould also have writed loop to call
// 	// the function recursively
// 	// recursively write codes by same programmer
// 	ans+=f(lvl, currLOC+1, currBugs+a[lvl]);

// 	return ans;
// }

void solve(){
	cin>>n>>m>>b>>md;
	
	a=vi(n);
	for(int &i:a)cin>>i;

	// cout<<"hw"<<endl;

	// cout<<f(0,0,0)<<endl;

	// memset(dp, 0, sizeof(dp));

	dp[0][0][0]=1;

	for(int i=1;i<=n;i++){
		for(int loc=0;loc<=m;loc++){
			for(int bug=0;bug<=b;bug++){
				dp[(i%2)][loc][bug] = dp[((i-1)%2)][loc][bug];

               if(loc && bug>=a[i-1]) {
                   dp[(i%2)][loc][bug] = (dp[(i%2)][loc][bug] + dp[(i%2)][loc-1][bug-a[i-1]])%md;
               }
			}
		}
	}

   int ans=0;
   for (int i = 0; i <= b; ++i) {
       ans = (ans + dp[(n%2)][m][i]) % md;
   }
   cout<<ans<<endl;
}

signed main(){
	fio;

#ifndef ONLINE_JUDGE
    freopen("D://CP//Codes//input.txt", "r", stdin);
    freopen("D://CP//Codes//output.txt", "w", stdout);
#endif

	// int t; cin>>t;
	int t=1;

	while(t--) solve();

	return 0;

}