#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <functional>
#include <iomanip>
#include <numeric>
#include <queue>
#include <random>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=j;k++)
            {
                if( k==1 || j==k )
                    cout<<1<< " ";
                else
                    cout<<0<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
