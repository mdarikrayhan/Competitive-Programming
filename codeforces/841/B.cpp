/***************************************************/
/*            Author : Md. Arik Rayhan             */
/*        Github : github.com/mdarikrayhan         */
/***************************************************/
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, even = 0, odd = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k & 1)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    if (n == even)
    {
        cout << "Second" << '\n';
    }
    else
    {
        cout << "First" << '\n';
    }
    return 0;
}