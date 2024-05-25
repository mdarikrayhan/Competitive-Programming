// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#define int long long
#define ff first
#define ss second

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1;//scanf("%lld", &t);
    while(t--){
        int n, u, v;
        scanf("%lld", &n);
        vector<int> ans(n);
        vector<pair<int,int>> hm(n);
        for(int i=0; i<n; i++){
            scanf("%lld%lld", &u, &v);
            hm[i].ff=v-1;
            hm[i].ss=u-1;
        }
        if(n==3){
            cout << "1 2 3";
            return 0;
        }
        int i=0;
        for(int _=0; _<n; _++){
            ans[_]=i+1;
            if(hm[i].ss == hm[hm[i].ff].ff || hm[i].ss == hm[hm[i].ff].ss) i=hm[i].ff;
            else i=hm[i].ss;
        }
        for(int i=0; i<n; i++) printf("%lld ", ans[i]);
    }
}
