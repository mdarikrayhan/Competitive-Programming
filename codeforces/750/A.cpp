#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n, k;
cin >> n >> k;
int time = 240 - k;
int count = 0;
for (int i = 1; i <= n; i++)
{
    if (time - 5 * i >= 0)
    {
        count++;
        time -= 5 * i;
    }
    else
    {
        break;
    }
}
cout << count << nl;
return 0;
}