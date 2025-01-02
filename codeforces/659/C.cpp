#include<bits/stdc++.h>
using namespace std;

#define pb push_back

int main(){
	
	int n, m;
	cin >> n >> m;
	vector<int> a;
	
	for(int i = 0; i < n; i++){
		int temp; 
		cin >> temp;
		a.pb(temp);
	}
	
	sort(a.begin(), a.end());
	
	vector<int> ans;
	
	int cnt = 0;
	int pnt = 0;
	int k = 1;
	
	while(cnt < m){
		
		if(k == a[pnt]){
			if(pnt + 1 < n){
				pnt++;	
			}
		}
		else if(cnt + k <= m){
			cnt += k;
			ans.pb(k);
		}else{
			break;
		}
		
		k++;
	}
	
	cout << ans.size() << endl;
	
	for(auto x : ans)
	cout << x << " ";
	
	return 0;
}