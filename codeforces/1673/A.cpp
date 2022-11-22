#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string s;
        cin >> s;
        int n=s.length(),alice=0;
        for(int i=0;i<n;i++)
            alice += s[i]-'a'+1;
        if(n%2==0)
            cout << "Alice " << alice << '\n';
        else
        {
            int bob;
            if(s[0]<=s[n-1])
                bob = s[0]-'a'+1;
            else
                bob = s[n-1]-'a'+1;
            alice -= bob;
            if(alice > bob)
                cout << "Alice " << alice-bob << '\n';
            else if(alice < bob)
                cout << "Bob " << bob-alice << '\n';
            else
                cout << "Draw " << 0 << '\n';
        }
    }
}