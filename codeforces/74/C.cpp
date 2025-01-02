#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,m,i,j,k;
	cin>>n>>m;
	n--;m--;
	m=__gcd(n,m);
	m++;
	cout<<m<<"\n";
}