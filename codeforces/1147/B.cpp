#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;
set<pii> s;
int n, m;
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		s.insert({ a-1, b-1 });
	}
	for (int i = 1; i < n; i++) {
		if (!(n%i)) {
			bool flag = true;
			for (auto e : s) {
				if (!s.count({ (e.first + i) % n, (e.second + i) % n }) &&  
					!s.count({ (e.second + i) % n, (e.first + i) % n }) ){
					flag = false;
					break;
				}
			}
			if (flag) return !printf("Yes\n");
		}
	}
	printf("No\n");
}
	 	 	 	 	 	 			 			   	   	  	