#include<bits/stdc++.h>
#define ll long long
const int N=1e5+10;
using namespace std;
void solve()
{
    string ans="hello";
    string s;
    int cnt=0;
    cin>>s;
    for(auto ss:s)
    {
        if(ss==ans[cnt]&&cnt<ans.size())
            cnt++;
    }
    if(cnt==ans.size())
        cout<<"YES";
    else
        cout<<"NO";
}
int main()
{
	 ios::sync_with_stdio(false);
cin.tie(0);
    cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
 }

  			   	 	 	 	  	 	 			 		  	