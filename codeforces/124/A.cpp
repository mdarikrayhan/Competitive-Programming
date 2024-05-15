#include<iostream>
#include <cstring>
#include <map>
#define ll long long
using namespace std;
map<string,string> str;
int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    cout<<min(n-a,b+1);
    return 0;
}
