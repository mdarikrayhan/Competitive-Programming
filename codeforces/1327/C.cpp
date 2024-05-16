#include<bits/stdc++.h>
using namespace std;

void testcase() 
{
    int n , m , k; cin >> n >> m >> k;

    vector<int> v(k); for(auto &i : v) cin >> i;

    cout << n - 1 + m - 1 + n * (m - 1) + n - 1 << "\n";
    for(int i = 0 ; i < m - 1; i++) cout << "L";
    for(int i = 0 ; i < n - 1; i++) cout << "U";

    string s1(m - 1 , 'L') , s2(m - 1 , 'R');
    for(int i = 0 ; i < n ; i++)
    {
        if(i&1) cout << s1;
        else cout << s2;
        if(i != n - 1) cout << "D";
    }

    cout << "\n";
}


int main() 
{

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif

    int tc = 1;
    //cin >> tc;
    while(tc--) testcase();

    return 0;
}
