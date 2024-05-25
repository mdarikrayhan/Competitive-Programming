#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef unsigned long long ull;
#define MOD 1000000007
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORll(i,a,b) for(ll i=a;i<b;i++)
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define fast_io ios::sync_with_stdio(0);cin.tie(0);
#define debug(x) for(auto k:x) cout<<k<<" ";cout<<"\n";
#define int long long
#define endl "\n" 

int gcd(int a,int b){if(b==0)return a;else return gcd(b,a%b);}
int lcm(int a,int b){return a*b/gcd(a,b);}
int power(int x, unsigned int y, unsigned int M)
{
    if (y == 0)
        return 1;
 
    int p = power(x, y / 2, M) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
int modInverse(int A, int M)
{
    int g = gcd(A, M);
    if (g != 1)
        return -1;
    else {
       return power(A, M - 2, M);
    }
}
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
void bfs(vector<vector<int> >& adjList, int startNode,
         vector<bool>& visited)
{
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return;
}

// --- code starts here --- 
//to reverse sort use greater<int>()
//use "\n" instead of endl
signed main(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    int n,k;
    cin>>n>>k;
    map<int,vector<int>> d;
    FOR(i,0,n){
        int di;
        cin>>di;
        d[di].PB(i);
    }
    if(sz(d[0])!=1){
        cout<<-1; 
        return 0;
    }
    vector<vector<int>> adj(n);
    FOR(i,1,n){
        if(i==1 and sz(d[i])>k){cout<<-1;return 0;}
        else if(i!=1 and sz(d[i])>(k-1)*sz(d[i-1])){cout<<-1;return 0;}
        else{
            int cur = 0;
            int szz = sz(d[i-1]);
            for(auto x:d[i]){
                adj[d[i-1][cur]].PB(x);
                adj[x].PB(d[i-1][cur]);
                cur++;
                cur %= szz;
            }
        }
    }

    int m=0;
    for(auto x:adj){
        m += sz(x);
    }
    m /= 2;
    cout<<m<<endl;
    FOR(i,0,n){
        for(auto x:adj[i]){
            if(x > i){
                cout<<i+1<<" "<<x+1<<endl;
            }
        }
    }
    return 0;
    
}