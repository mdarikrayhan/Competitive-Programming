#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string s;
    cin >> s;
    vector <int> v(s.size(), 0);
    for(int i=0; i<s.size(); i++){
        if(i>0 && s[i-1]==s[i]){
            v[i] = v[i-1]+1;
        }
        else v[i] = v[i-1];
    }
    cin >> t;
    int a, b;
    for(int i=0; i<t; i++){
        cin >> a >> b;
        cout << v[b-1]-v[a-1] << endl;
    }
}