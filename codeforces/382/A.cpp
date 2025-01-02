#include <iostream>
#include <bits/stdc++.h>
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair
#define el '\n'
using namespace std;

//IEHOVA;
char grid[100][100];
bool seen[100][100];
bool valid(int i,int j){
    return {i < 1 && i >=0 && j <1 && j >=0};
}
string path = "IEHOVA#";
vector<string> Dir = {"right","left","forth"};
int DX[] ={-1,0,1,0,1,1,-1,-1};
int DY[] ={0,-1,0,1,-1,1,1,-1};

void dfs(int i ,int j ){
    if (seen[i][j] || grid[i][j] == '.') return;
    if (valid(i,j)){
        seen[i][j] = true;
        dfs(i,j+1);
        dfs(i-1,j);
        dfs(i+1,j);
        dfs(i,j-1);
    }


}

bool isBipartite(int i , vector<vector<int>>adj,int color[]){
    queue<int> q;
    q.push(i);
    color[i]=0;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        for (auto it: adj[node]) {
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }else if (color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}
vector<vector<int> > adj;
bool seek[150];
vector<int>eg;
void Topological_Sort(int k){
    seek[k]= true;
    for (int i = 0; i < adj[k].size(); ++i) {
        if (!seek[adj[k][i]]){
            Topological_Sort(adj[k][i]);
        }
    }
    eg.emplace_back(k);

}
ll Gcd(ll a, ll b){
    if (a == 0) return b;
    Gcd(b  %a, a);
}

ll Lcm(ll a, ll b){
    return (a*b) / Gcd(a, b);
}
int M[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s , z,ans="",part1 , part2;
    int s3;
    cin >> s >> z;
    int f = s.find('|');
    part1 = s.substr(0,f);
    part2 = s.substr(f+1,s.size());
    s3 = z.size();

    if(part1.size() == part2.size()){
        if(s3%2==0){
            ans = part1 + z.substr(0,s3/2) + '|'+part2+ z.substr(s3/2,z.size());
            cout << ans;
        }else{
            cout << "Impossible";
        }
    }else{
        int x = part1.size()-part2.size();
        x = abs(x);
        if ((s3-x)%2==0 && (s3-x) >=0){
            if (part1.size() < part2.size()){
                part1 += z.substr(0,x);
            } else{
                part2 += z.substr(0,x);
            }
            z.erase(0,x);
            s3 = z.size();
            ans = part1 + z.substr(0,s3/2) + '|'+part2+ z.substr(s3/2,z.size());
            cout << ans;

        } else{
            cout << "Impossible";
        }
    }

    return 0;

}



/*
*/