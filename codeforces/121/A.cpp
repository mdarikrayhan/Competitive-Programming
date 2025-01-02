
#include<bits/stdc++.h>
using namespace std;
long long luckyNum[100001] = {0}, len = 1;
long long calc(long long pos)
{
    long long sum = 0;
    for(int i = 1;;i++)
    {
        if(luckyNum[i] >= pos) 
        {
            sum += luckyNum[i] * (pos - luckyNum[i - 1]);
            break;
        }
        sum += luckyNum[i] * (luckyNum[i] - luckyNum[i - 1]);
    }
    return sum;
}
int main()
{
    luckyNum[1] = 4, luckyNum[2] = 7;
    for (int i = 1, len = 2; luckyNum[i] * 10 + 4 <= (long long)(1e10); i++)
    {
        luckyNum[++len] = luckyNum[i] * 10 + 4;
        luckyNum[++len] = luckyNum[i] * 10 + 7;
    }
    long long l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1);
    return 0;
}