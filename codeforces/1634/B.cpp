#include<bits/stdc++.h>
using namespace std;
#define int long long

void testcase() 
{
    int n , x , y; cin >> n >> x >> y;

    int a = x , b = x + 3;

    for(int i = 0 ; i < n ; i++)
    {
        int k; cin >> k;
        a ^= k;
        b ^= k;
    }


    cout << ((a&1) == (y&1) ? "Alice\n" : "Bob\n");
}


int32_t main() 
{

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif

    int tc = 1;
    cin >> tc;
    while(tc--) testcase();

    return 0;
}
