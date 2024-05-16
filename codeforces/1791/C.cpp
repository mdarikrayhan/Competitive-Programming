#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
for (int i = 0; i < t; i++)
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int start=0,end=n-1,ans=0;
    while(start<=end)
    {
        if(s[start]=='1' && s[end]=='1'){
            ans=end-start+1;
            break;
        }
        else if(s[start]=='0' && s[end]=='0'){
            ans = end-start+1;
            break;
        }
        else {
          start++;
          end--;
        }
    }
    cout<<ans<<endl;
}

return 0;
}