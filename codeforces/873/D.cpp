#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void hassan(){
    int n , k;
    cin >> n >> k;
    if(k % 2 == 0){
        cout << -1 << '\n';
        return;
    }
    vector<int> v(n);
    iota(v.begin() , v.end() , 1);

    function<void(int,int)> solve = [&] (int l , int r){
        if(r == l + 1 || k == 1)
            return;
        k -= 2;
        int md = (l + r) / 2;
        swap(v[md] , v[md - 1]);
        solve(l , md);
        solve(md , r);
    };

    solve(0 , n);
    if(k != 1){
        cout << -1 << '\n';
        return;
    }
    for(auto &a : v)
        cout << a << " ";
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while(t --)
    hassan();
}
		 	     				 			 						   		