#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s,t;
    cin>>s>>t;
    int e=0;
    for(int i=0;i<t.size();i++){
        if(s[e]==t[i]) e++;
    }
    cout<<e+1<<endl;
    return 0;
}