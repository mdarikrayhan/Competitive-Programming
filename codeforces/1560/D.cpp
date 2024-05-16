#include<bits/stdc++.h>
using namespace std;
vector<string> arr;
int f(string s,string t){
    int i = 0;
    int j = 0;
    int n1 = s.length();
    int n2 = t.length();
    int taken = 0;
    while(i < n1 && j < n2){
        if(s[i] == t[j]){
            taken++;
            j++;
        }
        i++;
    }
    return n1-taken+n2-taken;
}
void solve(){
    string s;
    cin>>s;
    int ans = s.length()+1;
    for(string t: arr){
        ans = min(ans,f(s,t));
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(long long i=1;i<=2e18;i*=2){
        arr.push_back(to_string(i));
    }
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}