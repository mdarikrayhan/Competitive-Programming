#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int number, difference, targetrow, targetcoloum;
        cin >> number >> difference >> targetrow >> targetcoloum;
        targetrow--;
        targetcoloum--;
        int target = targetrow + targetcoloum;
        set<int> targets;
        targets.insert(target);
        int l = target-difference;
        while (l >= 0)
        {
            targets.insert(l);
            l -= difference;
        }
        l=target;
        while (l<2*number)
        {
           l+=difference;
              targets.insert(l);
        }
        for (int i = 0; i < number; i++)
        {
            for (int j = 0; j < number; j++)
            {
                if(targets.find(i+j)!=targets.end())
                {
                    cout<<'X';
                }
                else
                {
                    cout<<'.';
                }
            }
            cout<<nl;
        }
        
    }
    return 0;
}