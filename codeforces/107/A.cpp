#include<bits/stdc++.h>
using namespace std;
#define int long long int

int mod = 1e9 + 7;
const int g = 1e6 + 5;
int fact[g];

int flip(int n){int n1 = floor(log2(n)) + 1;return ((1 << n1) - 1) ^ n;}
string d2b(unsigned n){unsigned i;string s;s.push_back('0');for (i = 1 << 31; i > 0; i = i / 2){if ((n & i) != 0) {s.push_back('1');}else {s.push_back('0');}}return s;}
void rangee(int i,vector<int> &a,int n){for(int k = i;k<n;k++){cout << a[k] << " ";}}
int power(int x, int y){int z = 1;x = x % mod;	while (y > 0){if (y & 1)z = (z * x) % mod;y = y >> 1;x = (x * x) % mod;}return z;}
void seive(){for (int i = 2; i < g; i++){fact[i] = i;}for (int i = 2; i < g; i++){if (fact[i] != i){continue;}for (int j = 2 * i; j < g; j += i){fact[j] = min(fact[j], i);}}}
int b2d(string n){string num = n;int dec_value = 0;int base = 1;int len = num.length();for (int i = len - 1; i >= 0; i--) {if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}


void dfs(int s,vector<pair<int,int>> adj[],vector<vector<int>> &ans,vector<int> &a,int m){    
    if(adj[s].size()==0){
        a.push_back(s);
        a.push_back(m);
        if(m!=1e9)
        ans.push_back(a);
        return;
    }
    dfs(adj[s][0].first,adj,ans,a,min(m,adj[s][0].second));
    
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,p;
    cin >> n >> p;
    vector<pair<int,int>> adj[n+1];
    vector<int> indegree(n+1,0);
    for(int i=0;i<p;i++){
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({b,d});
        indegree[b]++;
    }

    vector<vector<int>> ans;
    // cout << indegree[3] << endl;
    for(int i=1;i<n+1;i++){
        if(indegree[i]==0){
            vector<int> a = {i};
            dfs(i,adj,ans,a,(1e9));
        }
    }

    cout << ans.size() << endl;;
    for(auto i:ans){
        
        cout << i[0] << " " << i[1] << " " << i[2] << endl; 
    }


}