#include <bits/stdc++.h>
#define ll long long
#define lli long long int
#define ulli unsigned long long int
#define vi vector<int>
#define pii pair<int,int>
#define vlli vector<lli>
#define vpii vector<pii>
#define vvi vector<vector<int> > 
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(a)  (int)a.size()
#define ld  long double
#define ff  first
#define ss  second


using namespace std;

//ctrl + B to compile and run
//ctrl + Q to stop infinite loop
//Here is one interesting fact. There always exists a power of prime p in the range [x,p*x] for any positive integer x
//With any positive integer x, there is at least one square number in [x,2x]
//if getting precision error write the formula in different ways and try also make sure to perform all multiplications before your division
//if no output check out of bounds, array size,, division by zero, modulo with 0, division long long by int

template<typename T> istream& operator>>(istream &in, vector<T>& a) { for(auto &x:a) in >> x; return in; }
template<typename T> ostream& operator<<(ostream &out, vector<T>& a) { for(auto &x:a) out << x << " "; return out; }
template<typename T> void prt(T to_print){cout << to_print << '\n';return;}
template<typename T1,typename T2> ostream& operator<<(ostream &out,pair<T1,T2> &p){out << "{" << p.first << "," << p.second<<"} ";return out;}





void solve(){


    int n,m;cin >> n >> m;
    vector<vector<int> > v(n,vector<int>(m));
    int i1=0,j1=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
            if(v[i][j]>v[i1][j1]){
                i1=i;
                j1=j;
            }
        }
    }
    cout << (max(i1+1,n-i1)*max(j1+1,m-j1)) << '\n';


    











    


    



    //cout << "\n-------------------------\n";
    return;
    
}




int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);


    //precalc();
    

    int t;cin >> t;
    while(t--) 
        solve();
    
    

    return 0;
}