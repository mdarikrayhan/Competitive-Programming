#include<bits/stdc++.h>
using namespace std;
int T;
string str;
int p[10]={0,13,23,37,47,59,61,73,83,97};
void solve(){
    cin>>str;
    cout<<p[str[0]-'0']<<'\n';
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>T;
    while(T--) solve();
    return 0;
}