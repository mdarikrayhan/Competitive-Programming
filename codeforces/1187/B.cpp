#include <bits/stdc++.h>
using namespace std;

const int MAX_SADIK = 2e5 + 5;
char show[MAX_SADIK];
char name[MAX_SADIK];

int main()
{
    int len;
    cin >> len >> show;

    vector<vector<int>> pos(29);
    for (int i = 0; i < len; ++i)
    {
        pos[show[i] - 'a'].push_back(i + 1);
    }

    int numTest;
    cin >> numTest;

    for (int t = 0; t < numTest; t++)
    {
        vector<int> count(29);
        cin >> name;
        int nameLen = strlen(name);
        int maxLen = 0;
        for (int i = 0; i < nameLen; ++i)
        {
            maxLen = max(maxLen, pos[name[i] - 'a'][count[name[i] - 'a']]);
            count[name[i] - 'a']++;
        }
        cout << maxLen << endl;
    }

    return 0;
}

  						    							  	 	 				 	