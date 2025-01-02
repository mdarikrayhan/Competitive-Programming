// LUOGU_RID: 159790889
#include<iostream>
using namespace std;
int ic(int x, int y)
{
    if(x > y) swap(x,y);
    if(x == 0) return 0;
    return (y/x+ic(x, y%x))%2;
}
int calc(int x, int y)
{
    if(x > y) swap(x,y);
    return ic(x-1, y)^ic(x, y-1)^ic(x-1, y-1)^1^ic(x, y-x);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, ans = 0;
    cin >> n;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        ans ^= calc(a, b);
    }
    cout << (ans?"FIRST":"SECOND") << endl;
    return 0;
}