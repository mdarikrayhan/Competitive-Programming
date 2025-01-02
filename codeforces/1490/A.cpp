#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//cout<<" = "<< <<endl;


bool findLetter ( string s, char a );
ll gcd ( ll a, ll b );
ll lcm ( ll a, ll b );
int numberOfDegits ( int n );
bool multiOfTwo ( int n );



int main()
{
	FAST
	ll t = 1;
	cin >> t;
	int n, ans, mx, mn;

	while ( t-- ) {
		ans = 0;
		cin >> n;
		int arr[n];

		for ( int i = 0; i < n; i++ ) {
			cin >> arr[i];
		}

		for ( int i = 0; i < n - 1; i++ ) {
			mx = max ( arr[i], arr[i + 1] );
			mn = min ( arr[i], arr[i + 1] );

			while ( ( mx / mn ) > 2 || ( ( mx / mn ) == 2 && mx % mn != 0 ) )              {
				mn *= 2;
				ans++;
			}
		}

		cout << ans;

		if ( t ) {
			cout << endl;
		}
	}
}










bool findLetter ( string s, char a )
{
	for ( int i = 0; i < s.size(); i++ ) {
		if ( s[i] == a ) {
			return true;
		}
	}

	return false;
}
ll gcd ( ll a, ll b )
{
	if ( b == 0 ) {
		return a;
	}

	return gcd ( b, a % b );
}
ll lcm ( ll a, ll b )
{
	return ( a / gcd ( a, b ) ) * b;
}

int numberOfDegits ( int n )
{
	int ans = 0;

	while ( n > 0 ) {
		n /= 10;
		ans++;
	}

	return ans;
}

bool multiOfTwo ( int n )
{
	int ans = 1;
	int k = log2 ( n );

	for ( int i = 0; i < k; i++ ) {
		ans *= 2;
	}

	if ( ans  ==  n ) {
		return 1;
	}

	return 0;
}
