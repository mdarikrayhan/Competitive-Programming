#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
#define ll long long
bool isVowel(char c)
{
    return (c == 'a' || c == 'e');
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        ll n;string s,ans="";
        cin >> n>>s;
        reverse(s.begin(),s.end());
        for(int i=0;i<n;){
            if(!isVowel(s[i])&&isVowel(s[i+1])&&!isVowel(s[i+2])){
                ans+=s[i];
                ans+=s[i+1];
                ans+=s[i+2];
                ans+='.';
                i+=3;
            }
            else{
                ans+=s[i];
                ans+=s[i+1];
                ans+='.';
                i+=2;
            }
        }
        reverse(ans.begin(),ans.end());
        ans.erase(ans.begin());
        cout<<ans<<nl;
    }
    return 0;
}