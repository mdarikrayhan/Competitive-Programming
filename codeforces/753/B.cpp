// LUOGU_RID: 159351589
#include<bits/stdc++.h>

using namespace std;

bool use[10];

int main()
{
    int a[10];
    memset(use, 1, sizeof(use));
    int cnt = 0;
    for(int i = 0; i <= 9; i++)//0~9全部询问
    {
        if(i != 0)
            cout << i * 1000 + i * 100 + i * 10 + i << endl;
        else
            cout << "0000" << endl;//这里要输出字符串
        int A, b;
        cin >> A >> b;
        if(A || b) //记录出现过的数字
            a[++cnt] = i, use[i] = 0;
    }
    int c, d;
    for(int i = 1; i <= cnt; i++)//暴力全排列
        for(int j = 1; j <= cnt; j++)
            for(int k = 1; k <= cnt; k++)
                for(int l = 1; l <= cnt; l++)
                {
                    if(i == j || i == k || i == l || j == k || j == l || k == l)
                        continue;
                    cout << a[i] << a[j] << a[k] << a[l] << endl;
                    int c, d;
                    cin >> c >> d;
                    if(c == 4)
                        return 0;
                }
    system("pause");
    return 0;
}