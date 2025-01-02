#include <bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		int n,m; cin >> n >> m;
        string s; cin >> s;
        int prev[n]; prev[0] = (s[0]=='0'?0: -1);
        for(int i=1;i<n;i++){
            prev[i] = (s[i]=='0'? i:prev[i-1]);
        }
        int next[n]; next[n-1] = (s[n-1]=='1'? n-1: n);
        for(int i=n-2;i>=0;i--){
            next[i] = (s[i]=='1'? i:next[i+1]);
        }

        set<pair<int,int>> st;
        for(int i=0; i<m; i++){
            int l,r; cin >> l >> r;
            l--; r--;
            l = next[l];
            r = prev[r];
            if(l>=r)st.insert({0,0});
            else st.insert({l,r});
        }

        cout << st.size() << "\n";
	}
}