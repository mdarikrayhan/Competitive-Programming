#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include<bits/stdc++.h>
#define int long long 


int calc(int n, int k, vector<int>& p, vector<int>& a, int st) {
    int ans = 0;
    int curr = st;
    vector<bool> visited(n, false);
    int sum = 0;

    while (k > 0 && !visited[curr]) {
        ans = max(ans, sum + k * a[curr]);
        sum += a[curr];
        k--;
        visited[curr] = true;
        curr = p[curr] - 1;
    }

    return ans;
}


bool isValid(vector<int>& arr, int mid, int k) {
    int cnt = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (arr[i] < mid) {
            cnt += (mid - arr[i]);
        }
    }

    return cnt <= k;
}
bool icy(int vis[],vector<int> adj[],int node,int par,vector<pair<int,int>>&temp){
    vis[node]=1;
    for(auto it:adj[node]){
        if(it!=par){
            if(vis[it]){
                temp.push_back({node,it});
                return true;
            }
            else {
                temp.push_back({node,it});
               if( icy(vis,adj,it,node,temp)==true)return true;;
            }
        }
    }
    temp.pop_back();
    return false;
}

string fo(int k){
    string ans="";
    if(k== (long long)0)return ans;
    while(k>0){
        int dig=k%9;
        ans=to_string(dig)+ans;
        k/=9;
    }
    return ans;
}

void solve() {
 int k;
 cin>>k;
 string s=fo(k);
 //cout<<s;
 for(int i=0;i<s.size();i++){
     if(s[i]-'0'<=3){
         cout<<s[i]-'0';
     }
     else {
         cout<<(s[i]-'0')+1;
     }
 }
 cout<<endl;
 
}

int32_t main() {
    int t;
    cin >> t;

    while (t > 0) {
         solve();
        t--;
    }

    return 0;
}
