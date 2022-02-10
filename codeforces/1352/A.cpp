#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
void solve()
{
    int n;
    cin >> n;
    vector<int> number;
    vector<int>num;
    while (n)
    {
        number.push_back(n % 10);
        if(n%10!=0){
            num.push_back(n%10);
        }
        n = n / 10;
    }
    cout<<num.size()<<nl;
    for (int i = 0; i < number.size(); i++)
    {
        if (number[i] > 0)
        {
            cout << number[i];
            for (int j = 0; j < i; j++)
            {
                cout << 0;
            }
            cout << " ";
        }
    }
    cout << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}