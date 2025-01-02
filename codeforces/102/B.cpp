#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void hassan(){
    string s;
    cin >> s;
    for(int i = 0; ; i ++){
        if(s.size() == 1){
            cout << i << '\n';
            return;
        }
        int sm = 0;
        for(auto &a : s)
            sm += a - '0';
        s = to_string(sm);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin >> t; while(t --)
    hassan();
}
 			  					   	   	 		  	 	  	