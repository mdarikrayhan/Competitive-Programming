#include <iostream>
using namespace std;
int t;
string s;
void solve(){
    long long maxx=0;
    s+="0";
    for (int i=0, cnt=0;i<s.size();i++){
        if (s[i]=='1')cnt++;
        else {maxx=max(maxx, (long long)cnt); cnt=0;}
    }
    if (maxx==s.size()-1)cout<<maxx*maxx;
    else if (maxx%2==0)cout<<maxx/2*(maxx/2+1);
    else cout<<(maxx/2+1)*(maxx/2+1);
    cout<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while (t--){
        cin>>s;
        if (s.find("0")!=-1){
            while (s[s.size()-1]=='1'){
                s.erase(s.size()-1, 1);
                s="1"+s;
            }
        }
        solve();
    }
    return 0;
}

