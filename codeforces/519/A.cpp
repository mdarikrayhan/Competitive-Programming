// LUOGU_RID: 159040088
// #include <bits/stdc++.h>
// using namespace std;
// /*
// 一个很大的问题，函数里面的cnt并不会影响外面的cnt，因为我们
// 讲过这个函数调用只是将值复制到函数里面，并不会影响原本的数值
// 这道题没有固定某个地方一定是白色或者黑色，所以只能一起处理
// 建议计数器放在外面使用
// */
// int cnt1 = 0;
// int cnt2 = 0;
// void vis(string s) // 改为int返回值
// {
//     for (int i = 0; i < 8; ++i)
//     {
//         if (s[i] == 'Q')
//         {
//             cnt1 += 9;
//         }
//         if (s[i] == 'q')
//         {
//             cnt2 += 9;
//         }
//         if (s[i] == 'R')
//         {
//             cnt1 += 5;
//         }
//         if (s[i] == 'r')
//         {
//             cnt2 += 5;
//         }
//         if (s[i] == 'B')
//         {
//             cnt1 += 3;
//         }
//         if (s[i] == 'b')
//         {
//             cnt2 += 3;
//         }
//         if (s[i] == 'N')
//         {
//             cnt1 += 3;
//         }
//         if (s[i] == 'n')
//         {
//             cnt2 += 3;
//         }
//         if (s[i] == 'P')
//         {
//             cnt1 += 1;
//         }
//         if (s[i] == 'p')
//         {
//             cnt2 += 1;
//         }
//     }
// }
// int main()
// {
//     string s1;
//     string s2;
//     string s3;
//     string s4;
//     string s5;
//     string s6;
//     string s7;
//     string s8;
//     cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8;

//     vis(s1);
//     vis(s2);
//     vis(s3);
//     vis(s4);
//     vis(s5);
//     vis(s6);
//     vis(s7);
//     vis(s8);
//     if (cnt1 > cnt2)
//     {
//         cout << "White";
//     }
//     else if (cnt1 < cnt2)
//     {
//         cout << "Black";
//     }
//     else
//     {
//         cout << "Draw";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
string s[8];       // 总共有八个字符串，直接用数组存储
map<char, int> op; // 存储对应字符的数字
void init()        // 预处理
{
    op['Q'] = op['q'] = 9;
    op['R'] = op['r'] = 5;
    op['B'] = op['b'] = 3;
    op['N'] = op['n'] = 3;
    op['P'] = op['p'] = 1;
    return;
}
int cnt1, cnt2;
void Count(string x) // 计数
{
    for (int j = 0; j < x.size(); ++j)
    {
        if (x[j] >= 'a' && x[j] <= 'z')
        {
            cnt2 += op[x[j]];
        }
        else
        {
            cnt1 += op[x[j]];
        }
    }
    return;
}
int main()
{
    init();
    for (int i = 0; i < 8; ++i)
    {
        cin >> s[i];
        Count(s[i]);
    }
    if (cnt1 > cnt2)
    {
        cout << "White";
    }
    else if (cnt1 < cnt2)
    {
        cout << "Black";
    }
    else
    {
        cout << "Draw";
    }
    return 0;
}