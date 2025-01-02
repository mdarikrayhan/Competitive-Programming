#include<bits/stdc++.h>
using namespace std;
 
#define int long long int
const int mx = 4e6 ;
#define pb push_back
const int mod = 1e9+7;

 
int32_t main(){
		int t=1; cin >> t;
		while(t--){
			int n, l, r, s;	cin >> n >> l >> r >> s;
			set<int> taken;
			int x = (r-l+1);
			int lst = n; int m = s;
			while(x and lst > 0){
				if(taken.find(lst) != taken.end() or lst > m){
					lst--; continue;
				}
				if((m - lst) >= (x-1)*(x)/2 ){
					m -= lst;
					taken.insert(lst);
					
				} else if((m - lst) < (x-1)*(x)/2 ){
					lst--; continue;
				}
				 else {
					taken.insert(lst);
					m -= lst;
				}
				lst--;
				x--;
			}
			if(m == 0){
				set<int> nottaken;
				for(int i=1; i<=n; i++){
					if(taken.find(i) == taken.end()){
						nottaken.insert(i);
					}
				}
				for(int i=1; i<=n; i++){
					if(i >= l and i <= r){
						for(auto y:taken){
							cout << y << " ";
						}
						i =r;
					} else{
						cout << *nottaken.begin() << " ";
						nottaken.erase(nottaken.begin());
					}
				}
			}	 else{
				cout << "-1";
			}
			cout << "\n";
		}
		
}