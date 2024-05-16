#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define modulo (1000000007)
#define endl '\n'
#define gap ' '

void solve() 
{
    int n,k=0;
    cin >>n;
    string s;
    cin >> s;
    for (int i = 0; i < n/2; i++) 
    {
        if(s[i]!=s[n-i-1])
        {
            k++;
        }
    }
    string ans="";
    if(k==0)
    {
        for (int i = 0; i < n+1; i++) 
        {
            if(i%2==1 && n%2==0)cout << "0";
            else cout << "1";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < k; i++) 
    {
        ans+="0";
    }
    for (int i = k; i < n+1-k; i++) 
    {
        if( abs(k%2-i%2)==1 && n%2==0)
        {
            ans+="0";
        }
        else
        {
            ans+="1";
        }
    }
    for (int i = 0; i < k; i++) 
    {
        ans+="0";
    }
    cout << ans << endl;
}
int main() 
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) 
	{
		solve();
	}
	return 0;
}