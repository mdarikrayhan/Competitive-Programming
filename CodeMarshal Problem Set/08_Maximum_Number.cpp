#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int NoOfTestCase = 1;
    cin >> NoOfTestCase;
    for (int testcaseno = 1; testcaseno <= NoOfTestCase; testcaseno++)
    {
        long long a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        cout << "Case " << testcaseno << ": " << a[2] << "\n";
    }
    return 0;
}