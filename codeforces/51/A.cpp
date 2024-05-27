#include "bits/stdc++.h"
using namespace std;

string rot90(string s)
{
    char tmp;
    tmp = s[0];
    s[0] = s[1];
    s[1] = s[2];
    s[2] = s[3];
    s[3] = tmp;

    return s;
}

string rot180(string s)
{
    return rot90(rot90(s));
}

string rot270(string s)
{
    
    return rot180(rot90(s));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s1, s2, amulet, stars;
    vector<string> piles;
    vector<int> cnts;
    bool inserted;

    cin >> n;

    cin >> s1 >> s2;

    amulet = s1 + s2[1] + s2[0];

    piles.push_back(amulet);
    cnts.push_back(1);

    for (int i = 1; i < n; i ++)
    {
        cin >> stars >> s1 >> s2;
        amulet = s1 + s2[1] + s2[0];

        inserted = false;

        for (int j = 0; j < piles.size(); j ++)
        {
            if (amulet == piles[j] || rot90(amulet) == piles[j] || rot180(amulet) == piles[j] || rot270(amulet) == piles[j])
            {
                cnts[j] ++;
                inserted = true;
                break;
            }
        }

        if (!inserted)
        {
            piles.push_back(amulet);
            cnts.push_back(1);
        }

    }

    cout << piles.size() << "\n";

    return 0;
}