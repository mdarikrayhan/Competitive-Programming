#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int sumofdigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
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
        long long n,temp;
        cin >> n;
        temp = n;
        int sum = sumofdigits(n);
        sum = sum / 2;
        long long ans = 0,step=1;
        while (sum > 0)
        {
            int digit = temp % 10;
            temp /= 10;
            if(digit>=sum){
                ans+=step*sum;
                sum=0;
            }
            else{
                ans+=(step*digit);
                sum-=digit;
            }
            step*=10;
        }
        cout << ans << " " << n - ans << nl;
    }
    return 0;
}