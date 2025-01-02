#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    unordered_set<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.insert(s[i]);
    }
    if(st.size()%2==0){
        cout<<"CHAT WITH HER!"<<nl;
    }
    else{
        cout<<"IGNORE HIM!"<<nl;
    }
    return 0;
}