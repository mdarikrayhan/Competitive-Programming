/* -----------------  إِنَّا لا نُضِيعُ أَجْرَ مَنْ أَحْسَنَ عَمَلا  ----------------- */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define ld long double
#define For1(n) for(int i=0; i<n; i++)
#define For2(n) for(int j=0; j<n; j++)
#define test int t; cin >> t; while(t--) solve();
#define sb << '\n'
#define pi 3.14159265358979323846
using namespace std;
//#pragma GCC optimize("Ofast,unroll-loops,O3")
//#pragma GCC target("avx2,tune=native")
/* **************************************************************** */
void solve() //SOLVE
{
    double n,t1,t2,k,qa,qb,sum1,sum2;bool b= true;
    cin >> n >> t1 >> t2 >> k;k/=100;
    vector<pair<double,int>>vs(n);
    For1(n){
        cin >> qa >> qb;
        sum1=qa*t1;sum1-=sum1*k;
        sum2=qb*t1;sum2-=sum2*k;
        if(sum1+qb*t2<sum2+qa*t2) swap(qa,qb);
        sum1=qa*t1;sum1-=sum1*k;sum2=qb*t2;sum1+=sum2;
        vs[i].second=i;vs[i].first=sum1;
    }
    sort(vs.rbegin(),vs.rend());
    while(b){
        b= false;
        For1(n-1){
            if(vs[i].first==vs[i+1].first && vs[i].second>vs[i+1].second){swap(vs[i],vs[i+1]);b= true;}
        }
    }
    For1(n){
        cout << vs[i].second+1 << ' ' << fixed << setprecision(2) << vs[i].first sb;
    }
}
/* **************************************************************** */
int main() //MAIN
{
    IOS
    //test
    solve();

    return 0;
}