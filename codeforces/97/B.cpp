#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 2e5+5;

int n,m;

struct point {
	int x,y;
	bool operator < (const point &a) const {
		return x==a.x?y<a.y:x<a.x;
	}
	bool operator == (const point &a) const {
		return x==a.x && y==a.y;
	}
} a[N];

void sol(int l,int r){
	if (l!=r){
		int mid=l+r>>1;
		for (int i=l; i<=r; i++){
			a[++n]={a[mid].x,a[i].y};
		}
		sol(l,mid),sol(mid+1,r);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+1+n);
	sol(1,n);
	set<point> st;
	for (int i=1; i<=n; i++){
		st.insert(a[i]);
	}
	cout<<st.size()<<"\n";
	for (auto u : st){
		cout<<u.x<<' '<<u.y<<"\n";
	}
	return 0;
}
