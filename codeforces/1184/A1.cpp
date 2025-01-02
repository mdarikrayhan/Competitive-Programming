#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
#include<iostream>
#include<vector>
#include<cassert>
#include <algorithm>
#include <cassert>
#include <numeric>
#include <string>
#include <vector>
#define pb push_back
#define all(a) a.begin(), a.end()
#define rep(i,a,b) for (long long i=(long long)(a);i<(long long)(b);i++)
//-----------------------------------------------------------------------------------------------------
//void solve(){
  // SUBSTRING FUNTION
//int isSubstring(string s1, string s2)
//{
  // using find method to check if s1 is
  // a substring of s2
 // if (s2.find(s1) != string::npos)
  //  return 1;
  //return -1;
//}
 
                         //BINARY SEARCH
//ll binary_search(ll b[], ll key, ll n)
//{
   // int low = 0, high = n - 1;
   // while (low <= high)
   // {
      //  int mid = (low + high) / 2;
        //if (b[mid] == key)
        //{
          //  return mid;
      //  }
        //else if (key < b[mid])
        //{
          //  high = mid - 1;
        //}
     //   else
       // {
         //   low = mid + 1;
        //}
    //}
    //return -1;
//}   // input taking for the code 
//SALESMAN PROBLEM--------------------------------------------------------------

// there are four nodes in example graph (graph is 1-based)

// give appropriate maximum to avoid overflow


// dist[i][j] represents shortest distance to go from i to j
// this matrix can be calculated for any given graph using
// all-pair shortest path algorithms


// memoization for top down recursion
//int memo[n + 1][1 << (n + 1)];

//int fun(int i, int mask)
//{
	// base case
	// if only ith bit and 1st bit is set in our mask,
	// it implies we have visited all other nodes already
	//if (mask == ((1 << i) | 3))
		//return dist[1][i];
	// memoization
	//if (memo[i][mask] != 0)
		//return memo[i][mask];

	//int res = MAX; // result of this sub-problem

	// we have to travel all nodes j in mask and end the
	// path at ith node so for every node j in mask,
	// recursively calculate cost of travelling all nodes in
	// mask except i and then travel back from node j to
	// node i taking the shortest path take the minimum of
	// all possible j nodes

	
// Driver program to test above logic
//int main()
//{
	//int ans = MAX;
	//for (int i = 1; i <= n; i++)
		// try to go from node 1 visiting all nodes in
		// between to i then return from i taking the
		// shortest route to 1
		//ans = std::min(ans, fun(i, (1 << (n + 1)) - 1)
			//					+ dist[i][1]);

	//printf("The cost of most efficient tour = %d", ans);

	//return 0;
//}
//}
//---------------------------------------------------------------------------------------------------------------------------
//vector<vector<string>>v;
//ll po(ll ba,ll exp){
 // ll re=1;
  //rep(i,0,exp){
    //re*=ba;
  //}-
  //return re;
//}
int ab[1000010];
const int mod=1e9+7;
long long cnt[1000010];
//'',"",4

  //int n,m;
//char a[101][101];

signed main()
{
 ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
ll r;
  cin >> r;
  for (ll x = 1; x * x <= r; x++) {
    ll need = r - x * x - x - 1;
    if (need > 0 && need % 2 == 0) {
      cout << x << ' ' << need / 2 << '\n';
      return 0;
    }
  }
  cout << "NO\n";   
   }

