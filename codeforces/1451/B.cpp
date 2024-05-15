// LUOGU_RID: 159078121

#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,T;
string s;
bool f;
int main()
{
	cin>>T;
	while (T--)
	{
		cin>>n>>q>>s;
		while (q--)
		{
			cin>>l>>r;
			l--;r--;
			f=0;
			for (int i=0;i<l;i++) if (s[i]==s[l]) {f=1; break; } 
			if (!f)
				for (int i=r+1;i<n;i++) if (s[i]==s[r]) {f=1; break; }
			if (f) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}