#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 8;

int n;
int nums[maxn];
int nums_from_bottom[maxn];
int t[maxn];
int DONE = 0;

const int prm_maxn = 1000 * 1000;
vector<int> primes;
bool is_prime[prm_maxn + 10];
void seive()
{
    fill(is_prime, is_prime + prm_maxn + 2, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= prm_maxn; i++)
        if (is_prime[i])
            for (int j = i * i; j <= prm_maxn; j += i)
                is_prime[j] = false;

    for (int i = 2; i <= prm_maxn; i++)
        if (is_prime[i])
            primes.push_back(i);
}

int RESULT = 0;
int NW = 0;
int MX;

int DEBUG[maxn];

void rec(int ind = 0)
{
    if (ind == n)
    {
        if(DONE == n-1) NW--;
        if(NW == -691)
        {
            cout << "OH";
        }
        RESULT = min(NW, RESULT);
        if(DONE == n-1) NW++;
        return;
    }
    DEBUG[ind] = 0;
    rec(ind + 1);
    for (int i = ind + 1; i < n; i++)
    {
    DEBUG[ind] = i;
        if (nums_from_bottom[i] % nums[ind] == 0)
        {
            DONE++;
            nums_from_bottom[i] /= nums[ind];
            if(t[ind] == 0) NW--;
            NW -= t[ind];
            rec(ind + 1);
            nums_from_bottom[i] *= nums[ind];
            if(t[ind] == 0) NW++;
            NW += t[ind];
            DONE--;
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
        
    sort(nums,nums+n);
    for (int i = 0; i < n; i++)
        nums_from_bottom[i] = nums[i];
    RESULT = 1 + n;
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        for (auto k : primes)
        {
            if (k >= num)
                break;
            while (num % k == 0)
            {
                num /= k;
                t[i]++;
            }
        }

        if(num > 1 && num != nums[i]) t[i]++;

        RESULT += t[i];
    }
    NW = RESULT;
    rec();

    cout << RESULT;
}

signed main()
{

    /* Recording the starting clock tick.*/
    seive();
    solve();
}