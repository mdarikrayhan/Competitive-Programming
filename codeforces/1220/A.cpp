#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    int z=0,one=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='n')
        {
            one++;
        }
        else if(str[i]=='z')
        {
            z++;
        }
    }
    vector<int>ans;
    while(one--)
    {
        ans.push_back(1);
    }
    while(z--)
    {
        ans.push_back(0);
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}