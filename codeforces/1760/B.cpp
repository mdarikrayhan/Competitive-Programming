#include<bits/stdc++.h>
using namespace std;

int main()
{
int t,n;
string s;
cin>>t;
while(t--) 
{
cin>>n;
cin>>s;
sort(s.begin(),s.end());
cout<<s[s.size()-1]-96<<endl;
}
    return 0;
}