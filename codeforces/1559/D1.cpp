#include<bits/stdc++.h>
#define int long long
#define double long double
#define inf 1e18
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}
using namespace std;

int dx4[] = {0,0,-1,1};
int dy4[] = {-1,1,0,0};
int dx8[] = {0,0,-1,1,-1,1,-1,1};
int dy8[] = {-1,1,0,0,-1,1,1,-1};
int knight_x[] = {2,2,-2,-2,1,1,-1,-1};
int knight_y[] = {1,-1,1,-1,2,-2,2,-2};
const int N =  210;
const int mod = 1e9+7;
int color[N];


bool is_valid(int i,int j,int n,int m){
    return i>=0 && i<n && j>=0 && j<m;
}
bool is_valid2(int i,int j,int n){
    return i>=0 && i<n && j>=0 && j<n;
}
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
void solve(int tc=1) {
    int n,m1,m2;
    cin>>n>>m1>>m2;
    DisjointSet ds1(n+1),ds2(n+1);
    for(int i=0;i<m1;i++){
        int u,v;
        cin>>u>>v;
        ds1.unionBySize(u,v);
    }
    for(int i=0;i<m2;i++){
        int u,v;
        cin>>u>>v;
        ds2.unionBySize(u,v);
    }
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ds1.findUPar(i)!=ds1.findUPar(j) && ds2.findUPar(i)!=ds2.findUPar(j)){
                ans.emplace_back(i,j);
                ds1.unionBySize(i,j);
                ds2.unionBySize(i,j);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x.first<<" "<<x.second<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    //input from file
//    freopen("input.txt", "r", stdin);
    int t=1;
//    cin>>t;
    int tc=1;
    while(t--){
        solve(tc);
    }
    return 0;
}
	 		  		    	  		 	  		       	