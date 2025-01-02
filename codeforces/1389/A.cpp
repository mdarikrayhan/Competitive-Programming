#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void hassan(){
    int l , r;
    cin >> l >> r;
    if(l * 2 <= r)
        cout << l << " " << 2 * l << '\n';
    else
        cout << -1 << " " << -1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while(t --)
    hassan();
}
								  	 		    	  		 	 		