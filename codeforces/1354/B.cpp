#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define file "test"
using namespace std;

const ll N   = 1e6+1;
const ll NN  = 1e3+9;
const ld eps = 1e-7;
const ll oo  = 1e16 + 1;
const ll MOD = 1e9+7;

ll res, t;
string s;
vector < pair <ll, ll> > v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
			// freopen(file".inp","r",stdin);
			// freopen(file".out","w",stdout);
	#endif
	cin >> t;
	while ( t-- )
		{
			cin >> s;
			res = oo;
			v.clear();
			for ( int i=0;i<s.size();i++ )
				{
					if ( v.empty() || v.back().first != s[i] ) 
						{
							v.push_back({s[i], 1});
						}
					else v.back().second += 1;
				}

			for ( int i=1;i<v.size()-1;i++ )
				{
					if ( v[i-1].first != v[i+1].first )
						res = min ( res, v[i].second + 2 );
				}

			if ( res == oo ) cout << 0 << "\n";
			else cout << res << "\n";
		}
	return 0;
}
/*

    ____             _   __                                     _    __          ______ __     _                 __  __
   / __ ) __  __    / | / /____ _ __  __ __  __ ___   ____     | |  / /____     /_  __// /_   (_)___   ____     / / / /____ _ ____
  / __  |/ / / /   /  |/ // __ `// / / // / / // _ \ / __ \    | | / // __ \     / /  / __ \ / // _ \ / __ \   / /_/ // __ `// __ \
 / /_/ // /_/ /   / /|  // /_/ // /_/ // /_/ //  __// / / /    | |/ // /_/ /    / /  / / / // //  __// / / /  / __  // /_/ // /_/ /
/_____/ \__, /   /_/ |_/ \__, / \__,_/ \__, / \___//_/ /_/     |___/ \____/    /_/  /_/ /_//_/ \___//_/ /_/  /_/ /_/ \__,_/ \____/
       /____/           /____/        /____/


*/
