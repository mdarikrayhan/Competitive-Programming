/*


###       ##           ######           ##      ##    ##         ##    ##
####      ##          ##    ##          ##     ##     ##         ##    ##
## ##     ##         ##      ##         ##   ##       ##         ##    ##
##  ##    ##        ############        ####          ##         ##    ##
##   ##   ##       ##          ##       ##   ##       ##         ##    ##
##    ##  ##      ##            ##      ##    ##      ##         ##    ##
##     #####     ##              ##     ##     ##     ##         ##    ##
##      ####    ##                ##    ##      ##    #############    ##############


*/

#include <bits/stdc++.h>
using namespace std;
#include <cstdio>
#define ll long long
#define CodePat ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define fi(a, b) for (int i = a; i < b; i++)
#define fie(a, b) for (int i = a; i <= b; i++)
#define fj(a, b) for (int j = a; j < b; j++)
#define fk(a, b) for (int k = a; k < b; k++)
#define fje(a, b) for (int j = a; j <= b; j++)
#define fke(a, b) for (int k = a; k <= b; k++)
#define vi vector<int>
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ssort(v) sort(v.begin(), v.end())
#define lsort(v) sort(v.begin(), v.end(), greater<int>())
#define get(n) \
    int n;     \
    cin >> n;
vector<ll> pairs[1001];
vector<bool> isprime(1000001, false);
const int N = 2e5 + 10;

// count no. of digits
int countDigits(int n)
{
    int cnt = (int)(log10(n) + 1);
    return cnt;
}

// reverse a number
int reverseNum(int n)
{
    int temp = n;
    int rev = 0;
    while (temp > 0)
    {
        int digit = temp % 10;
        rev = rev * 10 + digit;
        temp /= 10;
    }
    return rev;
}

// check if palindrome
int isPalindrome(int n)
{
    int temp = n;
    ll rev = 0;

    while (temp > 0)
    {
        int digit = temp % 10;
        rev = rev * 10 + digit;
        temp /= 10;
    }

    return n == (int)rev ? true : false;
}

// find GCD
int findGcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a == 0)
    {
        return b;
    }
    return a;
}

// check if Armstrong number
bool isArmstrong(int num)
{

    int k = (int)(log10(num) + 1);
    int sum = 0;
    int n = num;
    while (n > 0)
    {
        int ld = n % 10;
        sum += pow(ld, k);
        n = n / 10;
    }
    return sum == num ? true : false;
}

// all divisors
vector<int> findDivisors(int n)
{
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i != n / i)
            {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

// prefixSum
void prefixSum(int arr[], int n, int prefixSum[])
{
    prefixSum[0] = arr[0];

    fi(1, n)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

// check if prime
bool checkPrime(int n)
{

    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {

        if (n % i == 0)
        {
            cnt++;
            if (n / i != i)
            {
                cnt++;
            }
        }
    }

    if (cnt == 3)
        return true;
    else
        return false;
}

// sieve of eratosthene
void sieve()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (isprime[i] == false)
            for (int j = i * i; j <= 1000000; j += i)
                isprime[j] = 1;
    }
}

/*
❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌
❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌
*/
// use when file i/p & o/p is given

// void CodePat(istream &cin, ostream &cout)

void solve()
{
    CodePat;

    get(n);
    get(m);
    float mini = INT_MAX, a, b;
    float temp;
    while (n--)
    {
        a, b;
        cin >> a >> b;
        temp = (float)a / b;
        mini = min(temp, mini);
    }

    cout <<setprecision(8)<< m * mini << endl;
}

/*
❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌
❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌❌
*/
int main()
{
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    CodePat;

    int cp;
    // cin >> cp;
    cp = 1;
    while (cp--)
    {
        solve();
    }

    // use for file i/p o/p :::

    // CodePat(cin, cout);
    // cin.close();
    // cout.close();
    return 0;
}