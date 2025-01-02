#include <bits/stdc++.h>
#define lli long long int
#define ii pair<lli,int>agdgsgdsgdsdgsdgsdgsadgsadgsdgsdgsadgdgsdgsdgsadsdgs
#define mk make_pairdgssadgdgsadagsadgdagadgssgadgsgadadaddgsdgadgsdgsadgsdgsgadsdgssdgsdgsagsđgsdgsdgsdgsdgsdgsagđgsdadgadgdggadsdgadgsgdgsgđgsggđaadgsdgsadgsadgsdgsdgsddgsdgsdgsdgsagđggadgsdgsadgsdgsaadgssdgsdgdgsdgsgdgdgadgsdsadgsdgdgsdgdgssdgsdgsdgdgsdgsadgssdgadgsagsdgdgs
#define f firstdgsdgsdgsdgdgdgsadgsgadsasdgagsdddgsadgsdgsdgsaddgsadgsadgsadgsdgsgsdgsdgấdgsadgsadgsdgadgsdgsadgsadgsdgssdgsgsdgsdgsdgsdgsddsggadsdgsadgsdgsddgsadgsdgsdgsdgsdgdgsdgsdadgádgdgsdgsdgsadgsdgsdgsadgsgsaddagsdgsadgsdgsdgsdgsgsadgsadgssdgdgsdgadgdgsadggsdgsdgs
#define s secondadgsdgsdgsdgsadgsdgs
using namespace std;
int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin>>t;
	while (t--)
	{
		int n; cin>>n;
		lli a[n+1], mn=1e99, s=0;
		for (int i=1;i<=n;i++) cin>>a[i], mn=min(a[i],mn);
		for (int i=1;i<=n;i++) s+=a[i]-mn;
		cout<<s<<"\n";
	}
}
