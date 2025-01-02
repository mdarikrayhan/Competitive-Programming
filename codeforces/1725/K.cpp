#include <bits/stdc++.h>
using namespace std;
#define N 2000000
int n, q, op, x, y, l, r, cnt, a[400010], rev[2000010], f[2000010];
map <int, int> mp;
set <int> s;
set <int> :: iterator it, itt;
int find(int x){
	if (x != f[x]) return f[x] = find(f[x]);
	return f[x];
}
int main(){
	scanf ("%d", &n);
	cnt = n;
	for (int i=1; i<=N; i++) f[i] = i;
	for (int i=1; i<=n; i++){
		scanf ("%d", &a[i]);
		if (!mp[a[i]]) mp[a[i]] = ++cnt, rev[cnt] = a[i];
		f[i] = mp[a[i]];
		s.insert(a[i]);
	//	printf ("cnt = %d, val = %d\n", mp[a[i]], a[i]);
	}
	scanf ("%d", &q);
	for (int i=1; i<=q; i++){
		scanf ("%d", &op);
		if (op == 1){
			scanf ("%d%d", &x, &y);
			if (!mp[y]) mp[y] = ++cnt, rev[cnt] = y;
		//	printf ("cnt = %d, val = %d\n", cnt, y);
			s.insert(y);
			f[x] = mp[y];
		}
		else if (op == 2){
			scanf ("%d", &x);
			int fx = find(x);
			assert(fx > n);
			printf ("%d\n", rev[fx]);
		//	printf ("fx = %d\n", fx);
		}
		else{
			scanf ("%d%d", &l, &r);
			it = s.lower_bound(l); itt = it;
			vector <int> tmp;
			for (; it!=s.end() && *it<=r; it++){
				tmp.push_back(*it);
			}
			int pd1 = 0, pd2 = 0;
			for (int j=0; j<tmp.size(); j++){
				int now = tmp[j];
				if (now - l < r - now){
					if (!mp[l-1]) mp[l-1] = ++cnt, rev[cnt] = l-1;
					int fx = find(mp[now]), fy = find(mp[l-1]);
					f[fx] = fy;
					pd1 = 1;
				}
				else{
					if (!mp[r+1]) mp[r+1] = ++cnt, rev[cnt] = r+1;
					int fx = find(mp[now]), fy = find(mp[r+1]);
					f[fx] = fy;
					pd2 = 1;
				}
				mp[now] = 0;
			}
			s.erase(itt, it);
			if (pd1) s.insert(l-1);
			if (pd2) s.insert(r+1);
		}
	}
	return 0;
}

		   	   		 	     		  	 		 		