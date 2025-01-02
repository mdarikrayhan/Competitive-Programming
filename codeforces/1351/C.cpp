#include<bits/stdc++.h>
using namespace std;
#define int   long long int
    
    
signed main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        int x = 0, y = 0;
        int ans =0;
        set<pair<int, int>> c;

        for(int i =0; i<s.size(); i++){

            int a=x,b=y;
            int sz = c.size();

            if(s[i]=='N') y++;
            if(s[i]=='S') y--;
            if(s[i]=='E') x++;
            if(s[i]=='W') x--;

            c.insert({x+a,y+b});

            if(c.size()!=sz){
                ans+=5;
            }
            else ans+=1;

            
        }

        cout << ans << endl;
    }
    
    return 0;
}