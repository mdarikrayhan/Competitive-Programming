#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int n,flag=1;
        cin >> n;
        string s;
        cin >> s;
        int temp=0;
        if(s[0]=='m' || s[0]=='M'){
            while (s[temp]=='m' || s[temp]=='M')
            {
                temp++;
            }
        }
        else{
            cout<<"NO"<<nl;
            continue;
        }
        if(s[temp]=='e' || s[temp]=='E'){
            while (s[temp]=='e' || s[temp]=='E')
            {
                temp++;
            }
        }
        else{
            cout<<"NO"<<nl;
            continue;
        }
        if(s[temp]=='o' || s[temp]=='O'){
            while (s[temp]=='o' || s[temp]=='O')
            {
                temp++;
            }
        }
        else{
            cout<<"NO"<<nl;
            continue;
        }
        if(s[temp]=='w' || s[temp]=='W'){
            while (s[temp]=='w' || s[temp]=='W')
            {
                temp++;
            }
        }
        else{
            cout<<"NO"<<nl;
            continue;
        }
        if(temp==n){
            cout<<"YES"<<nl;
        }
        else{
            cout<<"NO"<<nl;
        }
        
    }
    return 0;
}