#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, d1, d2;
int a[2005], atmp[2005], sz;
int b[2005];
int lb = 0, ub = 0, id1 = 0;
int vl[2005], id2 = 0;

vector<pair<int, int> >ans;

void no(bool bad){if(bad){cout << "NO\n"; exit(0);}}

void op1(int x){
//	cout << "op1 " << x << endl;
	no(x > d1);
	for(int i = lb + x; i > lb; i --)
		b[++id1] = a[i];
	lb += x;
	ans.push_back({1, x});
}

void op2(int x){
	no(x > d2);
	id1 -= x;
	sz -= x;
	ans.push_back({2, x});
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> d1 >> d2;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		atmp[i] = a[i];
	}

	sort(atmp + 1, atmp + n + 1);
	for(int i = 1; i <= n; i ++){
		a[i] = lower_bound(atmp + 1, atmp + n + 1, a[i]) - atmp;
//		cout << a[i] << " ";
	}

	for(sz = n; sz > 0;){
//		cout << "owo\n";
		for(int found = 1; found;){
			found = 0;
			for(int i = lb + 1; i <= n; i ++){
				if(a[i] == sz){
//					cout << "1\n";
					for(int j = 0, times = i - lb; j < times; j ++)
						op1(1);
				}
				else if(a[i] + 1 < a[i + 1])
					break;
			}
			for(int i = id1; i > 0; i --)
				if(b[i] == sz){
//					cout << "10\n";
					op2(id1 - i + 1);
					found ++;
				}
		}

		int mn = 1000000000, mx = -1000000000;
		vl[0] = lb, id2 = 0;
		int ii;
		for(ii = lb + 1; ii <= n; ii ++){
			mn = min(mn, a[ii]);
			mx = max(mx, a[ii]);
			if(a[ii] + 1 != a[ii + 1])
				vl[++id2] = ii;
			if(a[ii] + 1 < a[ii + 1])
				break;
		}

		ub = ii;
		if(mx - mn + 1 > ub - lb){
//			cout << "2\n";
			op1(ub - lb);
		}
		else{
			mx = -1000000000;
			for(int i = 1; i <= id2; i ++)
				mx = max(mx, vl[i] - vl[i - 1]);

			if(mx <= d1 && vl[id2] - lb <= d2){
//				cout << "3\n";
				for(int i = 1; i <= id2; i ++)
					op1(vl[i] - lb);
			}
			else if(id2 == 1){
//				cout << "4\n";
				for(; lb < vl[1];)
					op1(1);
			}
			else if(id2 > 2){
//				cout << "5\n";
				op1(vl[id2] - lb);
			}
			else{
				for(ii = lb + 1; ii <= vl[id2]; ii ++){
					if(max(ii - lb, vl[2] - ii) <= d1
					&& max(abs(vl[1] - ii), vl[2] - lb - abs(vl[1] - ii)) <= d2){
//						cout << "6\n";
						op1(ii - lb);
						if(vl[id2] - ii){
//							cout << "7\n";
							op1(vl[id2] - ii);
						}
						ii = -1;
						break;
					}
				}
				no(ii != -1);
			}
		}
		for(int i = id1; i > 1; i --)
			no(b[i] + 1 < b[i - 1]);
	}

	cout << "YES\n" << ans.size() << endl;
	for(pair<int, int> i : ans)
		cout << i.first << " " << i.second << endl;

	return 0;
}