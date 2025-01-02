#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <limits>
#include <cmath>
#include <unordered_map>
#include <queue>
#include<stack>
using namespace std;
#define ll long long


void f() {
    int n;cin>>n;
    map<int,set<int>>G;
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        G[x].insert(y);G[y].insert(x);
    }
    stack<int>cn;
    for(auto x:G){
        if(x.second.size()==1){
            cn.push(x.first);
        }
    }
    while(true){
        if(cn.size()==1){
            cout<<"! "<<cn.top()<<endl;cout.flush();return;
        }
        int x1=cn.top();cn.pop();
        int x2=cn.top();cn.pop();
        cout<<"? "<<x1<<" "<<x2<<endl;
        cout.flush();
        int la;cin>>la;
        if(la==x1 or la==x2){
            cout<<"! "<<la<<endl;
            cout.flush();return;
        }
        int parent1=*G[x1].begin();
        int parent2=*G[x2].begin();
        G[parent1].erase(x1);
        G[parent2].erase(x2);
        G[x1].erase(parent1);
        G[x2].erase(parent2);
        if(G[parent1].size()<=1){
            cn.push(parent1);
        }
        if(G[parent2].size()<=1 and parent2!=parent1){
            cn.push(parent2);
        }
        cout.flush();
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll x = 2;
    if (x == 1) {
        ll t;
        cin >> t;
        while (t--) {
            f();
        }
    } else {
        f();
    }
    return 0;
}
