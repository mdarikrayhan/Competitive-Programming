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
void joyshreeram(){
    string str;
    cin>>str;
    stack<char>arr1,arr2;
    ll ans=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='['||str[i]==']'){
            if(arr1.empty()) {
                arr1.push(str[i]);
            }
            else if(arr1.top()=='['&&str[i]==']'){
                ans+=1;
                arr1.pop();
            }
            else{
                arr1.push(str[i]);
            }
        }
        else{
            if(arr2.empty()) {
                arr2.push(str[i]);
            }
            else if(arr2.top()=='('&&str[i]==')'){
                ans+=1;
                arr2.pop();
            }
            else{
                arr2.push(str[i]);
            }
        }
    }
    cout<<ans<<nline;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    ll testcases;
    cin>>testcases;
    while(testcases--){
        joyshreeram();
    }
    return 0;
}