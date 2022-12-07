/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    string s1;
    unordered_set<string> s;
    for (int i = 0; i < a + b; i++)
    {
        cin >> s1;
        s.insert(s1);
    }
    if ((a + b - s.size()) % 2 == 1)
        a++;
    if (a > b)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
    return 0;
}