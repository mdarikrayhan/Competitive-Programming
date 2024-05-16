#include <bits/stdc++.h>
using namespace std;

int main()
{
    int result = 0, max = 0;
    int n;
    cin >> n;
    int freq[n+1]={0};
    int input;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> input;
        if (freq[input] == 1)
        {
            result--;
        }
        else
        {
            freq[input]++;
            result++;
        }
        (result > max) ? max = result : max;
    }
    cout << max << endl;
}