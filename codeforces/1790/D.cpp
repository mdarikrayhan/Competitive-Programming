#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int,int> mp;
    set<int> st;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
        st.insert(x);
        st.insert(x+1);
    }
    int count = 0, x = 0;
    for(auto it : st)
    {
        int y = mp[it];
        count += max(0, y - x);
        x = y;
    }
    cout << count << endl;

}
int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
}


				 			  		 	  			 		 	  		 	