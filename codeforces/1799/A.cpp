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
    int t,n,m,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<int> V(n,-1);
        int idx{0};
        vector<int> listaM;
        for(int j=1;j<=m;j++)
        {
            cin>>x;
            if( find(listaM.begin(),listaM.end(),x) == listaM.end() )
            {
                listaM.push_back(x);
                if( idx<n )
                    V[idx]=j;
                idx++;
            }
        }

        for(auto it=V.rbegin();it!=V.rend();it++)
            cout<<*it<<' ';
            cout<<endl;
    }

    return 0;
}
