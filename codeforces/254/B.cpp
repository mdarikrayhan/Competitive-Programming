#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int monthToDay[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int a[500] = {0}, ans = 0;
    int n;
    fin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        int m, d, p, t;
        fin >> m >> d >> p >> t;
        m--; 
        int totald = monthToDay[m] + d - 1; 
        
        for (int j = 0; j < t; ++j)
        {
            ans = max(ans, a[totald - j + 100] += p);
        }
    }
    
    fout << ans << endl;
    
    return 0;
}
