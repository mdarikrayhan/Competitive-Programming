#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <deque>
using namespace std;
typedef long long int ll;
const int M=2000+10;

char a[M][M];

int main() {
	
	
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int k; cin>>k;
	int t = 0;
	for (int i = 0; i < n; i++){
		string s; cin>>s;
		for (int j = 0; j < m; j++){
			a[i][j] = s[j];
			if (a[i][j] == '.'){
				t++;
			}
		}
	}
	
	if (k == 1){
		cout<<t<<endl;
		return 0;
	}
	
	int res = 0;
	for (int i = 0; i < n; i++){
		int p = 0;
		while(p < m){
			int p1 = p;
			while(p1 < m && a[i][p1] == '*'){
				p1++;
			}
			int p2 = p1;
			while(p2 < m && a[i][p2] == '.'){
				p2++;
			}
			int len = p2 - p1;
			res += max(len - k + 1, 0);
			p = p2;
		}
	}
	
	for (int i = 0; i < m; i++){
		int p = 0;
		while(p < n){
			int p1 = p;
			while(p1 < n && a[p1][i] == '*'){
				p1++;
			}
			int p2 = p1;
			while(p2 < n && a[p2][i] == '.'){
				p2++;
			}
			int len = p2 - p1;
			res += max(len - k + 1, 0);
			p = p2;
		}
	}
	cout<<res<<endl;
	
	
	return 0;
}
