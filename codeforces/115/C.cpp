#include<bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define fi first
#define se second
#define pss pair<string,string>
#define double long double
#define vb vector<bool>
#define vvb vector<vb>

#define pb push_back

#define vvii vector<vii>

#define pcc pair<char,char>
#define picc pair<int,pcc>

const int mod=1000003;

void debug(vb v){
	for (int x:v) cerr << x << ' ';
	cerr << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;

	vvb left(n,vb(m,1));
	vvb up(n,vb(m,1));
	vvb dot(n,vb(m,0));

	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			char x;
			cin >> x;
			if (x=='.') dot[i][j]=1;
			left[i][j]=(x=='1' || x=='2');
			up[i][j]=(x=='1' || x=='4');
		}
	}

	int res=1;

	for (int i=0;i<n;i++){
		bool a=1;
		for (int j=0;j<m;j++){
			if (dot[i][j]) continue;
			if (j%2) a &= left[i][j];
			else a &= !left[i][j];
		}

		bool b=1;
		for (int j=0;j<m;j++){
			if (dot[i][j]) continue;
			if (j%2) b &= !left[i][j];
			else b &= left[i][j];
		}
		res=((int)(a)+b)*res%mod;
		//debug(left[i]);
		//cerr << i << ' ' << a << ' ' << b << ' ' << res << '\n';
	}

	for (int i=0;i<m;i++){
		bool a=1;
		for (int j=0;j<n;j++){
			if (dot[j][i]) continue;
			if (j%2) a &= up[j][i];
			else a &= !up[j][i];
		}

		bool b=1;
		for (int j=0;j<n;j++){
			if (dot[j][i]) continue;
			if (j%2) b &= !up[j][i];
			else b &= up[j][i];
		}
		res=((int)(a)+b)*res%mod;
		//cerr << i << ' ' << a << ' ' << b << ' ' << res << '\n';
	}

	cout << res << '\n';
    

}
