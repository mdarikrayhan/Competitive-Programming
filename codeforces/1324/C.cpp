#include <bits/stdc++.h>
#define ll long long

using namespace std;

string alph = "abcdefghijklmnopqrstuvwxyz";
string Alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        int ans = 0;
        int j=0,n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='R'){
                ans = max(ans,i+1-j);
                j=i+1;
            }
        }
        ans = max(n+1-j,ans);
        if(ans==0)
            ans = n+1;
        cout << ans << "\n";
    }
    return 0;
}