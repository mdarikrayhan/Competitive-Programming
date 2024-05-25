// LUOGU_RID: 160202789
// LUOGU_RID: 160184235
#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __read(T &x)
        {
            char ch;
            T res = 0, f = 1;
            while (std::isdigit(ch = getchar()) == false)
            {
                f = (ch != '-');
            }
            do
            {
                res = res * 10 + (ch - '0');
            } while (std::isdigit(ch = getchar()) == true);
            x = res * (f ? 1 : -1);
        }
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __read(T &x)
        {
            std::cin >> x;
        }
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __write(T x)
        {
            if (x < 0)
            {
                std::putchar('-'), __write(-x);
                return;
            }
            if (x >= 10)
            {
                __write(x / 10);
            }
            std::putchar(x % 10 + '0');
        }
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __write(T x)
        {
            std::cout << x;
        }
        template <typename First, typename... Rest>
        void __write(First first, Rest... rest)
        {
            __write(first), std::putchar(' '), __write(rest...);
        }
    }  // namespace basic_IO
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        basic_IO::__read(first, rest...);
    }
    template <typename T>
    void readAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__read(*i);
        }
    }
    long long readi()
    {
        long long res;
        read(res);
        return res;
    }
    std::string reads()
    {
        std::string res;
        read(res);
        return res;
    }
    template <typename First, typename... Rest>
    void write(First first, Rest... rest)
    {
        basic_IO::__write(first, rest...), std::putchar('\n');
    }
    template <typename T>
    void writeAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__write(*i), std::putchar(' ');
        }
        std::putchar('\n');
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;

    constexpr int DELTA = 1e4;
    constexpr int MAXN  = 1e2 + 5;
    constexpr int MAXN2 = 3e4 + 5;

    int n;
    std::string s;

    int a[MAXN];

    int sum[2];

    int dp[MAXN][MAXN2];

    int main()
    {
        std::memset(dp, 0x3f, sizeof(dp));

        read(s);
        n = s.size();

        for (int i = 1; i <= n; i++)
        {
            sum[a[i] = s[i - 1] - '0']++;
        }

        dp[0][0 + DELTA] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                for (int k = -n * n / 4; k <= n * n / 4; k++)
                {
                    if (j - 1 < 0)
                    {
                        dp[j][k + DELTA] = dp[j][k + DELTA] + (a[i] != 0);
                    }
                    else
                    {
                        dp[j][k + DELTA] = std::min(dp[j][k + DELTA] + (a[i] != 0), dp[j - 1][k - (sum[0] - (i - j) - (i - j)) + DELTA] + (a[i] != 1));
                    }
                }
            }
        }

        write(dp[sum[1]][0 + DELTA] / 2);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}

/**
 * dp[i][j][k]: 前 i 个数，填了 j 个 1，贡献为 k 的花费
 * dp[i][j][k] <- dp[i - 1][j][k] 当前位填 0
 * dp[i][j][k] <- dp[i - 1][j - 1][k - (sum_0 - (i - j) - (i - j))] 当前位填 1
 */