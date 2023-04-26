#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;cin >> t;while(t--){
int n;cin >> n;
string s;cin >> s;
string t = s;
vector<int>v;
sort(t.begin(),t.end());
for(int i = 0 ; i < n ; i++)if(s[i]!=t[i])v.push_back(i+1);
if(v.size()==0)cout << 0 << endl;
else{
cout << 1 << endl;
cout << v.size()<<" ";
for(auto it : v)cout << it << " ";
cout << endl;
}
}
}