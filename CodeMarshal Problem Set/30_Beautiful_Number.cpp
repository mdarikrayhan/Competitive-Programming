#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
long long int m, n;
long long int ans = 0;
int fi(long long int a[], long long int bi, int x, int y)
{
    if (bi > n)
        return 0;
    if (x == m)
    {
        return 0;
    }
    fi(a, bi, x + 1, y);
    bi *= a[x];
    y++;
    if (y % 2)
    {
        ans += (n / bi);
    }
    else
    {
        ans -= (n / bi);
    }
    fi(a, bi, x + 1, y);
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> m;
        long long int a[m];
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        cin >> n;
        ans = 0;
        fi(a, 1, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
/*
A certain strange mathematician, Rasyak, considers a particular set of prime numbers 
beautiful. He also calls a composite number beautiful, if it is divisible by at least 
one prime number in his chosen set of beautiful primes. Given Rasyak’s set of M beautiful 
primes and an integer N, you have to find the number of beautiful numbers (both primes 
and composites) between 1 and N. For example, given a set of 2 beautiful primes, {2, 5}, 
there are 6 beautiful numbers between 1 and 10 (i.e. 2, 4, 5, 6, 8 and 10).

Input

The first line of the input gives the number of test cases, T (1 <= T <= 100). 
T test cases follow. Each will consist of one line containing a single integer M, 
followed by a line containing M space-separated prime numbers mi, followed by 
another line containing a single integer N. 

Output

For each test case, output one line containing a single integer X, where X is the number 
of beautiful numbers between 1 and N.

Input	         Output
3                

2               6
2 5
10

3                63
2 5 13
100

25               1759360857
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
2000000000
*/