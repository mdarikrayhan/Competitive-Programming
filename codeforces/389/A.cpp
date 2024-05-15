#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int num[N];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}


int main()
{
    int n;
    int temp1 = 0;
    cin >> n;
    cin >> temp1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        temp1 = gcd(temp1, x);

    }

    cout << temp1 * n << endl;


}