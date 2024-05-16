/*
* JAY SHREE RAM
* JAY SHREE GANESH
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define nline "\n"
#define MOD 1000000007
void joyshreeram() {
    ll n;
    cin>>n;
    string str;
    cin>>str;
    string ans1="",ans2="";
    for(int i=0;i<n;i++){
        ans1+='1';
        ans2+='0';
    }
    ll count1=0,count2=0;
    for(int i=0;i<n;i++){
        ll ind1=0,ind2=0;
        for(int j=i;j<i+n;j++){
            if(str[j]==ans1[ind1]){
                count1+=1;
                break;
            }
            ind1+=1;
        }
        for(int j=i;j<i+n;j++){
            if(str[j]==ans2[ind2]){
                count2+=1;
                break;
            }
            ind2+=1;
        }
    }
    if(count1==n){
        cout<<ans1<<nline;
        return;
    }
    cout<<ans2<<nline;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
        ll testcases;
        cin>>testcases;
        while(testcases--){
            joyshreeram();
        }
return 0;
}