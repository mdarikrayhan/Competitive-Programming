#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<string, string>> str;
    vector<pair<string, string>> str2;

    for(int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        b = b + ";";
        str.push_back({a, b});
    }
    for(int i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;
        str2.push_back({a, b});
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(str[j].second == str2[i].second)
            cout << str2[i].first << " " << str2[i].second << " #" << str[j].first << '\n';
        }
    }

    return 0;
}
 		 	  			  	      	  	 	   		