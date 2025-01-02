/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int k;
    cin>>k;
    vector <vector <int>> pal(n, vector <int>(n));
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            int l=i, r=j;
            int kol=0;
            while (l<r){
                if (s[l]!=s[r]) kol++;
                l++;
                r--;
            }
            pal[i][j]=kol;
        }
    }
    vector <vector <int>> dp(n+1, vector <int>(k+1, n+1));
    dp[0][0]=0;
    vector <vector <int>> pre(n+1, vector <int>(k+1, -1));
    for (int ko=1; ko<=k; ko++){
        for (int i=1; i<=n; i++){
            for (int j=i; j>=1; j--){
                if (dp[i][ko]>dp[j-1][ko-1]+pal[j-1][i-1]) {
                    dp[i][ko]=min(dp[i][ko], dp[j-1][ko-1]+pal[j-1][i-1]);
                    pre[i][ko]=j-1;
                }
            }
        }
    }
    int otv=n+1, miotv=0;
    for (int i=1; i<=k; i++) {
        if (otv>dp[n][i]) {
            otv=min(otv, dp[n][i]);
            miotv=i;
        }
    }
    int kol=miotv, pr=n;
    string s1;
    while (kol>0){
        int l=pr;
        pr=pre[pr][kol];
        int le=pr, ri=l-1;
        //cout<<le<<" "<<ri<<endl;
        while (le<ri){
            if (s[le]!=s[ri]) s[le]=s[ri];
            le++;
            ri--;
        }
        while (l>pr){
            s1=s[l-1]+s1;
            l--;
        }
        if (pr!=0){
            s1="+"+s1;
        }
        kol--;
    }
    cout<<otv<<"\n"<<s1;
    return 0;
}
