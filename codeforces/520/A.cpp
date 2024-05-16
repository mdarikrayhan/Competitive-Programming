#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin>>s;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    sort(s.begin(),s.end());
    int arr[26] = {0};


    for(int i =0;i<s.length();i++)
    {
        arr[s[i]-'a'] = 1;
    }
    int sum = 0;

    for(int i =0;i< 26;i++)
    {
        sum += arr[i];
    }
    if(sum==26)
    cout<<"YES";
    else
    cout<<"NO";
}