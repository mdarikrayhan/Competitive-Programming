/*
               <3  "صلي علي النبي" 
*/
#include<bits/stdc++.h>
using namespace std;
void Start();
void Solve();

int main(void)//By: Ahmed Elshamy
{
    Start();
    Solve();
    return 0;
}

void Solve()
{
    int tt ; cin >> tt;
    while (tt--)
    {
        int n ; cin >>n;
        vector<int>v;
        int zero = 0;
        set<int>st;
        for(int i = 0 ; i < n ;++i)
        {
            int x ; cin >> x;
            if(x != 0)
            {
                st.insert(x);
                v.push_back(x);
            }
            else
                zero++;
        }

        if(zero > 0)
            cout << n - zero  << '\n';
        else 
            cout << n + (st.size() == v.size()) << '\n';


    }
    

}

void Start()
{
    #ifndef ONLINE_JUDGE 
    freopen("Read.tex","r",stdin) , freopen("Write.tex","w",stdout); 
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL) , cout.tie(NULL);
}
