//???
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int mod;

int bfs (int v,vector<vector<int>>&tree,vector<int>&degree,vector<bool>&check) {
    check[v]=true;
    int sum=0;
    for (int i=0;i<tree[v].size();i++) {
        if(check[tree[v][i]]==false) {
            sum+=bfs(tree[v][i],tree,degree,check)%2;
        }
    }
    sum++;
    degree[v]=sum;
    return degree[v];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<vector<int>>tree(n);
    for (int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    vector<int> degree(n,-1);
    vector<bool> check(n,false);
    int out=0;
    if(n&1) {
        out=0;
    }
    else {
        bfs(0,tree,degree,check);
    }
    for (int i=0;i<n;i++) {
        if(degree[i]%2==0) {
            out++;
        }
        //cout<<i<<" "<<degree[i]<<" "<<endl;
    }
    cout<<out-1<<endl;
}