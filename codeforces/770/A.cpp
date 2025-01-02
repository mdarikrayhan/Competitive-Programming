#include <bits/stdc++.h>
#define ll long long
#define yes cout << "yes" << endl
#define no cout << "no" << endl
using namespace std;
#define fast() ios_base::sync_with_stdio(false);
double  pi=3.1415926535897932384626433832795;
int is_prime(ll n)
{
    for(ll i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int sumOfDigits(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int checkPalindrome(string str)
{
    ll len = str.length();
    for (ll i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
            return false;
    }
    return true;
}
int main(){fast()
    int n, k;
    cin >> n >> k;
    while(n--){
        putchar('a' + n % k);
    }
    return 0;
}
