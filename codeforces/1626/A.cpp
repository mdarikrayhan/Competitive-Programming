#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<climits>
#include<cmath>
#define ll long long int
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        cout<<s<<endl;
    }
    return 0;
}