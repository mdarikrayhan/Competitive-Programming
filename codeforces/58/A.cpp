#include <bits/stdc++.h>
using namespace std;
int main()
{
    char ch, a[6]="hello";
    int i = 0;
    while (cin >> ch)
        if (a[i] == ch)
            i++;
    cout << (i == 5 ? "YES" : "NO");
}