#include <bits/stdc++.h>

using namespace std;
long long p = 1000000000 + 7;
vector <vector <int>> a;
int c;
void num(string& s){
	int i=0;
	while (i<s.size()){
		int ch=0;
		while (s[i]>='0' and s[i]<='9' and i<s.size()){
			char d=s[i];
			ch=ch*10+d-'0';
			i++;
		}
		a[c].push_back(ch);
		i++;
	}
}
int to_int(string& s){
	int num=0;
	int i=0;
	while (i<s.size()){
		char d=s[i];
		num=num*10+d-'0';
		i++;
	}
	return num;
}
vector <set<pair<int, int>>> g;
map <tuple<int, int, int>, int> ma;
vector <int> colour;
vector <int> ans;
void dfs(int v){
    for (auto [e, ty]: g[v]){
        if (ma.find({v, e, ty})==ma.end() and ma.find({e, v, ty})==ma.end()){
            ma[{v, e, ty}]=ty;
            //ma[{e, v, ty}]=ty;
            dfs(e);
        }
    }
    ans.push_back(v);
}
void solve(){
    int n, m;
    cin>>n>>m;
    ma.clear();
    g=vector <set <pair<int, int>>>(n+1);
    for (int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        x--;
        y--;
        g[x].insert({y, 1});
        g[y].insert({x, 1});
    }
    int pre=-1;
    int kol=0;
    for (int i=0; i<n; i++){
        if (g[i].size()%2==1){
            g[i].insert({n, 2});
            g[n].insert({i, 2});
            kol++;
        }
    }
    cout<<n-kol<<"\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<g[i].size(); j++){
            ans=vector <int>(0);
            dfs(i);
            /*for (auto e: ans){
                cout<<e+1<<" ";
            }
            cout<<" | ";
            for (int i=1; i<ans.size(); i++){
                if (ma[{ans[i-1], ans[i], 1}]==1){
                    cout<<ans[i-1]+1<<" "<<ans[i]+1<<"\n";
                }
            }
            if (ans.size()>1 and ma[{ans.back(), ans[0]}]==1){
                cout<<ans.back()<<" "<<ans[0]<<"\n";
            }*/
        }
    }
    //cout<<endl;
    for (auto e: ma){
        auto[v1, s]=e;
        auto[v, to, ty]=v1;
        if (ty==1) cout<<v+1<<" "<<to+1<<"\n";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}