#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    bool lucky = true;
    for(int i=0; i<s.size(); i++) if(s[i]!='4' && s[i]!='7')
        {
            lucky = false;
            break;
        }

    int fir_half = 0, sec_half = 0;
    for(int i=0; i<(n/2); i++) fir_half+=(s[i]-'0');
    for(int i=(n/2); i<n; i++) sec_half+=(s[i]-'0');

    if(fir_half != sec_half) lucky = false;

    if(lucky) cout<<"YES";
    else cout<<"NO";

    return 0;
}

   		 			 		 			       	    	