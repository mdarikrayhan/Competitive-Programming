#include <bits/stdc++.h>
using namespace std;
int main() 
{ 

    map<char, int> omar;
    omar['('] = 1;omar[')'] = -1;
    omar['['] = 2;omar[']'] = -2;
    omar['{'] = 3;omar['}'] = -3;
    omar['<'] = 4;omar['>'] = -4;
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    vector<int> st;
    for (auto c : s) 
    {
        if (omar[c] > 0) 
        {
            st.push_back(omar[c]);
        }
        else if (st.empty()) 
        {
            cout << "Impossible" << endl;
            return 0;
        }
        else 
        {
            if (st.back() != -omar[c]) 
            {
                ans += 1;
            }
            st.pop_back();
        }
    }
    if (!st.empty()) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}