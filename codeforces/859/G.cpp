// LUOGU_RID: 158447748
#include <bits/stdc++.h>
using i64 = long long;
constexpr i64 mod = 998224353;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

int main()
{
    int n, m;
    std::string s;
    std::cin >> n >> s;
    m = n;
    std::vector<int> a;
    std::vector<double> num(n);
    for(int i = 0; i < m; i++) 
    {
        num[i] = s[i] - '0';
    }
    for(int i = 2; i < m; i++)
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n /= i;
                a.push_back(i);
            }
        }
    a.push_back(m);
    for(auto t : a)
    {
        for(int i = 0; i < m / t; i++)
        {
            double tmp = 0;
            for(int j = i; j < m; j += m / t)
            {
                tmp += num[j];
            }
            tmp /= t;
            for(int j = i; j < m; j += m / t)
            {    
                num[j] -= tmp;
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        if(fabs(num[i]) >= 1e-9)
        {
            std::cout << "NO\n";
            return 0;
        }
    }
    std::cout << "YES\n";
}
